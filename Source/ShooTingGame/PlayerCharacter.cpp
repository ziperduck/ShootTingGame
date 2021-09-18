// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "Movement.h"
#include <Engine/Classes/Camera/CameraComponent.h>

// Sets default values
APlayerCharacter::APlayerCharacter()
	:ApratVector(0.0f) {
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	UE_LOG(LogTemp, Log, TEXT("AplayerContorller Constructor"));
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/PhysicMash/PuzzleCube.PuzzleCube"));
	CharacterMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	if (MeshAsset.Succeeded() && MeshAsset.Object != nullptr)
	{

		CharacterMesh->SetStaticMesh(MeshAsset.Object);
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

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AplayerContorller BeginPlay"));
}


// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveX", this, &APlayerCharacter::MoveX);
	InputComponent->BindAxis("MoveY", this, &APlayerCharacter::MoveY);
}

void APlayerCharacter::MoveX(float Direction)
{
	UE_LOG(LogTemp, Log, TEXT("Move XXX %f"), Direction);
	const int8 EastWest = Direction;
	constexpr int8 East = 1;
	constexpr int8 West = 2;

	switch (EastWest)
	{
	case East:
		m_actions.push(EVariousAction::EastMove);
		break;
	case West:
		m_actions.push(EVariousAction::WestMove);
		break;
	default:
		break;
	}

}

void APlayerCharacter::MoveY(float Direction)
{
	UE_LOG(LogTemp, Log, TEXT("Move YYY %f"), Direction);
	const int8 SouthNorth = Direction;
	constexpr int8 South = 1;
	constexpr int8 North = 2;

	switch (SouthNorth)
	{
	case South:
		m_actions.push(EVariousAction::SouthMove);
		break;
	case North:
		m_actions.push(EVariousAction::NorthMove);
		break;
	default:
		break;
	}

}
void APlayerCharacter::EventA()
{
}

const EFuselageKind APlayerCharacter::GetKind_Implementation() const
{
	return m_kind;
}

const float APlayerCharacter::GetSpeed_Implementation() const
{
	return m_speed;
}

const FVector APlayerCharacter::GetLocation_Implementation() const
{
	return K2_GetActorLocation();
}

const FRotator APlayerCharacter::GetRotation_Implementation() const
{
	return K2_GetActorRotation();
};

UWorld* APlayerCharacter::GetFuselageWorld_Implementation() const
{
	return GetWorld();
}

UClass* APlayerCharacter::GetComponentClass_Implementation() const
{
	return GetClass();
}

TSubclassOf<UFuselage>  APlayerCharacter::GetWeapon() const
{
	return m_weapon;
}

void APlayerCharacter::SetLocation_Implementation(const FVector& MoveLocation) {
	/*
	* setLocatino은 충돌처리를 못하고 랜더링 값을 가지고있기때문에
	* USceneComponenet를 이용해 충돌처리와 이동을 같이 처리하게 만들었다.
	*/

	FHitResult Hit(1.f);

	GetRootComponent()->MoveComponent(MoveLocation, GetRotation(), true, &Hit);
	if (Hit.IsValidBlockingHit())
	{
		UE_LOG(LogTemp, Log, TEXT("is Hit Actor"));
	}
}

//Event
void APlayerCharacter::EventUpdate_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("Aplyaer Character EventUpdate"));
	while (m_actions.size() > 0)
	{
		//만약 인터페이스 정의되지 않았을경우를 체크한다.
		IAction* Action = ChangeAction(m_actions.front());
		m_actions.pop();
		checkf(Action != nullptr, TEXT("Player animation No have Interface"));
		Action->Execute_Implementation(StaticClass());
	}
}