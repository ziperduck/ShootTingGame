// Fill out your copyright notice in the Description page of Project Settings.


#include "LaserBeam.h"
#include "Action.h"
#include "ActionInstance.h"
#include <Engine/Classes/Components/SphereComponent.h>

// Sets default values
ALaserBeam::ALaserBeam() {
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Meshes/Projectile.Projectile"));
	UStaticMeshComponent* WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	if (MeshAsset.Succeeded() && MeshAsset.Object != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Mesh Aseet %s"), *MeshAsset.GetReferencerName());
		WeaponMesh->SetupAttachment(RootComponent);
		WeaponMesh->SetStaticMesh(MeshAsset.Object);
		FTransform transform{ FRotator::ZeroRotator,FVector{ 100.0f,0.0f,0.0f } ,FVector{ 50.0f,1.0f,1.0f } };
		WeaponMesh->SetRelativeTransform(transform);

		WeaponMesh->SetNotifyRigidBodyCollision(true);
		WeaponMesh->SetCollisionProfileName(TEXT("OverlapAll"));
	}

	m_speed = 0.0f;
	m_max_HP = 100;
	m_current_HP = m_max_HP;
	m_attack_power = 1;
	m_attack_term = 60;

}

//Getter
const EFuselageKind ALaserBeam::GetKind() const
{
	return m_kind;
}

const float ALaserBeam::GetSpeed() const
{
	return m_speed;
}

const int32 ALaserBeam::GetAttackPower() const
{
	return m_attack_power;
}

const int32 ALaserBeam::GetMaxHP() const
{
	return m_max_HP;
}



//Setter

void ALaserBeam::AddCurrentHP(const int32 HP)
{
	m_current_HP += HP;
}

void ALaserBeam::MoveLocation(const FVector& MoveLocation) {

	SetActorLocation(GetActorLocation() + MoveLocation);
}

//Event
void ALaserBeam::EventUpdate()
{
	while (m_actions.size() > 0)
	{
		IAction* Action = ChangeAction(m_actions.front());
		UE_LOG(LogTemp, Log, TEXT("ALaserBeam EventUpdate"));
		checkf(Action != nullptr, TEXT("ALaserBeam EventUpdate in Action is nullptr"));
		Action->Execute(this);
		m_actions.pop();
	}

	m_actions.push(EVariousAction::GUIDANCE_MOVE);

	if (m_attack_term < m_term_count)
	{
		m_actions.push(EVariousAction::ATTACK);
		m_term_count = 0;
	}
}

void ALaserBeam::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("Overlap ALaserBeam"));
	m_actions.push(EVariousAction::ATTACK);
}

void ALaserBeam::Tick(float Delta)
{
	Super::Tick(Delta);
	EventUpdate();
	++m_term_count;
}