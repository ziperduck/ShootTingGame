// Fill out your copyright notice in the Description page of Project Settings.


#include "Rifle.h"
#include "Movement.h"
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



 //Setter

void ARifle::AddCurrentHP(const int8 HP)
{
	m_current_HP += HP;
}

void ARifle::MoveLocation(const FVector& MoveLocation) {

	SetActorLocation(GetActorLocation() + MoveLocation);
}

void ARifle::SetKind(const EFuselageKind& Kind)
{
	m_kind = Kind;
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

	//플레이어가 쏘는 경우 남쪽으로 적은 북쪽으로 쏜다.
	switch (GetKind())
	{
	case EFuselageKind::PlayerRifle:
		m_actions.push(EVariousAction::NorthMove);
		break;
	case EFuselageKind::EnemyRifle:
		m_actions.push(EVariousAction::SouthMove);
		break;
	default:
		break;
	}
}

void ARifle::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("Overlap ARifle"));
	if (Actor == nullptr)
		return;
	IFuselage* OverlapTarget = Cast<IFuselage>(Actor);
	checkf(OverlapTarget != nullptr, TEXT("Overlap Target is nullptr"));

	//지금 rifle의 상태에 따라 어떤 캐릭터를 공격해야하는지 판단한다.
	if (GetKind() == EFuselageKind::PlayerRifle
		&& OverlapTarget->GetKind() == EFuselageKind::EnemyFuselage)
	{
		m_actions.push(EVariousAction::Death);
	}
	else if (GetKind() == EFuselageKind::EnemyRifle
		&& OverlapTarget->GetKind() == EFuselageKind::PlayerFuselage)
	{
		m_actions.push(EVariousAction::Death);
	}

}

void ARifle::Tick(float Delta)
{
	Super::Tick(Delta);
	EventUpdate();
}