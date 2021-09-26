// Fill out your copyright notice in the Description page of Project Settings.


#include "FireShoot.h"
#include "Movement.h"
#include <Engine/Classes/Components/SphereComponent.h>

// Sets default values
AFireShoot::AFireShoot() {
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
const EFuselageKind AFireShoot::GetKind() const
{
	return m_kind;
}

const float AFireShoot::GetSpeed() const
{
	return m_speed;
}

const int32 AFireShoot::GetStruckDamage() const
{
	return m_struck_damage;
}

const int32 AFireShoot::GetAttackPower() const
{
	return m_attack_power;
}



 //Setter

void AFireShoot::AddCurrentHP(const int8 HP)
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
	case EFuselageKind::Rifle:
		m_actions.push(EVariousAction::NorthMove);
		break;
	case EFuselageKind::FireShoot:
		m_actions.push(EVariousAction::SouthMove);
		break;
	default:
		break;
	}
}

void AFireShoot::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("Overlap AFireShoot"));
	if (Actor == nullptr)
		return;
	IFuselage* OverlapTarget = Cast<IFuselage>(Actor);
	checkf(OverlapTarget != nullptr, TEXT("Overlap Target is nullptr"));

	if (OverlapTarget->GetKind() == EFuselageKind::PlayerFuselage)
	{
		UE_LOG(LogTemp, Log, TEXT("FireShoot Collision Player"));
		m_actions.push(EVariousAction::Death);
	}

}

void AFireShoot::Tick(float Delta)
{
	Super::Tick(Delta);
	EventUpdate();
}