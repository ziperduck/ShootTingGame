// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "Action.h"
#include "ActionInstance.h"
#include "GameInformation.h"
#include <Engine/Classes/Camera/CameraComponent.h>
#include <Engine/Classes/Components/SphereComponent.h>
#include <Engine/Classes/Components/AudioComponent.h>

// Sets default values
APlayerCharacter::APlayerCharacter() {

	UE_LOG(LogTemp, Log, TEXT("AplayerContorller Constructor"));

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	static ConstructorHelpers::FObjectFinder<USoundWave>
		RifleAssetSound(TEXT("/Game/Audio/RifleShootingSound.RifleShootingSound"));
	checkf(RifleAssetSound.Succeeded(), TEXT("RifleAssetSound is nullptr"));
	RifleSound = RifleAssetSound.Object;

	static ConstructorHelpers::FObjectFinder<USoundWave>
		LaserGatherAssetSound(TEXT("/Game/Audio/GatherLaserSound.GatherLaserSound"));
	checkf(LaserGatherAssetSound.Succeeded(), TEXT("LaserGatherAssetSound is nullptr"));
	LaserGatherSound = LaserGatherAssetSound.Object;

	m_weapon_shoot_audio = CreateDefaultSubobject<UAudioComponent>(TEXT("Weapon Audio"));
	m_weapon_shoot_audio->SetupAttachment(RootComponent);

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

void APlayerCharacter::FuselageInitialize(
	const float Speed, const int32 MaxHP, const EVariousWeapon Weapon, const float ShootingDelay)
{
	if (!mb_initialize)
	{
		Tags.Add(TEXT("Fuselage"));
		Tags.Add(TEXT("Airframe"));

		mb_initialize = true;

		UE_LOG(LogTemp, Log, TEXT("Initialize %s"), *GetName());

		SetActorTickEnabled(true);
		SetActorEnableCollision(true);

		m_speed = Speed;
		m_max_HP = MaxHP;
		m_current_HP = MaxHP;
		
		m_weapon_kind = Weapon;


		switch (m_weapon_kind)
		{
		case EVariousWeapon::RIFLE_WEAPON:
		{
			m_weapon_lifespan = 5.0f;

			checkf(RifleSound != nullptr, TEXT("Laser Weapon assets not find"));

			m_weapon_shoot_audio->SetSound(RifleSound);
			break;
		}
		case EVariousWeapon::LASERBEAM_WEAPON:
		{
			m_weapon_lifespan = 0.0f;
			checkf(LaserGatherSound != nullptr, TEXT("Laser Weapon assets not find"));

			m_weapon_shoot_audio->SetSound(LaserGatherSound);
			break;
		}
		default:
			checkf(false, TEXT("weapon is no player weapon"));
			break;
		}
		m_shooting_delay = ShootingDelay;

		m_weapon_level = 1;

		m_press_time = 0;

		m_special_boom_number = 3;

		m_score = 10;
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

const int32 APlayerCharacter::GetCurrentHP() const
{
	return m_current_HP;
}

const int32 APlayerCharacter::GetSpecialBoomNumber() const
{
	return m_special_boom_number;
}

const int32 APlayerCharacter::GetScore() const
{
	return m_score;
}

void APlayerCharacter::SetSpeed(const float Speed)
{
	m_speed = Speed;
}

void APlayerCharacter::SetAttackPower(const int32 Power)
{
	m_attack_power = Power;
}

void APlayerCharacter::WeaponChange(const EVariousWeapon ChangeWeapon)
{
	if (ChangeWeapon != m_weapon_kind)
	{
		checkf(EVariousWeapon::FIRESHOOT_WEAPON != ChangeWeapon,TEXT("change Weapon is fireshoot"));
		m_weapon_kind = ChangeWeapon;
		m_weapon_level = 1;
		switch (m_weapon_kind)
		{
		case EVariousWeapon::RIFLE_WEAPON:
		{
			m_weapon_lifespan = 5.0f;

			checkf(RifleSound != nullptr, TEXT("Laser Weapon assets not find"));

			m_weapon_shoot_audio->SetSound(RifleSound);
			break;
		}
		case EVariousWeapon::LASERBEAM_WEAPON:
		{
			m_weapon_lifespan = 0.0f;
			checkf(LaserGatherSound != nullptr, TEXT("Laser Weapon assets not find"));

			m_weapon_shoot_audio->SetSound(LaserGatherSound);
			break;
		}
		default:
			checkf(false, TEXT("weapon is no player weapon"));
			break;
		}
	}
	else
	{
		++m_weapon_level;
		if (m_weapon_level > 3)
			m_weapon_level = 3;
	}
}

void APlayerCharacter::PressSpecialBoom()
{
	if (m_special_boom_number > 0)
	{
		m_actions.push(EVariousAction::SPECIAL_BOOM);
		--m_special_boom_number;
	}
}

//Setter
void APlayerCharacter::AttackFuselage(const int32 HP)
{
	if (HP >= 0)
	{
		UE_LOG(LogTemp, Log, TEXT("HP HEAL"));
		m_current_HP += HP;
	}
	else if (!GetWorldTimerManager().IsTimerActive(m_invincibility_timer))
	{
		UE_LOG(LogTemp, Log, TEXT("HP HI"));
		m_current_HP += HP;
		GetWorldTimerManager().SetTimer(m_invincibility_timer, []() {
			UE_LOG(LogTemp, Log, TEXT("You not Invincible HP"));}, 3.0f, false);
	} 

	UE_LOG(LogTemp, Log, TEXT("Player Attack %d Now HP %d "), HP, m_current_HP);

	if (m_current_HP < 1)
	{
		UE_LOG(LogTemp, Log, TEXT("current Hp is 0"));

		SetActorTickEnabled(false);
		SetActorEnableCollision(false);

		UnregisterAllComponents();

	}
}

void APlayerCharacter::MoveLocation(const FVector& MoveLocation) {
	
	SetActorLocation(GetActorLocation() + MoveLocation);
}

const int32 APlayerCharacter::GetWeaponLevel() const
{
	return m_weapon_level;
}

const float APlayerCharacter::GetWeaponLifespan() const
{
	return m_weapon_lifespan;
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
		switch (m_weapon_kind)
		{
		case EVariousWeapon::RIFLE_WEAPON:
			if (m_available_shooting)
			{
				m_weapon_shoot_audio->Play();
				m_available_shooting = false;
				m_actions.push(EVariousAction::SHOOTING);
				GetWorldTimerManager().SetTimer(
					m_shooting_timer, [&] {m_available_shooting = true; }, m_shooting_delay, false);
			}
			break;
		case EVariousWeapon::LASERBEAM_WEAPON:
			if (m_available_shooting)
			{
				++m_press_time;
				UE_LOG(LogTemp, Log, TEXT("APlayerCharacter Count %d"), m_press_time);

				if (!m_weapon_shoot_audio->IsPlaying())
				{
					m_weapon_shoot_audio->Play();
				}
			}
			break;
		default:
			break;
		}
	}
	UE_LOG(LogTemp, Log, TEXT("Player Position (%f,%f)"),GetActorLocation().X, GetActorLocation().Y);
}

void APlayerCharacter::Tick(float Delta)
{
	Super::Tick(Delta);

	EventUpdate();

}

void APlayerCharacter::EastWest(float Direction)
{
	const int EastOrWeast = Direction;
	constexpr int East = 1;
	constexpr int West = -1;
	
	GameInformation* Interface = GameInformation::GetInstance();

	switch (EastOrWeast)
	{
	case East:
		if (Interface->GetMapWidthMaxLocation() > GetActorLocation().Y + m_speed)
		{
			m_actions.push(EVariousAction::EAST_MOVE);
		}
		break;
	case West:
		if (Interface->GetMapWidthMinLocation() < GetActorLocation().Y - m_speed)
		{
			m_actions.push(EVariousAction::WEST_MOVE);
		}
		break;
	default:
		break;
	}
}

void APlayerCharacter::NorthSouth(float Direction)
{
	const int NorthOrSouth = Direction;
	constexpr int North = 1;
	constexpr int South = -1;

	GameInformation* Interface = GameInformation::GetInstance();
	switch (NorthOrSouth)
	{
	case North:
		if (Interface->GetMapHeightMaxLocation() > GetActorLocation().X + m_speed)
		{
		m_actions.push(EVariousAction::NORTH_MOVE);
		}
		break;
	case South:
		if (Interface->GetMapHeightMinLocation() < GetActorLocation().X - m_speed)
		{
		m_actions.push(EVariousAction::SOUTH_MOVE);
		}
		break;
	default:
		break;
	}
}
/*
* 
*/
void APlayerCharacter::PressAttack()
{
	UE_LOG(LogTemp, Log, TEXT("APlayerCharacter Press"));
	mb_press = true;
}


void APlayerCharacter::ReleaseAttack()
{

	UE_LOG(LogTemp, Log, TEXT("APlayerCharacter Release"));
	if (m_weapon_kind == EVariousWeapon::LASERBEAM_WEAPON && m_available_shooting)
	{
		m_weapon_shoot_audio->Stop();

		m_available_shooting = false;
		m_press_time /= 120;
		m_press_time += 1;
		if (m_press_time > 5)
		{
			m_press_time = 5;
		}
		m_weapon_lifespan = m_press_time;
		UE_LOG(LogTemp, Log, TEXT("Release time%d"), m_press_time);
		m_actions.push(EVariousAction::SHOOTING);
		GetWorldTimerManager().SetTimer(
			m_shooting_timer, [&] {m_available_shooting = true; }, m_shooting_delay + m_weapon_lifespan, false);

	}
	mb_press = false;
	m_press_time = 0;
}


const EVariousWeapon APlayerCharacter::GetWeaponKind() const
{
	return m_weapon_kind;
}

const TArray<EVariousAction> APlayerCharacter::GetNextActions()
{
	return TArray<EVariousAction>();
}

void APlayerCharacter::SetScore(const int32 Score)
{
	m_score += Score;
}

void APlayerCharacter::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("Overlap Player Character"));
	m_actions.push(EVariousAction::ATTACK);
}
