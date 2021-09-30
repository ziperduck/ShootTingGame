// Fill out your copyright notice in the Description page of Project Settings.


#include "MissileDragon.h"

#include "Action.h"
#include "ActionInstance.h"
#include <Engine/Classes/Components/SphereComponent.h>

// Sets default values
AMissileDragon::AMissileDragon()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;


	USphereComponent* Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetNotifyRigidBodyCollision(true);
	Sphere->SetCollisionProfileName(TEXT("OverlapAll"));
	Sphere->InitSphereRadius(40.0f);
	RootComponent = Sphere;

	mb_initialize = false;

	SetActorTickEnabled(false);
	SetActorEnableCollision(false);

}

void AMissileDragon::Initialize_Implementation(const float Speed, const int32 MaxHP, FWeaponStruct Weapon)
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

		m_weapon = Weapon;
	}
}

// Called when the game starts or when spawned
void AMissileDragon::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMissileDragon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	EventUpdate();
}

void AMissileDragon::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("Meteoric Overlap"));
	m_actions.Push(EVariousAction::ATTACK);
	return;


}

const EFuselageKind AMissileDragon::GetKind() const
{
	return m_kind;
}

const float AMissileDragon::GetSpeed() const
{
	return m_speed;
}

const int32 AMissileDragon::GetAttackPower() const
{
	return 1;
}

const int32 AMissileDragon::GetMaxHP() const
{
	return m_max_HP;
}

void AMissileDragon::AttackFuselage(const int32 HP)
{
	m_current_HP += HP;
}

void AMissileDragon::MoveLocation(const FVector& MoveLocation)
{
	SetActorLocation(GetActorLocation() + MoveLocation);
}

void AMissileDragon::EventUpdate()
{
	while (m_actions.GetAllocatedSize() > 0)
	{
		IAction* Action = ChangeAction(m_actions.Pop());
		Action->Execute(this);
	}
	if (m_current_HP < 1)
	{
		//분해되는 건 그냥 운석을 두개 생성하자
		ChangeAction(EVariousAction::DEATH)->Execute(this);
	}
	else
	{
		m_actions.Push(EVariousAction::GUIDANCE_MOVE);
	}
}

const FWeaponStruct AMissileDragon::GetWeapon()const
{
	return m_weapon;
}


