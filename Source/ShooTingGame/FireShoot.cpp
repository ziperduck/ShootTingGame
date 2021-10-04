// Fill out your copyright notice in the Description page of Project Settings.


#include "FireShoot.h"
#include "Action.h"
#include "ActionInstance.h"
#include <Engine/Classes/Components/SphereComponent.h>
#include <Engine/Classes/Particles/ParticleSystem.h>
#include <Engine/Classes/Particles/ParticleSystemComponent.h>

// Sets default values
AFireShoot::AFireShoot() {
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	mb_initialize = false;

	SetActorTickEnabled(false);
	SetActorEnableCollision(false);
}

void AFireShoot::FuselageInitialize(const float Speed)
{
	if (!mb_initialize)
	{
		Tags.Add(TEXT("Fuselage"));
		Tags.Add(TEXT("Weapon"));

		mb_initialize = true;

		UE_LOG(LogTemp, Log, TEXT("Initialize"));

		SetActorTickEnabled(true);
		SetActorEnableCollision(true);

		m_speed = Speed;

		m_attack_power = 1;
	}
}

//Getter
const EFuselageKind AFireShoot::GetKind() const
{
	return m_kind;
}

const float AFireShoot::GetSpeed() const
{
	return m_speed;
}

const int32 AFireShoot::GetAttackPower() const
{
	return m_attack_power;
}

const TArray<EVariousAction> AFireShoot::GetNextActions()
{
	return m_next_actions;
}

void AFireShoot::SetNextActions_Implementation(const TArray<EVariousAction>& NextActions)
{
	m_next_actions = NextActions;
}

void AFireShoot::SetSpeed(const float Speed)
{
	m_speed = Speed;

}

void AFireShoot::SetAttackPower(const int32 Power)
{
	m_attack_power = Power;
}

//Setter

void AFireShoot::AttackFuselage(const int32 HP)
{
	UE_LOG(LogTemp, Log, TEXT("AFireShoot Death"));
	m_actions.Enqueue(EVariousAction::DEATH);
}

void AFireShoot::MoveLocation(const FVector& MoveLocation) {

	SetActorLocation(GetActorLocation() + MoveLocation);
}

//Event
void AFireShoot::EventUpdate()
{
	while (!m_actions.IsEmpty())
	{
		IAction* Action = ChangeAction(*m_actions.Peek());
		UE_LOG(LogTemp, Log, TEXT("Change Action had Action"));
		checkf(Action != nullptr, TEXT("AFireShoot EventUpdate in Action is nullptr"));
		Action->Execute(this);
		m_actions.Pop();
	}

	for (const auto& i : m_next_actions)
	{
		m_actions.Enqueue(i);
	}
}

void AFireShoot::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("Overlap AFireShoot"));
	m_actions.Enqueue(EVariousAction::ATTACK);
}

void AFireShoot::Tick(float Delta)
{
	Super::Tick(Delta);
	EventUpdate();
}