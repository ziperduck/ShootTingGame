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


	USphereComponent* Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetNotifyRigidBodyCollision(true);
	Sphere->SetCollisionProfileName(TEXT("OverlapAll"));
	Sphere->InitSphereRadius(40.0f);
	RootComponent = Sphere;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/PhysicMash/PuzzleCube.PuzzleCube"));
	UStaticMeshComponent* WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	if (MeshAsset.Succeeded() && MeshAsset.Object != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Mesh Aseet %s"), *MeshAsset.GetReferencerName());
		WeaponMesh->SetupAttachment(RootComponent);
		WeaponMesh->SetStaticMesh(MeshAsset.Object);
		WeaponMesh->SetRelativeScale3D(FVector{ 0.4f,0.4f,0.4f });
	}

	mb_initialize = false;

	SetActorTickEnabled(false);
	SetActorEnableCollision(false);

}

void AMeteoricStone::Initialize_Implementation(const float Speed, const int32 MaxHP, EFuselageKind Weapon, const float Delay)
{
	if (!mb_initialize)
	{
		mb_initialize = true;

		UE_LOG(LogTemp, Log, TEXT("Initialize"));

		SetActorTickEnabled(true);
		SetActorEnableCollision(true);

		m_speed = Speed;
		m_max_HP = MaxHP;
		m_current_HP = MaxHP;
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
	m_actions.Push(EVariousAction::ATTACK);
	return;
	UE_LOG(LogTemp, Log, TEXT("Meteoric Overlap"));

	IFuselage* OverlapTarget = Cast<IFuselage>(Actor);
	checkf(OverlapTarget != nullptr, TEXT("Meteoric Fuselgae is nullptr"));

	switch (OverlapTarget->GetKind())
	{
	case EFuselageKind::PLAYER_FUSELAGE:
	case EFuselageKind::RIFLE_WEAPON:
		m_actions.Push(EVariousAction::STRUCK);
		m_struck_damage = OverlapTarget->GetAttackPower();
		break;
	default:
		UE_LOG(LogTemp, Log, TEXT("Meteoric Ignore Overlap"));
		break;
	}

}

const EFuselageKind AMeteoricStone::GetKind() const
{
	return m_kind;
}

const float AMeteoricStone::GetSpeed() const
{
	return m_speed;
}

const int32 AMeteoricStone::GetStruckDamage() const
{
	return m_struck_damage;
}

const int32 AMeteoricStone::GetAttackPower() const
{
	return 1;
}

const int32 AMeteoricStone::GetMaxHP() const
{
	return m_max_HP;
}

void AMeteoricStone::AddCurrentHP(const int32 HP)
{
	m_current_HP += HP;
}

void AMeteoricStone::MoveLocation(const FVector& MoveLocation)
{
	SetActorLocation(GetActorLocation() + MoveLocation);
}

void AMeteoricStone::EventUpdate()
{
	while (m_actions.GetAllocatedSize() > 0)
	{
		IAction* Action = ChangeAction(m_actions.Pop());
		Action->Execute(this);
	}
	if (m_current_HP < 1)
	{
		//분해되는 건 그냥 운석을 두개 생성하자
		ChangeAction(EVariousAction::SHOOTING)->Execute(this);
		ChangeAction(EVariousAction::DEATH)->Execute(this);
	}
	else
	{
		m_actions.Push(EVariousAction::GUIDANCE_MOVE);
	}
}

const EFuselageKind AMeteoricStone::GetWeapon()const
{
	return m_weapon;
}

