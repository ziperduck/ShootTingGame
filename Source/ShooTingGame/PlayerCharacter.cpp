// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "Movement.h"
#include "Rifle.h"
#include <Engine/Classes/Camera/CameraComponent.h>
#include <Engine/Classes/Components/SphereComponent.h>

// Sets default values
APlayerCharacter::APlayerCharacter() {

	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Log, TEXT("AplayerContorller Constructor"));

	USphereComponent* Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetNotifyRigidBodyCollision(true);
	Sphere->SetCollisionProfileName(TEXT("OverlapAll"));
	Sphere->InitSphereRadius(20.0f);
	RootComponent = Sphere;

	m_characterScene = CreateAbstractDefaultSubobject<USceneComponent>(TEXT("Scene"));
	m_characterScene->SetupAttachment(RootComponent);

	m_kind = EFuselageKind::PlayerFuselage;
	m_weapon = EFuselageKind::RifleFuselage;
	m_speed = 1.0f;
	m_max_HP = 1;
	m_current_HP = m_max_HP;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AplayerContorller BeginPlay"));


}


const EFuselageKind APlayerCharacter::GetKind() const
{
	return m_kind;
}

const float APlayerCharacter::GetSpeed() const
{
	return m_speed;
}

const FVector APlayerCharacter::GetLocation() const
{
	return K2_GetActorLocation();
}

const FRotator APlayerCharacter::GetRotation() const
{
	return K2_GetActorRotation();
};

UWorld* APlayerCharacter::GetFuselageWorld() const
{
	return GetWorld();
}

const int32 APlayerCharacter::GetStruckDamage() const
{
	return m_struck_damage;
}

const int32 APlayerCharacter::GetAttackPower() const
{
	return m_attack_power;
}

void APlayerCharacter::SetCurrentHP(const int8 HP)
{
	m_current_HP += HP;
}

void APlayerCharacter::MoveLocation(const FVector& MoveLocation) {
	/*
	* setLocatino은 충돌처리를 못하고 랜더링 값을 가지고있기때문에
	* USceneComponenet를 이용해 충돌처리와 이동을 같이 처리하게 만들었다.
	*/
	FHitResult Hit(1.f);

	UE_LOG(LogTemp, Log, TEXT("MoveLocation"));
	RootComponent->MoveComponent(MoveLocation, K2_GetActorRotation(), true, &Hit);
	if (Hit.IsValidBlockingHit())
	{
		UE_LOG(LogTemp, Log, TEXT("is Hit Actor"));
	}
}

//Event
void APlayerCharacter::EventUpdate()
{
	while (m_actions.size() > 0)
	{
		IAction* Action = ChangeAction(m_actions.front());
		Action->Execute(this);
		m_actions.pop();
	}
	if (m_current_HP < 1)
	{
		UE_LOG(LogTemp, Log, TEXT("You Death"));
		PrimaryActorTick.bCanEverTick = false;
	}
}

void APlayerCharacter::Tick(float Delta)
{
	Super::Tick(Delta);

	EventUpdate();
}

void APlayerCharacter::MoveX(float Direction)
{
	const int EastOrWeast = Direction;
	constexpr int East = 1;
	constexpr int West = -1;
	switch (EastOrWeast)
	{
	case East:
		m_actions.push(EVariousAction::EastMove);
		break;
	case West:
		m_actions.push(EVariousAction::WestMove);
		break;
	default:
		break;
	}
}

void APlayerCharacter::MoveY(float Direction)
{
	const int NorthOrSouth = Direction;
	constexpr int North = -1;
	constexpr int South = 1;
	switch (NorthOrSouth)
	{
	case North:
		m_actions.push(EVariousAction::NorthMove);
		break;
	case South:
		m_actions.push(EVariousAction::SouthMove);
		break;
	default:
		break;
	}
}

void APlayerCharacter::MoveA(float Direction)
{
	m_actions.push(EVariousAction::Shooting);
}

void APlayerCharacter::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("Overlap Player Character"));
	if (Actor == nullptr)
		return;
	IFuselage* OverlapTarget = Cast<IFuselage>(Actor);
	checkf(OverlapTarget != nullptr, TEXT("Overlap Target is nullptr"));

	switch (OverlapTarget->GetKind())
	{
	case EFuselageKind::PlayerFuselage:
		UE_LOG(LogTemp, Log, TEXT("Player Overlap"));
		break;
	default:
		m_actions.push(EVariousAction::Struck);
		break;
	}
}


void APlayerCharacter::ShootingGun()
{
	switch (m_weapon)
	{
	case EFuselageKind::RifleFuselage:
		GetWorld()->SpawnActor<ARifle>(
			GetActorLocation() + FVector{ 60.0f,0.0f,0.0f }, FRotator::ZeroRotator);
		break;
	default:
		break;
	}
}
