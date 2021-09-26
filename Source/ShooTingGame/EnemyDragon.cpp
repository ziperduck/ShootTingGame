// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyDragon.h"
#include "FireShoot.h"
#include "Movement.h"
#include <Engine/Classes/Components/SphereComponent.h>

// Sets default values
AEnemyDragon::AEnemyDragon() 
{

	PrimaryActorTick.bCanEverTick = true;

	USphereComponent* Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetNotifyRigidBodyCollision(true);
	Sphere->SetCollisionProfileName(TEXT("OverlapAll"));
	Sphere->InitSphereRadius(40.0f);
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

	m_weapon = EFuselageKind::FireShoot;
	m_speed = 4.0f;
	m_max_HP = 1;
	m_struck_damage = 0;
	m_current_HP = m_max_HP;
	m_shooting_delay = 1.0f;
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
void AEnemyDragon::AddCurrentHP(const int8 HP)
{
	m_current_HP += HP;
}

void AEnemyDragon::MoveLocation(const FVector& MoveLocation) {
	
	SetActorLocation(GetActorLocation() + MoveLocation);
}

//Event
void AEnemyDragon::EventUpdate()
{

	while (m_actions.GetAllocatedSize() > 0)
	{
		IAction* Action = ChangeAction(m_actions.Pop());
		checkf(Action != nullptr, TEXT("Player animation No have Interface"));
		Action->Execute(this);
	}
	if (m_current_HP < 1)
	{
		UE_LOG(LogTemp, Log, TEXT("Enemy Dragon Death"));
		ChangeAction(EVariousAction::Death)->Execute(this);
	}
	else
	{
		m_actions = m_next_actions;
	}
}

void AEnemyDragon::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("Overlap AEnemyDragon"));

	IFuselage* OverlapTarget = Cast<IFuselage>(Actor);
	checkf(OverlapTarget != nullptr, TEXT("Overlap Target is nullptr"));

	switch (OverlapTarget->GetKind())
	{
	case EFuselageKind::PlayerFuselage:
	case EFuselageKind::Rifle:
		UE_LOG(LogTemp, Log, TEXT("Enemy Overlap Rifle"));
		m_actions.Push(EVariousAction::Struck);
		m_struck_damage = OverlapTarget->GetAttackPower();
		break;
	default:
		UE_LOG(LogTemp, Log, TEXT("Enemy Overlap Ignore"));
		break;
	}
}

//타임머 만들고 드레곤에 붙이자
void AEnemyDragon::Tick(float Delta)
{
	Super::Tick(Delta);

	EventUpdate();
	if (!GetWorldTimerManager().IsTimerActive(m_shooting_timer))
	{
		m_actions.Push(EVariousAction::Shooting);
		GetWorldTimerManager().SetTimer(m_shooting_timer, m_shooting_delay, false);
	}
}



void AEnemyDragon::ShootingGun()
{
	switch (m_weapon)
	{
	case EFuselageKind::FireShoot:
		GetWorld()->SpawnActor<AFireShoot>(
			GetActorLocation() + FVector{ -60.0f,0.0f,0.0f }, FRotator::ZeroRotator);
		break;
	default:
		break;
	}
}
