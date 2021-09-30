// Fill out your copyright notice in the Description page of Project Settings.


#include "HealPack.h"
#include "Action.h"
#include "ActionInstance.h"
#include <Engine/Classes/Components/SphereComponent.h>

// Sets default values
AHealPack::AHealPack()
{
	PrimaryActorTick.bCanEverTick = true;

	USphereComponent* Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetNotifyRigidBodyCollision(true);
	Sphere->SetCollisionProfileName(TEXT("OverlapAll"));
	Sphere->InitSphereRadius(40.0f);
	RootComponent = Sphere;

	m_speed = 2.0f;
	m_heal_power = 1.0f;
}

void AHealPack::HealPackInitalize(const float Spped, const int32 HealPower)
{
	Tags.Add(TEXT("Fuselage"));
	Tags.Add(TEXT("Item"));

	m_heal_power = HealPower;
	m_speed = Spped;
}

// Called when the game starts or when spawned
void AHealPack::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AHealPack::BeginPlay"));
}

// Called every frame
void AHealPack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Log, TEXT("AHealPack::Tick"));
	EventUpdate();
}

void AHealPack::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("AHealPack Overlap"));

	IFuselage* Fuselage = Cast<IFuselage>(Actor);
	checkf(Fuselage != nullptr, TEXT("AHealPack overlap actor is not Fuselage"));

	if (Fuselage->GetKind() == EFuselageKind::PLAYER_FUSELAGE)
	{
		m_actions.Enqueue(EVariousAction::HEALING);
		m_actions.Enqueue(EVariousAction::DEATH);
	}
}

const EFuselageKind AHealPack::GetKind() const
{
	return m_kind;
}

const float AHealPack::GetSpeed() const
{
	return m_speed;
}

const int32 AHealPack::GetAttackPower() const
{
	return 1;
}

void AHealPack::AttackFuselage(const int32 HP)
{
	m_current_HP += HP;
}

void AHealPack::MoveLocation(const FVector& MoveLocation)
{
	SetActorLocation(GetActorLocation() + MoveLocation);
}

void AHealPack::EventUpdate()
{
	while (!m_actions.IsEmpty())
	{
		IAction* Action = ChangeAction(*m_actions.Peek());
		Action->Execute(this);
		m_actions.Pop();
	}

	m_actions.Enqueue(EVariousAction::SOUTH_MOVE);
}

