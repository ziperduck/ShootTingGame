// Fill out your copyright notice in the Description page of Project Settings.


#include "FireShoot.h"
#include "Action.h"
#include "ActionInstance.h"
#include <Engine/Classes/Components/SphereComponent.h>

// Sets default values
AFireShoot::AFireShoot() {
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Meshes/Projectile.Projectile"));
	UStaticMeshComponent* WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	if (MeshAsset.Succeeded() && MeshAsset.Object != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Mesh Aseet %s"), *MeshAsset.GetReferencerName());
		WeaponMesh->SetupAttachment(RootComponent);
		WeaponMesh->SetStaticMesh(MeshAsset.Object);
	
		WeaponMesh->SetNotifyRigidBodyCollision(true);
		WeaponMesh->SetCollisionProfileName(TEXT("OverlapAll"));
	}

	m_speed = 4.0f;
	m_damage = 3;
	m_max_HP = 1;
	m_current_HP = m_max_HP;
	m_attack_power = 1;

}

//Getter
const EFuselageKind AFireShoot::GetKind() const
{
	return m_kind;
}

const float AFireShoot::GetSpeed() const
{
	return m_speed;
}

const int32 AFireShoot::GetAttackPower() const
{
	return m_attack_power;
}

const int32 AFireShoot::GetMaxHP() const
{
	return m_max_HP;
}



 //Setter

void AFireShoot::AddCurrentHP(const int32 HP)
{
	m_current_HP += HP;
}

void AFireShoot::MoveLocation(const FVector& MoveLocation) {

	SetActorLocation(GetActorLocation() + MoveLocation);
}

//Event
void AFireShoot::EventUpdate()
{
	while (m_actions.size() > 0)
	{
		IAction* Action = ChangeAction(m_actions.front());
		UE_LOG(LogTemp, Log, TEXT("Change Action had Action"));
		checkf(Action != nullptr, TEXT("AFireShoot EventUpdate in Action is nullptr"));
		Action->Execute(this);
		m_actions.pop();
	}

	//플레이어가 쏘는 경우 남쪽으로 적은 북쪽으로 쏜다.
	switch (GetKind())
	{
	case EFuselageKind::RIFLE_WEAPON:
		m_actions.push(EVariousAction::NORTH_MOVE);
		break;
	case EFuselageKind::FIRESHOOT_WEAPON:
		m_actions.push(EVariousAction::SOUTH_MOVE);
		break;
	default:
		break;
	}
}

void AFireShoot::NotifyActorBeginOverlap(AActor* Actor)
{
	m_actions.push(EVariousAction::ATTACK);
	return;
	UE_LOG(LogTemp, Log, TEXT("Overlap AFireShoot"));
	if (Actor == nullptr)
		return;
	IFuselage* OverlapTarget = Cast<IFuselage>(Actor);
	checkf(OverlapTarget != nullptr, TEXT("Overlap Target is nullptr"));

	if (OverlapTarget->GetKind() == EFuselageKind::PLAYER_FUSELAGE)
	{
		UE_LOG(LogTemp, Log, TEXT("FireShoot Collision Player"));
		m_actions.push(EVariousAction::DEATH);
	}

}

void AFireShoot::Tick(float Delta)
{
	Super::Tick(Delta);
	EventUpdate();
}