// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyDragon.h"
#include "Action.h"
#include "ActionInstance.h"
#include <Engine/Classes/Components/AudioComponent.h>


// Sets default values
AEnemyDragon::AEnemyDragon() 
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	static ConstructorHelpers::FObjectFinder<USoundWave>
		DeathAssetSound(TEXT("/Game/Audio/DragonDeathSound.DragonDeathSound"));
	checkf(DeathAssetSound.Succeeded(), TEXT("BreakAssetSound is no found"));
	m_death_sound_asset = DeathAssetSound.Object;

	m_death_sound = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio Component"));
	m_death_sound->SetupAttachment(RootComponent);
	
	

	mb_initialize = false;

	SetActorTickEnabled(false);
	SetActorEnableCollision(false);

}

void AEnemyDragon::FuselageInitialize(
	const float Speed, const int32 MaxHP, const EVariousWeapon Weapon, const float ShootingDelay)
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

		m_weapon_kind = Weapon;
		m_shooting_delay = ShootingDelay;

	}
}

void AEnemyDragon::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp,Log,TEXT("Spawn EnemyDragon"));

}

//Getter
const EFuselageKind AEnemyDragon::GetKind() const
{
	return m_kind;
}

const float AEnemyDragon::GetSpeed() const
{
	return m_speed;
}


const int32 AEnemyDragon::GetAttackPower() const
{
	return 1;
}

//Setter
void AEnemyDragon::AttackFuselage(const int32 HP)
{
	m_current_HP += HP;
	UE_LOG(LogTemp, Log, TEXT("AEnemyDragon Attack %d Now HP = %d"), HP, m_current_HP);
}

void AEnemyDragon::MoveLocation(const FVector& MoveLocation) {
	
	SetActorLocation(GetActorLocation() + MoveLocation);
}

//Event
void AEnemyDragon::EventUpdate()
{

	while (!m_actions.IsEmpty())
	{
		IAction* Action = ChangeAction(*m_actions.Peek());
		checkf(Action != nullptr, TEXT("Player animation No have Interface"));
		Action->Execute(this);
		m_actions.Pop();
	}
	if (m_current_HP < 1)
	{
		UE_LOG(LogTemp, Log, TEXT("Enemy Dragon Death"));
		m_actions.Enqueue(EVariousAction::DEATH);

		m_death_sound->SetSound(m_death_sound_asset);
		m_death_sound->Play();
		
	}
	else
	{
		for (const auto& i : m_next_actions)
		{
			m_actions.Enqueue(i);
		}
	}

	if (!GetWorldTimerManager().IsTimerActive(m_shooting_timer))
	{
		m_actions.Enqueue(EVariousAction::SHOOTING);
		GetWorldTimerManager().SetTimer(m_shooting_timer, m_shooting_delay, false);
	}
}

const int32 AEnemyDragon::GetWeaponLevel() const
{
	return 1;
}

const float AEnemyDragon::GetWeaponLifespan() const
{
	return 10.0f;
}


const EVariousWeapon AEnemyDragon::GetWeaponKind() const
{
	return m_weapon_kind;
}

const TArray<EVariousAction> AEnemyDragon::GetNextActions()
{
	return m_next_actions;
}

void AEnemyDragon::SetNextActions_Implementation(const TArray<EVariousAction>& NextActions)
{
	m_next_actions = NextActions;
}

void AEnemyDragon::SetSpeed(const float Speed)
{
	m_speed = Speed;
}

void AEnemyDragon::SetAttackPower(const int32 Power)
{
	m_attack_power = Power;
}

void AEnemyDragon::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("Overlap AEnemyDragon"));
	m_actions.Enqueue(EVariousAction::ATTACK);
	return;
}

//타임머 만들고 드레곤에 붙이자
void AEnemyDragon::Tick(float Delta)
{
	Super::Tick(Delta);

	EventUpdate();
}
