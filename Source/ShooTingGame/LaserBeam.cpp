// Fill out your copyright notice in the Description page of Project Settings.


#include "LaserBeam.h"
#include "Action.h"
#include "ActionInstance.h"
#include <Engine/Classes/Components/BoxComponent.h>
// Sets default values
ALaserBeam::ALaserBeam() {
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	mb_initialize = false;

	SetActorTickEnabled(false);
	SetActorEnableCollision(false);
}

void ALaserBeam::BeginPlay()
{
	Super::BeginPlay();
}

void ALaserBeam::WeaponInitalize(const int32 Power)
{
	if (!mb_initialize)
	{
		Tags.Add(TEXT("Fuselage"));
		Tags.Add(TEXT("Weapon"));

		m_attack_power = Power;

		SetActorTickInterval(1.0f);
		SetActorTickEnabled(true);
		SetActorEnableCollision(true);

		m_actions.Enqueue(EVariousAction::ATTACHPLAYER_MOVE);
	}
}

//Getter
const EFuselageKind ALaserBeam::GetKind() const
{
	return m_kind;
}

const float ALaserBeam::GetSpeed() const
{
	return 0;
}

const int32 ALaserBeam::GetAttackPower() const
{
	return m_attack_power;
}

const TArray<EVariousAction> ALaserBeam::GetNextActions()
{
	return TArray<EVariousAction>();
}

void ALaserBeam::SetNextActions_Implementation(const TArray<EVariousAction>& NextActions)
{
}

void ALaserBeam::SetSpeed(const float Speed)
{
}

void ALaserBeam::SetAttackPower(const int32 Power)
{
	m_attack_power = Power;
}


//Setter

void ALaserBeam::AttackFuselage(const int32 HP)
{
}

void ALaserBeam::MoveLocation(const FVector& MoveLocation) 
{
	SetActorLocation(GetActorLocation() + MoveLocation);
}

//Event
void ALaserBeam::EventUpdate()
{

	m_actions.Enqueue(EVariousAction::ATTACK);

	while (!m_actions.IsEmpty())
	{
		IAction* Action = ChangeAction(*m_actions.Peek());
		UE_LOG(LogTemp, Log, TEXT("ALaserBeam EventUpdate"));
		checkf(Action != nullptr, TEXT("ALaserBeam EventUpdate in Action is nullptr"));
		Action->Execute(this);
		m_actions.Pop();
	}
}

void ALaserBeam::Tick(float Delta)
{
	Super::Tick(Delta);
	EventUpdate();

}