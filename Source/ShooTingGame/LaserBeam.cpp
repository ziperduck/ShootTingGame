// Fill out your copyright notice in the Description page of Project Settings.


#include "LaserBeam.h"
#include "Action.h"
#include "ActionInstance.h"
#include <Engine/Classes/Components/BoxComponent.h>
// Sets default values
ALaserBeam::ALaserBeam() {
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	UBoxComponent* BoxComponenet = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponenet->SetupAttachment(RootComponent);
	BoxComponenet->SetNotifyRigidBodyCollision(true);
	BoxComponenet->SetCollisionProfileName(TEXT("OverlapAll"));
	BoxComponenet->SetWorldScale3D(FVector{20.0f,0.5f,0.5f});
	BoxComponenet->SetRelativeLocation(FVector{ 700.0f,0.0f,0.0f });

	mb_initialize = false;
	SetActorTickEnabled(false);
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

		m_actions.push(EVariousAction::ATTACHPLAYER_MOVE);
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

	m_actions.push(EVariousAction::ATTACK);

	while (m_actions.size() > 0)
	{
		IAction* Action = ChangeAction(m_actions.front());
		UE_LOG(LogTemp, Log, TEXT("ALaserBeam EventUpdate"));
		checkf(Action != nullptr, TEXT("ALaserBeam EventUpdate in Action is nullptr"));
		Action->Execute(this);
		m_actions.pop();
	}
}

void ALaserBeam::Tick(float Delta)
{
	Super::Tick(Delta);
	EventUpdate();

}