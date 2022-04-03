// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWidget.h"


void UPlayerWidget::NativeConstruct()
{
	Super::NativeConstruct();
	APawn* Player = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	m_fuselage_data = Cast<IFuselageBaseData>(Player);
	checkf(m_fuselage_data != nullptr, TEXT("UPlayerWidget::NativeConstruct m_fuselage_datanullptr"));



	m_player_data = Cast<IPlayerBaseData>(Player);
	checkf(m_player_data != nullptr, TEXT("UPlayerWidget::NativeConstruct m_player_data is nullptr"));

}

FString UPlayerWidget::GetPlayerScore()
{
	//플레이어의 고유 데이터
	std::shared_ptr<PlayerCharacterData> PlayerData = m_player_data->GetPlayerData();
	checkf(PlayerData.get() != nullptr, TEXT("UPlayerWidget::NativeConstruct PlayerData.get() is nullptr"));

	FString Score = FString::Printf(TEXT("Score : %d"), PlayerData->GetScore());
	return Score;
}

FString UPlayerWidget::GetPlayerFinishMove()
{
	//플레이어의 고유 데이터
	std::shared_ptr<PlayerCharacterData> PlayerData = m_player_data->GetPlayerData();
	checkf(PlayerData.get() != nullptr, TEXT("UPlayerWidget::NativeConstruct PlayerData.get() is nullptr"));
	
	FString FinishMoveNum = FString::Printf(TEXT("FinishMove : %d"), PlayerData->GetSuperBoomNum());
	return FinishMoveNum;
}


FString UPlayerWidget::GetPlayerHP()
{
	
	//플레이어의 캐릭터 데이터
	std::shared_ptr<FuselageCharacter> Fuselagedata = m_fuselage_data->GetBaseData();
	checkf(Fuselagedata.get() != nullptr, TEXT("UPlayerWidget::NativeConstruct Fuselagedata.get() is nullptr"));

	FString HP = FString::Printf(TEXT("HP : %d"), (int32)Fuselagedata->GetCurrentHP());
	return HP;
}
