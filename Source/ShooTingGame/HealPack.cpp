// Fill out your copyright notice in the Description page of Project Settings.


#include "HealPack.h"
#include "Action.h"
#include "ActionInstance.h"
#include <Engine/Classes/Components/SphereComponent.h>

// Sets default values
AHealPack::AHealPack()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	mb_initialize = false;

	SetActorTickEnabled(false);
	SetActorEnableCollision(false);
}

void AHealPack::HealPackInitalize(const float Speed, const int32 HealPower)
{
	if (!mb_initialize)
	{
		Tags.Add(TEXT("Fuselage"));
		Tags.Add(TEXT("Item"));

		m_attack_power = HealPower;
		m_speed = Speed;

		SetActorTickEnabled(true);
		SetActorEnableCollision(true);
	}
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
	return m_attack_power;
}

const TArray<EVariousAction> AHealPack::GetNextActions()
{
	return m_next_actions;
}

void AHealPack::SetNextActions_Implementation(const TArray<EVariousAction>& NextActions)
{
	m_next_actions = NextActions;
}

void AHealPack::SetSpeed(const float Speed)
{
	m_speed = Speed;
}

void AHealPack::SetAttackPower(const int32 Power)
{
	m_attack_power = Power;
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

	for (const auto& i : m_next_actions)
	{
		m_actions.Enqueue(i);
	}
}

