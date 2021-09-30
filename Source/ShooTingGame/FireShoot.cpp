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

//Setter

void AFireShoot::WeaponInitalize(const FWeaponStruct& Weapon)
{
	m_attack_power = 1;
	m_speed = Weapon.m_speed;
}

void AFireShoot::AttackFuselage(const int32 HP)
{
	UE_LOG(LogTemp, Log, TEXT("AFireShoot Death"));
	m_actions.push(EVariousAction::DEATH);
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

	m_actions.push(EVariousAction::SOUTH_MOVE);
}

void AFireShoot::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("Overlap AFireShoot"));
	m_actions.push(EVariousAction::ATTACK);
}

void AFireShoot::Tick(float Delta)
{
	Super::Tick(Delta);
	EventUpdate();
}