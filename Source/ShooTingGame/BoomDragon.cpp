// Fill out your copyright notice in the Description page of Project Settings.


#include "BoomDragon.h"
#include "ActionInstance.h"

// Sets default values
ABoomDragon::ABoomDragon()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/PhysicMash/Boom.Boom"));
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

	Tags.Add(TEXT("Fuselage"));
	Tags.Add(TEXT("Airframe"));

	SetActorTickEnabled(false);
	SetActorEnableCollision(false);

}

void ABoomDragon::Initialize_Implementation(const float Speed, const int32 MaxHP, FWeaponStruct Weapon)
{
	if (!mb_initialize)
	{
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
void ABoomDragon::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABoomDragon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	EventUpdate();
}

void ABoomDragon::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("ABoomDragon Overlap"));

	IFuselage* Fuselage = Cast<IFuselage>(Actor);
	checkf(Fuselage != nullptr, TEXT("ABoomDragon overlap actor is not Fuselage"));

	if (!GetWorldTimerManager().IsTimerActive(m_boom_timer_handle)
		&& Fuselage->GetKind() == EFuselageKind::PLAYER_FUSELAGE)
	{
		GetWorldTimerManager().SetTimer(m_boom_timer_handle
			, [&] {
			m_actions.Push(EVariousAction::BOOM_ATTACK);
			m_actions.Push(EVariousAction::DEATH); }, 2.0f, false);
	}
	m_actions.Push(EVariousAction::ATTACK);

	return;
}

const EFuselageKind ABoomDragon::GetKind() const
{
	return m_kind;
}

const float ABoomDragon::GetSpeed() const
{
	return m_weapon.m_speed;
}

const int32 ABoomDragon::GetAttackPower() const
{
	return 1;
}

const int32 ABoomDragon::GetMaxHP() const
{
	return m_max_HP;
}

const FWeaponStruct ABoomDragon::GetWeapon()const
{
	return m_weapon;
}


void ABoomDragon::AttackFuselage(const int32 HP)
{
	m_current_HP += HP;
}

void ABoomDragon::MoveLocation(const FVector& MoveLocation)
{
	SetActorLocation(GetActorLocation() + MoveLocation);
}

void ABoomDragon::EventUpdate()
{
	while (m_actions.GetAllocatedSize() > 0)
	{
		IAction* Action = ChangeAction(m_actions.Pop());
		Action->Execute(this);
	}
	if (m_current_HP < 1)
	{
		ChangeAction(EVariousAction::DEATH)->Execute(this);
	}
	else
	{
		m_actions.Push(EVariousAction::GUIDANCE_MOVE);
	}
}
