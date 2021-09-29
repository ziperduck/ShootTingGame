// Fill out your copyright notice in the Description page of Project Settings.


#include "LaserBeam.h"
#include "Action.h"
#include "ActionInstance.h"
#include <Engine/Classes/Components/BoxComponent.h>
// Sets default values
ALaserBeam::ALaserBeam() {
	PrimaryActorTick.bCanEverTick = true;

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

	m_speed = 0.0f;
	m_max_HP = 100;
	m_current_HP = m_max_HP;
	m_attack_power = 1;
	m_attack_term = 60;

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

const int32 ALaserBeam::GetMaxHP() const
{
	return m_max_HP;
}

const int32 ALaserBeam::GetAttackTerm() const
{
	return m_attack_term;
}

TMap<AActor*, int32> ALaserBeam::GetAttackTargetCount() const
{
	return m_term_count;
}



//Setter

void ALaserBeam::AddCurrentHP(const int32 HP)
{
	m_current_HP += HP;
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

void ALaserBeam::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("Overlap begin ALaserBeam"));

	IFuselage* Fuselage = Cast<IFuselage>(Actor);
	checkf(Fuselage != nullptr, TEXT("Overlap Actor not Descendants of Fuselage"));

	switch (Fuselage->GetKind())
	{
	case EFuselageKind::ENEMY_FUSELAGE:
	case EFuselageKind::METEORICSTONE_FUSELAGE:
	case EFuselageKind::MISSILEDRAGON_FUSELAGE:
		m_term_count.Add(MakeTuple(Actor, m_attack_term));
		break;
	default:
		break;
	}
}

void ALaserBeam::NotifyActorEndOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("Overlap end ALaserBeam"));
	m_term_count.Remove(Actor);
}

void ALaserBeam::Tick(float Delta)
{
	Super::Tick(Delta);
	EventUpdate();

	for (auto& i : m_term_count)
	{
		if (i.Key == nullptr)
		{
			UE_LOG(LogTemp, Log, TEXT("m_term_count Key Remove"));
			m_term_count.Remove(i.Key);
		}
		else if (i.Value > m_attack_term)
		{
			i.Value = 0;
		}
		++i.Value;
		UE_LOG(LogTemp, Log, TEXT("Term Count %d"), i.Value);
	}
}