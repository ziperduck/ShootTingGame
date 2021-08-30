// Copyright Epic Games, Inc. All Rights Reserved.

#include "Object.h"
#include "ObjectManager.h"
#include "ShooTingGameGameModeBase.h"

AShooTingGameGameModeBase::AShooTingGameGameModeBase() {
	PrimaryActorTick.bCanEverTick = true;
	m_object_manager = ObjectManager::GetInstance();
	UE_LOG(LogTemp, Log, TEXT("AShooTingGameGameModeBase"));

}

void AShooTingGameGameModeBase::StartPlay() {
}

void AShooTingGameGameModeBase::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
	m_object_manager->ObjectsUpdate();
}
