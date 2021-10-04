// Fill out your copyright notice in the Description page of Project Settings.


#include "BoomDragon.h"
#include "ActionInstance.h"

// Sets default values
ABoomDragon::ABoomDragon()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	mb_initialize = false;

	SetActorTickEnabled(false);
	SetActorEnableCollision(false);

}

void ABoomDragon::FuselageInitialize(const float Speed, const int32 MaxHP, const float BoomDelay)
{
	if (!mb_initialize)
	{
		mb_initialize = true;

		UE_LOG(LogTemp, Log, TEXT("Initialize"));

		Tags.Add(TEXT("Fuselage"));
		Tags.Add(TEXT("Airframe"));

		SetActorTickEnabled(true);
		SetActorEnableCollision(true);

		m_speed = Speed;

		m_max_HP = MaxHP;
		m_current_HP = MaxHP;

		m_boom_delay = BoomDelay;
	}
}

// Called when the game starts or when spawned
void ABoomDragon::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABoomDragon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	EventUpdate();
}

void ABoomDragon::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("ABoomDragon Overlap"));

	IFuselage* Fuselage = Cast<IFuselage>(Actor);
	checkf(Fuselage != nullptr, TEXT("ABoomDragon overlap actor is not Fuselage"));

	if (!GetWorldTimerManager().IsTimerActive(m_boom_timer_handle)&& Fuselage->GetKind() == EFuselageKind::PLAYER_FUSELAGE)
	{
		GetWorldTimerManager().SetTimer(m_boom_timer_handle
			, [&] {	m_actions.Enqueue(EVariousAction::BOOM_ATTACK);
			m_actions.Enqueue(EVariousAction::DEATH); }, m_boom_delay, false);
	}
	m_actions.Enqueue(EVariousAction::ATTACK);

	return;
}

const EFuselageKind ABoomDragon::GetKind() const
{
	return m_kind;
}

const float ABoomDragon::GetSpeed() const
{
	return m_speed;
}

const int32 ABoomDragon::GetAttackPower() const
{
	return 1;
}

const TArray<EVariousAction> ABoomDragon::GetNextActions()
{
	return m_next_actions;
}

void ABoomDragon::SetNextActions_Implementation(const TArray<EVariousAction>& NextActions)
{
	m_next_actions = NextActions;
}

void ABoomDragon::SetSpeed(const float Speed)
{
	m_speed = Speed;
}

void ABoomDragon::SetAttackPower(const int32 Power)
{
	m_attack_power = Power;
}

void ABoomDragon::AttackFuselage(const int32 HP)
{
	m_current_HP += HP;
}

void ABoomDragon::MoveLocation(const FVector& MoveLocation)
{
	SetActorLocation(GetActorLocation() + MoveLocation);
}

void ABoomDragon::EventUpdate()
{
	while (!m_actions.IsEmpty())
	{
		IAction* Action = ChangeAction(*m_actions.Peek());
		Action->Execute(this);
		m_actions.Pop();
	}
	if (m_current_HP < 1)
	{
		ChangeAction(EVariousAction::DEATH)->Execute(this);
	}
	else if(!GetWorldTimerManager().IsTimerActive(m_boom_timer_handle))
	{
		for (const auto& i : m_next_actions)
		{
			m_actions.Enqueue(i);
		}
	}
}
