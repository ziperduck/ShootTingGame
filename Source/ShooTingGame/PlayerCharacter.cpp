// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "Movement.h"
#include <Engine/Classes/Camera/CameraComponent.h>

// Sets default values
APlayerCharacter::APlayerCharacter(){

	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Log, TEXT("AplayerContorller Constructor"));


	m_characterScene = CreateAbstractDefaultSubobject<USceneComponent>(TEXT("Scene"));
	m_characterScene->SetupAttachment(RootComponent);

	m_kind = EFuselageKind::RifleFuselage;
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

UClass* APlayerCharacter::GetComponentClass() const
{
	return GetClass();
}

void APlayerCharacter::MoveLocation(const FVector& MoveLocation) {
	/*
	* setLocatino은 충돌처리를 못하고 랜더링 값을 가지고있기때문에
	* USceneComponenet를 이용해 충돌처리와 이동을 같이 처리하게 만들었다.
	*/
	FHitResult Hit(1.f);

	UE_LOG(LogTemp, Log, TEXT("MoveLocation"));
	m_characterScene->MoveComponent(MoveLocation, K2_GetActorRotation(), true, &Hit);
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

void APlayerCharacter::SetWeapon(TSubclassOf<class AActor> Weapon)
{

	UE_LOG(LogTemp, Log, TEXT("SetWeapon playercharacter Name : %s"), *GetHumanReadableName());
	if (Weapon == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("SetWeapon weapon is nullptr"));
		return;
	}
	checkf(Weapon != nullptr, TEXT("Weapon is nullptr"));
	checkf(Weapon->ImplementsInterface(UFuselage::StaticClass())
		, TEXT("Weapon is not Derived"));

	UE_LOG(LogTemp, Log, TEXT("SetWeapon Weapon Name : %s"), Weapon->StaticConfigName());
	m_weapon = Weapon;
	UE_LOG(LogTemp, Log, TEXT("SetWeapon m_weapon Name : %s"), m_weapon->StaticConfigName());
}


void APlayerCharacter::ShootingGun()
{
	if (m_weapon == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("ShootingGun no have m_weapon"));
		UE_LOG(LogTemp, Log, TEXT("ShootingGun playercharacter Name : %s"), *GetHumanReadableName());
		return;
	}
	UE_LOG(LogTemp, Log, TEXT("ShootingGun m_weapon Name : %s"), m_weapon->StaticConfigName());
	FTransform SpawnTransform{ K2_GetActorRotation() ,FVector{0.0f,0.0f,50.0f},FVector::OneVector };
	GetWorld()->SpawnActor<AActor>(m_weapon, SpawnTransform);


}
