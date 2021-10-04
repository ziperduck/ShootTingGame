// Fill out your copyright notice in the Description page of Project Settings.


#include "MeteoricStone.h"
#include "Action.h"
#include "ActionInstance.h"
#include <Engine/Classes/Components/BoxComponent.h>

// Sets default values
AMeteoricStone::AMeteoricStone()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	mb_initialize = false;

	SetActorTickEnabled(false);
	SetActorEnableCollision(false);

}

void AMeteoricStone::FuselageInitialize(const float Speed, const int32 MaxHP)
{
	if (!mb_initialize)
	{
		Tags.Add(TEXT("Fuselage"));
		Tags.Add(TEXT("Airframe"));

		mb_initialize = true;

		UE_LOG(LogTemp, Log, TEXT("Initialize"));

		SetActorTickEnabled(true);
		SetActorEnableCollision(true);

		m_speed = Speed;
		m_max_HP = MaxHP;
		m_current_HP = MaxHP;
	}
}

// Called when the game starts or when spawned
void AMeteoricStone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMeteoricStone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	EventUpdate();
}

void AMeteoricStone::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("Meteoric Overlap"));
	m_actions.Enqueue(EVariousAction::ATTACK);
	return;
}

const EFuselageKind AMeteoricStone::GetKind() const
{
	return m_kind;
}

const float AMeteoricStone::GetSpeed() const
{
	return m_speed;
}

const int32 AMeteoricStone::GetAttackPower() const
{
	return 1;
}

const TArray<EVariousAction> AMeteoricStone::GetNextActions()
{
	return m_next_actions;
}

void AMeteoricStone::SetNextActions_Implementation(const TArray<EVariousAction>& NextActions)
{
	m_next_actions = NextActions;
}

void AMeteoricStone::SetSpeed(const float Speed)
{
	m_speed = Speed;
}

void AMeteoricStone::SetAttackPower(const int32 Power)
{
	m_attack_power = Power;
}

void AMeteoricStone::AttackFuselage(const int32 HP)
{
	m_current_HP += HP;
}

void AMeteoricStone::MoveLocation(const FVector& MoveLocation)
{
	SetActorLocation(GetActorLocation() + MoveLocation);
}

void AMeteoricStone::EventUpdate()
{
	while (!m_actions.IsEmpty())
	{
		IAction* Action = ChangeAction(*m_actions.Peek());
		Action->Execute(this);
		m_actions.Pop();
	}
	if (m_current_HP < 1)
	{
		//분해되는 건 그냥 운석을 두개 생성하자
		m_actions.Enqueue(EVariousAction::FUSELAGE_DIVIDE);
		m_actions.Enqueue(EVariousAction::DEATH);
	}
	else
	{
		for (const auto& i : m_next_actions)
		{
			m_actions.Enqueue(i);
		}
	}
}

