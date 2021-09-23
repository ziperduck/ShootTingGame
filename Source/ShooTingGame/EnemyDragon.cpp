// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyDragon.h"
#include "Movement.h"

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
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Object is nullptr"));
	}

	m_kind = EFuselageKind::RifleFuselage;
	m_speed = 4.0f;
	m_max_HP = 1;
	m_current_HP = m_max_HP;

}

void AEnemyDragon::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp,Log,TEXT("Spawn EnemyDragon"));
}

const EFuselageKind AEnemyDragon::GetKind_Implementation() const
{
	return m_kind;
}

const float AEnemyDragon::GetSpeed_Implementation() const
{
	return m_speed;
}

const FVector AEnemyDragon::GetLocation_Implementation() const
{
	return K2_GetActorLocation();
}

const FRotator AEnemyDragon::GetRotation_Implementation() const
{
	return K2_GetActorRotation();
};

UWorld* AEnemyDragon::GetFuselageWorld_Implementation() const
{
	return GetWorld();
}

UClass* AEnemyDragon::GetComponentClass_Implementation() const
{
	return GetClass();
}

IFuselage*  AEnemyDragon::GetWeapon() const
{
	return m_weapon;
}

void AEnemyDragon::MoveLocation_Implementation(const FVector& MoveLocation) {
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

//Event
void AEnemyDragon::EventUpdate_Implementation() 
{
	while (m_actions.size() > 0)
	{
		//만약 인터페이스 정의되지 않았을경우를 체크한다.
		//IAction* Action = ChangeAction(m_actions.front());
		//m_actions.pop();
		//checkf(Action != nullptr, TEXT("Player animation No have Interface"));
		//Action->Execute_Implementation(StaticClass());
	}
	m_actions = m_next_actions;
}



