// Fill out your copyright notice in the Description page of Project Settings.


#include "Rifle.h"
#include "Action.h"
#include "ActionInstance.h"
#include <Engine/Classes/Components/SphereComponent.h>

// Sets default values
ARifle::ARifle() {
	PrimaryActorTick.bCanEverTick = true;

	USphereComponent* Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetNotifyRigidBodyCollision(true);
	Sphere->SetCollisionProfileName(TEXT("OverlapAll"));
	Sphere->InitSphereRadius(20.0f);
	RootComponent = Sphere;

	m_characterScene = CreateAbstractDefaultSubobject<USceneComponent>(TEXT("Scene"));
	m_characterScene->SetupAttachment(RootComponent);
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Meshes/Projectile.Projectile"));
	UStaticMeshComponent* WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	if (MeshAsset.Succeeded() && MeshAsset.Object != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Mesh Aseet %s"), *MeshAsset.GetReferencerName());
		WeaponMesh->SetStaticMesh(MeshAsset.Object);
		WeaponMesh->SetupAttachment(m_characterScene);
	}

	m_speed = 4.0f;
	m_damage = 3;
	m_max_HP = 1;
	m_current_HP = m_max_HP;
	m_attack_power = 1;

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

const int32 ARifle::GetStruckDamage() const
{
	return m_struck_damage;
}

const int32 ARifle::GetAttackPower() const
{
	return m_attack_power;
}

const int32 ARifle::GetMaxHP() const
{
	return m_max_HP;
}



 //Setter

void ARifle::AddCurrentHP(const int32 HP)
{
	m_current_HP += HP;
}

void ARifle::MoveLocation(const FVector& MoveLocation) {

	SetActorLocation(GetActorLocation() + MoveLocation);
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
	if (m_current_HP < 1)
	{
		ChangeAction(EVariousAction::Death)->Execute(this);
	}
	else
	{
		m_actions.push(EVariousAction::NorthMove);
	}

}

void ARifle::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("Overlap ARifle"));

	IFuselage* OverlapTarget = Cast<IFuselage>(Actor);
	checkf(OverlapTarget != nullptr, TEXT("Overlap Target is nullptr"));

	switch (OverlapTarget->GetKind())
	{
	case EFuselageKind::EnemyFuselage:
	case EFuselageKind::MeteoricStone:
		UE_LOG(LogTemp, Log, TEXT("Rifle Collision Enemy"));
		m_actions.push(EVariousAction::Struck);
		break;
	default:
		break;
	}

}

void ARifle::Tick(float Delta)
{
	Super::Tick(Delta);
	EventUpdate();
}