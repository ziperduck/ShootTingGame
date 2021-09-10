// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacterController.h"
#include "ActionInstance.h"
#include "Fuselage.h"
#include "EnemyDragon.h"

// Sets default values
APlayerCharacterController::APlayerCharacterController()
 :ApratVector(0.0f){
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	UE_LOG(LogTemp, Log, TEXT("AplayerContorller Constructor"));
}

// Called when the game starts or when spawned
void APlayerCharacterController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AplayerContorller BeginPlay"));
}


// Called to bind functionality to input
void APlayerCharacterController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	InputComponent->BindAxis("MoveX", this, &APlayerCharacterController::MoveX);
	InputComponent->BindAxis("MoveY", this, &APlayerCharacterController::MoveY);
	InputComponent->BindAction("EventA", IE_Pressed, this, &APlayerCharacterController::EventA);
}

void APlayerCharacterController::MoveX(float Direction)
{
	UE_LOG(LogTemp, Log, TEXT("Move XXX %f"), Direction);
	const int8 EastWest = Direction;
	constexpr int8 East = 1;
	constexpr int8 West = 2;

	switch (EastWest)
	{
	case East:
		break;
	case West:
		break;
	default:
		break;
	}

}

void APlayerCharacterController::MoveY(float Direction)
{
	UE_LOG(LogTemp, Log, TEXT("Move YYY %f"), Direction);
	const int8 SouthNorth = Direction;
	constexpr int8 South = 1;
	constexpr int8 North = 2;

	switch (SouthNorth)
	{
	case South:
		break;
	case North:
		break;
	default:
		break;
	}
}
void APlayerCharacterController::EventA() 
{
}