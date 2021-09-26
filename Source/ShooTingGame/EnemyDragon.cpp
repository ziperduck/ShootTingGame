// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyDragon.h"
#include "Rifle.h"
#include "Movement.h"
#include <Engine/Classes/Components/SphereComponent.h>

// Sets default values
AEnemyDragon::AEnemyDragon() 
{

	PrimaryActorTick.bCanEverTick = true;

	USphereComponent* Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetNotifyRigidBodyCollision(true);
	Sphere->SetCollisionProfileName(TEXT("OverlapAll"));
	Sphere->InitSphereRadius(100.0f);
	RootComponent = Sphere;

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/PhysicMash/PuzzleCube.PuzzleCube"));
	//m_character_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	//if (MeshAsset.Succeeded() && MeshAsset.Object != nullptr)
	//{
	//
	//	m_character_mesh->SetStaticMesh(MeshAsset.Object);
	//	m_character_mesh->SetAllMassScale(0.5f);
	//	m_character_mesh->SetupAttachment(RootComponent);
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Log, TEXT("Object is nullptr"));
	//}

	m_kind = EFuselageKind::RifleFuselage;
	m_speed = 4.0f;
	m_max_HP = 1;
	m_struck_damage = 0;
	m_current_HP = m_max_HP;

}

void AEnemyDragon::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp,Log,TEXT("Spawn EnemyDragon"));
}

//Getter
const EFuselageKind AEnemyDragon::GetKind() const
{
	return m_kind;
}

const float AEnemyDragon::GetSpeed() const
{
	return m_speed;
}

const int32 AEnemyDragon::GetStruckDamage() const
{
	return m_struck_damage;
}

const int32 AEnemyDragon::GetAttackPower() const
{
	return m_attack_power;
}

//Setter
void AEnemyDragon::SetCurrentHP(const int8 HP)
{
	m_current_HP += HP;
}

void AEnemyDragon::MoveLocation(const FVector& MoveLocation) {
	
	SetActorLocation(GetActorLocation() + MoveLocation);
}

//Event
void AEnemyDragon::EventUpdate()
{
	while (m_actions.size() > 0)
	{
		IAction* Action = ChangeAction(m_actions.front());
		m_actions.pop();
		checkf(Action != nullptr, TEXT("Player animation No have Interface"));
		Action->Execute(this);
	}

	if (m_current_HP < 1)
	{
		UE_LOG(LogTemp, Log, TEXT("Enemy Dragon Death"));
		ChangeAction(EVariousAction::Death)->Execute(this);
	}
	//m_actions = m_next_actions;
}

void AEnemyDragon::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("Overlap AEnemyDragon"));
	if (Actor == nullptr)
		return;
	IFuselage* OverlapTarget = Cast<IFuselage>(Actor);
	checkf(OverlapTarget != nullptr, TEXT("Overlap Target is nullptr"));
	
	m_actions.push(EVariousAction::Struck);
	m_struck_damage = OverlapTarget->GetAttackPower();
}

void AEnemyDragon::Tick(float Delta)
{
	Super::Tick(Delta);

	EventUpdate();
}



void AEnemyDragon::ShootingGun()
{
	switch (m_weapon)
	{
	case EFuselageKind::RifleFuselage:
		GetWorld()->SpawnActor<ARifle>(
			GetActorLocation() + FVector{ -60.0f,0.0f,0.0f }, FRotator::ZeroRotator);
		break;
	default:
		break;
	}
}
