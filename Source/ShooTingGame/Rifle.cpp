// Fill out your copyright notice in the Description page of Project Settings.


#include "Rifle.h"

// Sets default values
ARifle::ARifle()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/PhysicMash/PuzzleCube.PuzzleCube"));
	CharacterMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	if (MeshAsset.Succeeded() && MeshAsset.Object != nullptr)
	{

		CharacterMesh->SetStaticMesh(MeshAsset.Object);
		CharacterMesh->SetAllMassScale(0.2f);
		RootComponent = CharacterMesh;
	}
	m_kind = FuselageKind::RifleFuselage;
	m_speed = 4.0f;
	m_damage = 3;
	m_max_HP = 1;
	m_current_HP = m_max_HP;

}

const FuselageKind ARifle::GetKind() const
{
	return m_kind;
}

const float ARifle::GetSpeed() const
{
	return m_speed;
}

const FVector ARifle::GetLocation() const
{
	return K2_GetActorLocation();
}

const FRotator ARifle::GetRotation() const
{
	return K2_GetActorRotation();
}

UWorld* ARifle::GetFuselageWorld() const
{
	return GetWorld();
}

 UClass* ARifle::GetComponentClass() const
{
	return GetClass();
}


void ARifle::SetLocation(const FVector& MoveLocation) {
	/*
	* setLocatino은 충돌처리를 못하고 랜더링 값을 가지고있기때문에
	* USceneComponenet를 이용해 충돌처리와 이동을 같이 처리하게 만들었다.
	*/

	FHitResult Hit(1.f);
	checkf(this != nullptr, TEXT("ARifle is nullptr"));

	GetRootComponent()->MoveComponent(MoveLocation, GetRotation(), true, &Hit);
	if (Hit.IsValidBlockingHit())
	{
		UE_LOG(LogTemp, Log, TEXT("is Hit Actor"));
	}
}


void ARifle::AddAction(std::shared_ptr<IAction> Action)
{
	m_actions.push(Action);
}

void ARifle::AddNextAction(std::queue<std::shared_ptr<IAction>> Animation)
{
	m_animation = Animation;
}

void ARifle::Update() {

	UE_LOG(LogTemp, Log, TEXT("m_actions size %d"), m_actions.size());
	while (!m_actions.empty())
	{
		m_actions.front()->execute(Cast<IFuselage>(this));
		m_actions.pop();
	}
	if (!m_actions.empty())
	{
		m_actions = m_animation;
	}
}


