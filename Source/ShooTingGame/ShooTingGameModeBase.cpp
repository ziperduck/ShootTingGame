// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShooTingGameModeBase.h"
#include <Blueprint/UserWidget.h>

AShooTingGameModeBase::AShooTingGameModeBase() {
	PrimaryActorTick.bCanEverTick = false;
	UE_LOG(LogTemp, Log, TEXT("AShooTingGameModeBase"));
}

void AShooTingGameModeBase::BeginPlay() {
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AShooTingGameModeBase StartPlay"));
	ChangeWidget(m_start_widget);
}

void AShooTingGameModeBase::ChangeWidget(TSubclassOf<UUserWidget> NewWidget)
{
	if (m_current_widget != nullptr)
	{
		m_current_widget->RemoveFromViewport();
		m_current_widget = nullptr;
	}

	if (NewWidget != nullptr)
	{
		m_current_widget = CreateWidget(GetWorld(), NewWidget);
		if (m_current_widget != nullptr)
		{
			m_current_widget->AddToViewport();
		}
	}
}