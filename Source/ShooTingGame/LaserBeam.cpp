// Fill out your copyright notice in the Description page of Project Settings.


#include "LaserBeam.h"
#include "Action.h"
#include "ActionInstance.h"
#include <Engine/Classes/Components/BoxComponent.h>
// Sets default values
ALaserBeam::ALaserBeam() {
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	UBoxComponent* BoxComponenet = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponenet->SetupAttachment(RootComponent);
	BoxComponenet->SetNotifyRigidBodyCollision(true);
	BoxComponenet->SetCollisionProfileName(TEXT("OverlapAll"));
	BoxComponenet->SetRelativeScale3D(FVector{20.0f,0.5f,0.5f});
	BoxComponenet->SetRelativeLocation(FVector{ 700.0f,0.0f,0.0f });

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Meshes/Projectile.Projectile"));
	UStaticMeshComponent* WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	if (MeshAsset.Succeeded() && MeshAsset.Object != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Mesh Aseet %s"), *MeshAsset.GetReferencerName());
		WeaponMesh->SetupAttachment(BoxComponenet);
		WeaponMesh->SetStaticMesh(MeshAsset.Object);
		WeaponMesh->SetRelativeScale3D(FVector{ 3.0f,1.0f,1.0f });
		WeaponMesh->SetNotifyRigidBodyCollision(false);

	}

	m_attack_term = 1;

	SetActorTickEnabled(false);
}

void ALaserBeam::BeginPlay()
{
	Super::BeginPlay();
	m_actions.push(EVariousAction::ATTACHPLAYER_MOVE);
}

void ALaserBeam::WeaponInitalize(const FWeaponStruct& Weapon)
{
	Tags.Add(TEXT("Fuselage"));
	Tags.Add(TEXT("Weapon"));

	m_attack_power = Weapon.m_attack_power;
	m_speed = Weapon.m_speed;
	m_attack_term = Weapon.m_shooting_delay;
	SetActorTickInterval(Weapon.m_shooting_delay);
	SetActorTickEnabled(true);
}

//Getter
const EFuselageKind ALaserBeam::GetKind() const
{
	return m_kind;
}

const float ALaserBeam::GetSpeed() const
{
	return m_speed;
}

const int32 ALaserBeam::GetAttackPower() const
{
	return m_attack_power;
}
const int32 ALaserBeam::GetAttackTerm() const
{
	return m_attack_term;
}


//Setter

void ALaserBeam::AttackFuselage(const int32 HP)
{
}

void ALaserBeam::MoveLocation(const FVector& MoveLocation) 
{
	SetActorLocation(GetActorLocation() + MoveLocation);
}

//Event
void ALaserBeam::EventUpdate()
{

	m_actions.push(EVariousAction::ATTACK);

	while (m_actions.size() > 0)
	{
		IAction* Action = ChangeAction(m_actions.front());
		UE_LOG(LogTemp, Log, TEXT("ALaserBeam EventUpdate"));
		checkf(Action != nullptr, TEXT("ALaserBeam EventUpdate in Action is nullptr"));
		Action->Execute(this);
		m_actions.pop();
	}
}

void ALaserBeam::Tick(float Delta)
{
	Super::Tick(Delta);
	EventUpdate();

}