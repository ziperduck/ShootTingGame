// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverWidget.h"

#include <Kismet/GameplayStatics.h>

#include "GameFramework/GameMode.h"

#include "PlayerCharacterData.h"
#include "PlayerBaseData.h"


void UGameOverWidget::ReStarte()
{
	UE_LOG(LogTemp, Log, TEXT("UGameplayStatics::GetCurrentLevelName(this) = %s"), *UGameplayStatics::GetCurrentLevelName(this));
	UGameplayStatics::GetGameMode(this)->ResetLevel();
	UGameplayStatics::OpenLevel(this, *UGameplayStatics::GetCurrentLevelName(this));
}

void UGameOverWidget::BackMainMenu(FString LevelName)
{
	UGameplayStatics::OpenLevel(this, *LevelName);
}

void UGameOverWidget::SaveCurrentNameScore()
{
	UE_LOG(LogTemp, Log, TEXT("UGameOverWidget::SaveCurrentNameScore()"));
	m_save_game->AddScore(m_current_name, m_current_score);
	UGameplayStatics::SaveGameToSlot(m_save_game, m_solt_name, m_solt_index);
}


void UGameOverWidget::SetCurrentName(const FString CurrentName)
{
	m_current_name = CurrentName;
}


const FString UGameOverWidget::GetCurrentName() const
{
	return m_current_name;
}

const int32 UGameOverWidget::GetCurrentScore() const
{
	return m_current_score;
}

TMap<FString, int32> UGameOverWidget::GetSavePlayerNameScore() const
{
	return m_save_namescore;
}

void UGameOverWidget::NativeConstruct()
{
	Super::NativeConstruct();
	UE_LOG(LogTemp, Log, TEXT("UGameOverWidget::Construct()"));

	if (UGameplayStatics::DoesSaveGameExist(m_solt_name, m_solt_index))
	{
		m_save_game = Cast<USavePlayerScore>(UGameplayStatics::LoadGameFromSlot(m_solt_name, m_solt_index));
	}
	else
	{
		m_save_game = Cast<USavePlayerScore>(UGameplayStatics::CreateSaveGameObject(USavePlayerScore::StaticClass()));
	}


	m_save_namescore = m_save_game->GetScoreName();

	for (auto i : m_save_namescore)
	{
		UE_LOG(LogTemp, Log, TEXT("m_save_namescore Key = %s, Value = %d"), *i.Key, i.Value);
	}

	APawn* Player = GetWorld()->GetFirstPlayerController()->GetPawn();

	IPlayerBaseData* Player_data = Cast<IPlayerBaseData>(Player);
	checkf(Player_data != nullptr, TEXT("PlayerBase->GetPlayerData() != nullptr"));

	m_current_score = Player_data->GetPlayerData()->GetScore();
}

