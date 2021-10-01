// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponKit.h"
#include "Action.h"
#include "ActionInstance.h"
#include <Engine/Classes/Components/SphereComponent.h>

// Sets default values
AWeaponKit::AWeaponKit()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	USphereComponent* Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetNotifyRigidBodyCollision(true);
	Sphere->SetCollisionProfileName(TEXT("OverlapAll"));
	Sphere->InitSphereRadius(40.0f);
	RootComponent = Sphere;

	m_speed = 2.0f;

	SetActorTickEnabled(false);
	SetActorEnableCollision(false);

	mb_initialize = false;
}

void AWeaponKit::WeaponKitInitalize(const float Spped)
{
	if (!mb_initialize)
	{
		mb_initialize = true;

		Tags.Add(TEXT("Fuselage"));
		Tags.Add(TEXT("Item"));

		SetActorTickEnabled(true);
		SetActorEnableCollision(true);

		m_speed = Spped;
	}
}
// Called when the game starts or when spawned
void AWeaponKit::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AWeaponKit::BeginPlay"));
}

// Called every frame
void AWeaponKit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Log, TEXT("AWeaponKit::Tick"));
	EventUpdate();
}

void AWeaponKit::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("AWeaponKit Overlap"));

	IFuselage* Fuselage = Cast<IFuselage>(Actor);
	checkf(Fuselage != nullptr, TEXT("AWeaponKit overlap actor is not Fuselage"));

	if (Fuselage->GetKind() == EFuselageKind::PLAYER_FUSELAGE)
	{
		m_actions.Enqueue(EVariousAction::WEAPON_UPGRADE);
		m_actions.Enqueue(EVariousAction::DEATH);
	}
}

const EFuselageKind AWeaponKit::GetKind() const
{
	return m_kind;
}

const float AWeaponKit::GetSpeed() const
{
	return m_speed;
}

const int32 AWeaponKit::GetAttackPower() const
{
	return 0;
}

void AWeaponKit::AttackFuselage(const int32 HP)
{

}

void AWeaponKit::MoveLocation(const FVector& MoveLocation)
{
	SetActorLocation(GetActorLocation() + MoveLocation);
}

void AWeaponKit::EventUpdate()
{
	while (!m_actions.IsEmpty())
	{
		IAction* Action = ChangeAction(*m_actions.Peek());
		Action->Execute(this);
		m_actions.Pop();
	}

	m_actions.Enqueue(EVariousAction::SOUTH_MOVE);

}
