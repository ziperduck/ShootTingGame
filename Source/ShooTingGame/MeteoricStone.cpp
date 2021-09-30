// Fill out your copyright notice in the Description page of Project Settings.


#include "MeteoricStone.h"
#include "Action.h"
#include "ActionInstance.h"
#include <Engine/Classes/Components/SphereComponent.h>

// Sets default values
AMeteoricStone::AMeteoricStone()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/PhysicMash/PuzzleCube.PuzzleCube"));
	UStaticMeshComponent* WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	if (MeshAsset.Succeeded() && MeshAsset.Object != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Mesh Aseet %s"), *MeshAsset.GetReferencerName());
		WeaponMesh->SetupAttachment(RootComponent);
		WeaponMesh->SetStaticMesh(MeshAsset.Object);
		WeaponMesh->SetRelativeScale3D(FVector{ 0.4f,0.4f,0.4f });

		WeaponMesh->SetNotifyRigidBodyCollision(true);
		WeaponMesh->SetCollisionProfileName(TEXT("OverlapAll"));
	}

	mb_initialize = false;

	SetActorTickEnabled(false);
	SetActorEnableCollision(false);

}

void AMeteoricStone::Initialize_Implementation(const float Speed, const int32 MaxHP, FWeaponStruct Weapon)
{
	if (!mb_initialize)
	{
		Tags.Add(TEXT("Fuselage"));
		Tags.Add(TEXT("Airframe"));

		mb_initialize = true;

		UE_LOG(LogTemp, Log, TEXT("Initialize"));

		SetActorTickEnabled(true);
		SetActorEnableCollision(true);

		m_max_HP = MaxHP;
		m_current_HP = MaxHP;

		m_weapon = Weapon;
	}
}

// Called when the game starts or when spawned
void AMeteoricStone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMeteoricStone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	EventUpdate();
}

void AMeteoricStone::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("Meteoric Overlap"));
	m_actions.Enqueue(EVariousAction::ATTACK);
	return;
}

const EFuselageKind AMeteoricStone::GetKind() const
{
	return m_kind;
}

const float AMeteoricStone::GetSpeed() const
{
	return m_weapon.m_speed;
}

const int32 AMeteoricStone::GetAttackPower() const
{
	return 1;
}

const int32 AMeteoricStone::GetMaxHP() const
{
	return m_max_HP;
}

void AMeteoricStone::AttackFuselage(const int32 HP)
{
	m_current_HP += HP;
}

void AMeteoricStone::MoveLocation(const FVector& MoveLocation)
{
	SetActorLocation(GetActorLocation() + MoveLocation);
}

void AMeteoricStone::EventUpdate()
{
	while (!m_actions.IsEmpty())
	{
		IAction* Action = ChangeAction(*m_actions.Peek());
		Action->Execute(this);
		m_actions.Pop();
	}
	if (m_current_HP < 1)
	{
		//분해되는 건 그냥 운석을 두개 생성하자
		ChangeAction(EVariousAction::SHOOTING)->Execute(this);
		ChangeAction(EVariousAction::DEATH)->Execute(this);
	}
	else
	{
		m_actions.Enqueue(EVariousAction::SOUTH_MOVE);
	}
}

const FWeaponStruct AMeteoricStone::GetWeapon()const
{
	return m_weapon;
}

