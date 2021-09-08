// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyDragon.h"
// Sets default values
AEnemyDragon::AEnemyDragon()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/PhysicMash/PuzzleCube.PuzzleCube"));
	CharacterMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	if (MeshAsset.Succeeded() && MeshAsset.Object != nullptr)
	{

		CharacterMesh->SetStaticMesh(MeshAsset.Object);
		CharacterMesh->SetAllMassScale(0.5f);
		RootComponent = CharacterMesh;
	}

	m_kind = FuselageKind::RifleFuselage;
	m_speed = 4.0f;
	m_max_HP = 1;
	m_current_HP = m_max_HP;

}

const FuselageKind AEnemyDragon::GetKind() const
{
	return m_kind;
}

const float AEnemyDragon::GetSpeed() const
{
	return m_speed;
}

const FVector AEnemyDragon::GetLocation() const
{
	return K2_GetActorLocation();
}

const FRotator AEnemyDragon::GetRotation() const
{
	return K2_GetActorRotation();
};

UWorld* AEnemyDragon::GetFuselageWorld() const
{
	return GetFuselageWorld();
}

const TSharedPtr<IFuselage> AEnemyDragon::GetWeapon() const
{
	return m_weapon;
}

 UClass* AEnemyDragon::GetComponentClass() const
{
	return GetClass();
}

void AEnemyDragon::SetLocation(const FVector& MoveLocation) {
	/*
	* setLocatino은 충돌처리를 못하고 랜더링 값을 가지고있기때문에
	* USceneComponenet를 이용해 충돌처리와 이동을 같이 처리하게 만들었다.
	*/

	FHitResult Hit(1.f);

	checkf(this != nullptr, TEXT("ARifle is nullptr"));
	
	RootComponent->MoveComponent(MoveLocation, GetRotation(), true, &Hit);
	if (Hit.IsValidBlockingHit())
	{
		UE_LOG(LogTemp, Log, TEXT("is Hit Actor"));
	}
}


void AEnemyDragon::AddAction(std::shared_ptr<IAction> Action)
{
	m_actions.push(Action);
}

void AEnemyDragon::AddNextAction(std::queue<std::shared_ptr<IAction>> Animation)
{
	m_animation = Animation;
}

void AEnemyDragon::Update() {

	UE_LOG(LogTemp, Log, TEXT("m_actions size %d"), m_actions.size());
	while (!m_actions.empty())
	{
		m_actions.front()->execute(this);
		m_actions.pop();
	}
	if (!m_animation.empty())
	{
		m_actions = m_animation;
	}
}


