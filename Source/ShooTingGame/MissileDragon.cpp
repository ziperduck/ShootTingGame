// Fill out your copyright notice in the Description page of Project Settings.


#include "MissileDragon.h"

#include "Action.h"
#include "ActionInstance.h"
#include <Engine/Classes/Components/SphereComponent.h>

// Sets default values
AMissileDragon::AMissileDragon()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	mb_initialize = false;

	SetActorTickEnabled(false);
	SetActorEnableCollision(false);

}

void AMissileDragon::FuselageInitialize(const float Speed, const int32 MaxHP)
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
void AMissileDragon::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMissileDragon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	EventUpdate();
}

void AMissileDragon::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("Meteoric Overlap"));
	m_actions.Enqueue(EVariousAction::ATTACK);
	return;


}

const EFuselageKind AMissileDragon::GetKind() const
{
	return m_kind;
}

const float AMissileDragon::GetSpeed() const
{
	return m_speed;
}

const int32 AMissileDragon::GetAttackPower() const
{
	return 1;
}

const TArray<EVariousAction> AMissileDragon::GetNextActions()
{
	return m_next_actions;
}

void AMissileDragon::SetNextActions_Implementation(const TArray<EVariousAction>& NextActions)
{
	m_next_actions = NextActions;
}

void AMissileDragon::SetSpeed(const float Speed)
{
	m_speed = Speed;
}

void AMissileDragon::SetAttackPower(const int32 Power)
{
	m_attack_power = Power;
}

void AMissileDragon::AttackFuselage(const int32 HP)
{
	m_current_HP += HP;
}

void AMissileDragon::MoveLocation(const FVector& MoveLocation)
{
	SetActorLocation(GetActorLocation() + MoveLocation);
}

void AMissileDragon::EventUpdate()
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
		ChangeAction(EVariousAction::DEATH)->Execute(this);
	}
	else
	{
		for (const auto& i : m_next_actions)
		{
			m_actions.Enqueue(i);
		}
	}
}


