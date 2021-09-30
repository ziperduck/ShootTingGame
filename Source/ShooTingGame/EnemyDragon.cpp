// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyDragon.h"
#include "Action.h"
#include "ActionInstance.h"

// Sets default values
AEnemyDragon::AEnemyDragon() 
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;


	USphereComponent* Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetNotifyRigidBodyCollision(true);
	Sphere->SetCollisionProfileName(TEXT("OverlapAll"));
	Sphere->InitSphereRadius(40.0f);
	RootComponent = Sphere;

	mb_initialize = false;

	SetActorTickEnabled(false);
	SetActorEnableCollision(false);

}

void AEnemyDragon::Initialize_Implementation(
	const float Speed, const int32 MaxHP, FWeaponStruct Weapon)
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

		m_weapon = Weapon;
		m_weapon.m_weapon = EVariousWeapon::FIRESHOOT_WEAPON;
		m_weapon.m_lifespan = 5.0f;
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
		ChangeAction(EVariousAction::DEATH)->Execute(this);
	}

	if (!GetWorldTimerManager().IsTimerActive(m_shooting_timer))
	{
		m_actions.Enqueue(EVariousAction::SHOOTING);
		GetWorldTimerManager().SetTimer(m_shooting_timer, m_weapon.m_shooting_delay, false);
	}
}

const FWeaponStruct AEnemyDragon::GetWeapon() const
{
	return m_weapon;
}

const int32 AEnemyDragon::GetMaxHP() const
{
	return m_max_HP;
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
