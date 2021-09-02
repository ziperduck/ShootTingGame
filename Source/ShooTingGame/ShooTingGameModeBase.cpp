// Copyright Epic Games, Inc. All Rights Reserved.

#include "Object.h"
#include "ObjectManager.h"
#include "ShooTingGameModeBase.h"

AShooTingGameModeBase::AShooTingGameModeBase() {
	PrimaryActorTick.bCanEverTick = true;
	m_object_manager = ObjectManager::GetInstance();
	UE_LOG(LogTemp, Log, TEXT("AShooTingGameModeBase"));
	m_object_manager->CreateObject(ObjectKind::EnemyObject,GetWorld(), FVector{ 200.0f,0.0f,50.0f});

}

void AShooTingGameModeBase::StartPlay() {
	Super::StartPlay();
	UE_LOG(LogTemp, Log, TEXT("AShooTingGameModeBase StartPlay"));
}

void AShooTingGameModeBase::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
	m_object_manager->ObjectsUpdate();
}
