// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "Action.h"
#include "ActionInstance.h"
#include <Engine/Classes/Camera/CameraComponent.h>
#include <Engine/Classes/Components/SphereComponent.h>

// Sets default values
APlayerCharacter::APlayerCharacter() {

	UE_LOG(LogTemp, Log, TEXT("AplayerContorller Constructor"));

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

	mb_press = false;
	m_available_shooting = true;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AplayerContorller BeginPlay"));


}

void APlayerCharacter::Initialize_Implementation(
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
		switch (m_weapon.m_weapon)
		{
		case EVariousWeapon::RIFLE_WEAPON:
			UE_LOG(LogTemp, Log, TEXT("RIFLE_WEAPON"));
			m_weapon.m_lifespan = 5;
			break;
		case EVariousWeapon::LASERBEAM_WEAPON:
			UE_LOG(LogTemp, Log, TEXT("RIFLE_WEAPON"));
			m_weapon.m_lifespan = 0.;
			break;
		default:
			break;
		}

		m_press_time = 0;
	}
}

//Getter
const EFuselageKind APlayerCharacter::GetKind() const
{
	return m_kind;
}

const float APlayerCharacter::GetSpeed() const
{
	return m_speed;
}

const int32 APlayerCharacter::GetAttackPower() const
{
	return 1;
}

const int32 APlayerCharacter::GetMaxHP() const
{
	return m_max_HP;
}

void APlayerCharacter::UpgradeWeapon()
{
	switch (m_weapon.m_weapon)
	{
	case EVariousWeapon::RIFLE_WEAPON:
		++m_weapon.m_weapon_level;
		break;
	case EVariousWeapon::LASERBEAM_WEAPON:
		++m_weapon.m_weapon_level;
		break;
	default:
		UE_LOG(LogTemp, Log, TEXT("is not player weapon"));
		break;
	}
}

//Setter
void APlayerCharacter::AttackFuselage(const int32 HP)
{
	m_current_HP += HP;
	UE_LOG(LogTemp, Log, TEXT("Player Attack %d Now HP %d "), HP, m_current_HP);
}

void APlayerCharacter::MoveLocation(const FVector& MoveLocation) {
	
	SetActorLocation(GetActorLocation() + MoveLocation);
}

//Event
void APlayerCharacter::EventUpdate()
{
	if (m_current_HP < 1)
	{
		UE_LOG(LogTemp, Log, TEXT("You Death"));
		PrimaryActorTick.bCanEverTick = false;
	}
	while (m_actions.size() > 0)
	{
		IAction* Action = ChangeAction(m_actions.front());
		Action->Execute(this);
		m_actions.pop();
	}

	if (mb_press)
	{
		switch (m_weapon.m_weapon)
		{
		case EVariousWeapon::RIFLE_WEAPON:
			if (m_available_shooting)
			{
				m_available_shooting = false;
				m_actions.push(EVariousAction::SHOOTING);
				GetWorldTimerManager().SetTimer(
					m_shooting_timer, [&] {m_available_shooting = true; }, m_weapon.m_shooting_delay, false);
			}
			break;
		case EVariousWeapon::LASERBEAM_WEAPON:
			if (m_available_shooting)
			{
				++m_press_time;
				UE_LOG(LogTemp, Log, TEXT("APlayerCharacter Count %d"), m_press_time);
			}
			break;
		default:
			break;
		}
	}
}

void APlayerCharacter::Tick(float Delta)
{
	Super::Tick(Delta);

	EventUpdate();

}

void APlayerCharacter::MoveX(float Direction)
{
	const int EastOrWeast = Direction;
	constexpr int East = 1;
	constexpr int West = -1;
	switch (EastOrWeast)
	{
	case East:
		m_actions.push(EVariousAction::EAST_MOVE);
		break;
	case West:
		m_actions.push(EVariousAction::WEST_MOVE);
		break;
	default:
		break;
	}
}

void APlayerCharacter::MoveY(float Direction)
{
	const int NorthOrSouth = Direction;
	constexpr int North = 1;
	constexpr int South = -1;
	switch (NorthOrSouth)
	{
	case North:
		m_actions.push(EVariousAction::NORTH_MOVE);
		break;
	case South:
		m_actions.push(EVariousAction::SOUTH_MOVE);
		break;
	default:
		break;
	}
}
/*
* 
*/
void APlayerCharacter::PressAttack(float Direction)
{
	UE_LOG(LogTemp, Log, TEXT("APlayerCharacter Press"));
	mb_press = true;
}


void APlayerCharacter::ReleaseAttack(float Direction)
{

	UE_LOG(LogTemp, Log, TEXT("APlayerCharacter Release"));
	if (m_weapon.m_weapon == EVariousWeapon::LASERBEAM_WEAPON && m_available_shooting)
	{
		m_available_shooting = false;
		m_press_time /= 120;
		m_press_time += 1;
		if (m_press_time > 5)
		{
			m_press_time = 5;
		}
		m_weapon.m_lifespan = m_press_time;
		UE_LOG(LogTemp, Log, TEXT("Release time%d"), m_press_time);
		m_actions.push(EVariousAction::SHOOTING);
		GetWorldTimerManager().SetTimer(
			m_shooting_timer, [&] {m_available_shooting = true; }, m_weapon.m_shooting_delay + m_weapon.m_lifespan, false);
	}
	mb_press = false;
	m_press_time = 0;
}

const FWeaponStruct APlayerCharacter::GetWeapon()const
{
	return m_weapon;
}

void APlayerCharacter::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("Overlap Player Character"));
	m_actions.push(EVariousAction::ATTACK);
}
