// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingGameMode.h"

#include <Blueprint/UserWidget.h>

void AShootingGameMode::ChangeWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (m_current_widget != nullptr)
	{ 
		m_current_widget->RemoveFromViewport();
		m_current_widget = nullptr;
	} if (NewWidgetClass != nullptr) 
	{
		m_current_widget = CreateWidget(GetWorld(), NewWidgetClass);
		if (m_current_widget != nullptr)
		{
			m_current_widget->AddToViewport();
		}
	}

}

const FVector2D AShootingGameMode::GetMapSize()
{
	return FVector2D(500.0f, 200.0f);
}

const FVector2D AShootingGameMode::GetHalfMapSize()
{
	return FVector2D(250.0f, 100.0f);
}

void AShootingGameMode::BeginPlay()
{
	Super::BeginPlay();
	ChangeWidget(m_starte_widget_class);
}
