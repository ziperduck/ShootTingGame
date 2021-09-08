// Copyright Epic Games, Inc. All Rights Reserved.

#include "Fuselage.h"
#include "FuselageManager.h"
#include "EnemyDragon.h"
#include "ShooTingGameModeBase.h"

AShooTingGameModeBase::AShooTingGameModeBase() {
	PrimaryActorTick.bCanEverTick = true;
	m_object_manager = FuselageManager::GetInstance();
	UE_LOG(LogTemp, Log, TEXT("AShooTingGameModeBase"));
	m_object_manager->AddFuselage(FuselageKind::EnemyFuselage,FVector{ 200.0f,100.0f,50.0f});

}

void AShooTingGameModeBase::StartPlay() {
	Super::StartPlay();
	UE_LOG(LogTemp, Log, TEXT("AShooTingGameModeBase StartPlay"));
}

void AShooTingGameModeBase::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
	m_object_manager->ObjectsUpdate();
}
