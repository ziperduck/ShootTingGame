// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponKit.h"
#include "Action.h"
#include "ActionInstance.h"
#include "GameInformation.h"
#include <Engine/Classes/Components/SphereComponent.h>

// Sets default values
AWeaponKit::AWeaponKit()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	SetActorTickEnabled(false);
	SetActorEnableCollision(false);

	mb_initialize = false;
}

void AWeaponKit::WeaponKitInitalize(const float Spped)
{
	if (!mb_initialize)
	{
		mb_initialize = true;

		Tags.Add(TEXT("Fuselage"));
		Tags.Add(TEXT("Item"));

		SetActorTickEnabled(true);
		SetActorEnableCollision(true);

		m_change_weapon = EVariousWeapon::RIFLE_WEAPON;

		m_speed = Spped;
	}
}
// Called when the game starts or when spawned
void AWeaponKit::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AWeaponKit::BeginPlay"));
}

void AWeaponKit::ChangeWeaponEvent()
{
	switch (m_change_weapon)
	{
	case EVariousWeapon::RIFLE_WEAPON:
		m_change_weapon = EVariousWeapon::LASERBEAM_WEAPON;
		break;
	case EVariousWeapon::LASERBEAM_WEAPON:
		m_change_weapon = EVariousWeapon::RIFLE_WEAPON;
		break;
	default:
		checkNoEntry();
		break;
	}
}

// Called every frame
void AWeaponKit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Log, TEXT("AWeaponKit::Tick"));
	EventUpdate();
}

void AWeaponKit::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("AWeaponKit Overlap"));

	IFuselage* Fuselage = Cast<IFuselage>(Actor);
	checkf(Fuselage != nullptr, TEXT("AWeaponKit overlap actor is not Fuselage"));

	if (Fuselage->GetKind() == EFuselageKind::PLAYER_FUSELAGE)
	{
		m_actions.Enqueue(EVariousAction::PLAYER_WEAPON_CHANGE);
		m_actions.Enqueue(EVariousAction::DEATH);
	}
}

const EFuselageKind AWeaponKit::GetKind() const
{
	return m_kind;
}

const float AWeaponKit::GetSpeed() const
{
	return m_speed;
}

const int32 AWeaponKit::GetAttackPower() const
{
	return 0;
}

const TArray<EVariousAction> AWeaponKit::GetNextActions()
{
	return m_next_actions;
}

const EVariousWeapon AWeaponKit::GetChangeWeapon() const
{
	return m_change_weapon;
}

void AWeaponKit::SetNextActions_Implementation(const TArray<EVariousAction>& NextActions)
{
	m_next_actions = NextActions;
}

void AWeaponKit::SetSpeed(const float Speed)
{
	m_speed = Speed;
}

void AWeaponKit::SetAttackPower(const int32 Power)
{
}

void AWeaponKit::AttackFuselage(const int32 HP)
{

}

void AWeaponKit::MoveLocation(const FVector& MoveLocation)
{
	SetActorLocation(GetActorLocation() + MoveLocation);
}

void AWeaponKit::EventUpdate()
{
	while (!m_actions.IsEmpty())
	{
		IAction* Action = ChangeAction(*m_actions.Peek());
		Action->Execute(this);
		m_actions.Pop();
	}
	for (const auto& i : m_next_actions)
	{
		m_actions.Enqueue(i);
	}

}

