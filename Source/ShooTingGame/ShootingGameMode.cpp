// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingGameMode.h"

#include <Blueprint/UserWidget.h>

#include <random>

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
			UE_LOG(LogTemp, Log, TEXT("m_current_widget->AddToViewport()"));
			m_current_widget->AddToViewport();
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("m_current_widget == nullptr"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("NewWidgetClass is nullptr"));
	}

}


void AShootingGameMode::EnemySpawnStart(TArray<TSubclassOf<AActor>> Enemys, float Delay, FVector SpawnPointMin, FVector SpawnPointMax)
{
	if (!GetWorldTimerManager().IsTimerActive(m_spawn_timer))
	{
		UWorld* ShootingGameWorld = GetWorld();
		GetWorldTimerManager().SetTimer(m_spawn_timer, [ShootingGameWorld,Enemys, SpawnPointMin, SpawnPointMax]
		{
			//랜덤 적 스폰
			//std::random_device Device;
			//std::mt19937 Gen(Device());
			//
			//std::uniform_int_distribution<int32> Dis{ 0,Enemys.Num()-1 };
			//int32 RandomNum = Dis(Gen);
			int32 RandomNum = FMath::RandRange(0, Enemys.Num() - 1);

			//적의 위치를 설정한다.
			FVector RandomLocation = FVector(SpawnPointMin.X, FMath::RandRange(SpawnPointMin.Y, SpawnPointMax.Y), SpawnPointMin.Z);

			ShootingGameWorld->SpawnActor<AActor>(Enemys[RandomNum], RandomLocation, FRotator::ZeroRotator);
			
		}, Delay, true);
	}
}

void AShootingGameMode::EnemySpawnStop()
{
	GetWorldTimerManager().ClearTimer(m_spawn_timer);
}


const FVector2D AShootingGameMode::GetMapSize()
{
	return FVector2D(2700.0f, 1300.0f);
}

const FVector2D AShootingGameMode::GetHalfMapSize()
{
	return FVector2D(1350.0f, 650.0f);
}

void AShootingGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	GetWorldTimerManager().ClearAllTimersForObject(this);
}

void AShootingGameMode::BeginPlay()
{
	Super::BeginPlay();
	ChangeWidget(m_starte_widget_class);
}
