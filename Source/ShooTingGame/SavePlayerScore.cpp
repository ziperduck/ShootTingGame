// Fill out your copyright notice in the Description page of Project Settings.


#include "SavePlayerScore.h"

void USavePlayerScore::AddScore(const FString PlayerName, const int32 PlayerScore)
{
	TMap<FString, int32> NextScoreName;
	bool IsEmplace = false;
	
	for (auto name_score : m_player_name_score)
	{
		if (name_score.Value < PlayerScore && !IsEmplace)
		{
			IsEmplace = true;
			NextScoreName.Emplace(PlayerName, PlayerScore);
		}
	
		NextScoreName.Emplace(name_score.Key, name_score.Value);
	}
	
	if (NextScoreName.Num() > m_max_name_score)
	{
		NextScoreName.Remove(m_player_name_score.end().Key());
	}
	else if (!IsEmplace)
	{
		NextScoreName.Emplace(PlayerName, PlayerScore);
	}
	m_player_name_score = NextScoreName;
}

const TMap<FString,int32> USavePlayerScore::GetScoreName() const
{
	return m_player_name_score;
}