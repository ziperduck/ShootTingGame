// Fill out your copyright notice in the Description page of Project Settings.


#include "MeteoricStone.h"
#include "Movement.h"
#include <Engine/Classes/Components/SphereComponent.h>

// Sets default values
AMeteoricStone::AMeteoricStone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USphereComponent* Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetNotifyRigidBodyCollision(true);
	Sphere->SetCollisionProfileName(TEXT("OverlapAll"));
	Sphere->InitSphereRadius(40.0f);
	RootComponent = Sphere;

	m_speed = 2.0f;
	m_max_HP = 3;
	m_current_HP = m_max_HP;
	m_struck_damage = 0;
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

	IFuselage* OverlapTarget = Cast<IFuselage>(Actor);
	checkf(OverlapTarget != nullptr, TEXT("Meteoric Fuselgae is nullptr"));

	switch (OverlapTarget->GetKind())
	{
	case EFuselageKind::PlayerFuselage:
	case EFuselageKind::Rifle:
		m_actions.push(EVariousAction::Struck);
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

void AMeteoricStone::AddCurrentHP(const int8 HP)
{
	m_current_HP += HP;
}

void AMeteoricStone::MoveLocation(const FVector& MoveLocation)
{
	SetActorLocation(GetActorLocation() + MoveLocation);
}

void AMeteoricStone::EventUpdate()
{
	while (m_actions.size() > 0)
	{
		IAction* Action = ChangeAction(m_actions.front());
		Action->Execute(this);
		m_actions.pop();
	}
	if (m_current_HP < 1)
	{
		ChangeAction(EVariousAction::Death)->Execute(this);
	}
	else
	{
		m_actions.push(EVariousAction::SouthMove);
	}
}

