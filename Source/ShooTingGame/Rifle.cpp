// Fill out your copyright notice in the Description page of Project Settings.


#include "Rifle.h"
#include "Action.h"
#include "ActionInstance.h"
#include <Engine/Classes/Components/SphereComponent.h>

// Sets default values
ARifle::ARifle() {
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

}

//Getter
const EFuselageKind ARifle::GetKind() const
{
	return m_kind;
}

const float ARifle::GetSpeed() const
{
	return m_speed;
}

const int32 ARifle::GetAttackPower() const
{
	return m_attack_power;
}


 //Setter
void ARifle::AttackFuselage(const int32 HP)
{
	m_actions.push(EVariousAction::DEATH);
}

void ARifle::MoveLocation(const FVector& MoveLocation) {

	SetActorLocation(GetActorLocation() + MoveLocation);
}

void ARifle::WeaponInitalize(const FWeaponStruct& Weapon)
{

	Tags.Add(TEXT("Fuselage"));
	Tags.Add(TEXT("Airframe"));

	m_attack_power = Weapon.m_attack_power;
	m_speed = Weapon.m_speed;
}


//Event
void ARifle::EventUpdate()
{


	while (m_actions.size() > 0)
	{
		IAction* Action = ChangeAction(m_actions.front());
		UE_LOG(LogTemp, Log, TEXT("Change Action had Action"));
		checkf(Action != nullptr, TEXT("ARifle EventUpdate in Action is nullptr"));
		Action->Execute(this);
		m_actions.pop();
	}
	m_actions.push(EVariousAction::NORTH_MOVE);

}

void ARifle::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("Overlap ARifle"));
	m_actions.push(EVariousAction::ATTACK);
	return;
}

void ARifle::Tick(float Delta)
{
	Super::Tick(Delta);
	EventUpdate();
}