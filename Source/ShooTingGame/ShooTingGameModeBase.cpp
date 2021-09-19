// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShooTingGameModeBase.h"
#include "Fuselage.h"
#include "PlayerCharacter.h"
#include "ShootingPlayerController.h"

AShooTingGameModeBase::AShooTingGameModeBase() {
	PrimaryActorTick.bCanEverTick = false;
	UE_LOG(LogTemp, Log, TEXT("AShooTingGameModeBase"));
	DefaultPawnClass = APlayerCharacter::StaticClass();
	PlayerControllerClass = AShootingPlayerController::StaticClass();
}

void AShooTingGameModeBase::StartPlay() {
	Super::StartPlay();
	UE_LOG(LogTemp, Log, TEXT("AShooTingGameModeBase StartPlay"));
}

void AShooTingGameModeBase::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
}
