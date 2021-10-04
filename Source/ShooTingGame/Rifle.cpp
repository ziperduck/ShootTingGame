// Fill out your copyright notice in the Description page of Project Settings.


#include "Rifle.h"
#include "Action.h"
#include "ActionInstance.h"
#include <Engine/Classes/Components/SphereComponent.h>

// Sets default values
ARifle::ARifle() {
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	mb_initialize = false;

	SetActorTickEnabled(false);
	SetActorEnableCollision(false);
}

void ARifle::FuselageInitialize(const int32 AttackPower, const float Speed)
{
	if (!mb_initialize)
	{
		mb_initialize = true;


		UE_LOG(LogTemp, Log, TEXT("ARifle Initialize"));

		m_attack_power = AttackPower;
		m_speed = Speed;

		Tags.Add(TEXT("Fuselage"));
		Tags.Add(TEXT("Weapon"));

		SetActorTickEnabled(true);
		SetActorEnableCollision(true);
	}
}

//Getter
const EFuselageKind ARifle::GetKind() const
{
	return m_kind;
}

const float ARifle::GetSpeed() const
{
	return m_speed;
}

const int32 ARifle::GetAttackPower() const
{
	return m_attack_power;
}

const TArray<EVariousAction> ARifle::GetNextActions()
{
	return m_next_actions;
}

void ARifle::SetNextActions_Implementation(const TArray<EVariousAction>& NextActions)
{
	m_next_actions = NextActions;
}

void ARifle::SetSpeed(const float Speed)
{
	m_speed = Speed;
}

void ARifle::SetAttackPower(const int32 Power)
{
	m_attack_power = Power;
}


 //Setter
void ARifle::AttackFuselage(const int32 HP)
{
	m_actions.Enqueue(EVariousAction::DEATH);
}

void ARifle::MoveLocation(const FVector& MoveLocation) {

	SetActorLocation(GetActorLocation() + MoveLocation);
}


//Event
void ARifle::EventUpdate()
{


	while (m_actions.IsEmpty())
	{
		IAction* Action = ChangeAction(*m_actions.Peek());
		UE_LOG(LogTemp, Log, TEXT("Change Action had Action"));
		checkf(Action != nullptr, TEXT("ARifle EventUpdate in Action is nullptr"));
		Action->Execute(this);
		m_actions.Pop();
	}

	for (const auto& i : m_next_actions)
	{
		m_actions.Enqueue(i);
	}
}

void ARifle::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("Overlap ARifle"));
	m_actions.Enqueue(EVariousAction::ATTACK);
	return;
}

void ARifle::Tick(float Delta)
{
	Super::Tick(Delta);
	EventUpdate();
}