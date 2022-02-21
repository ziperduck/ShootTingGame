// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterData.h"

PlayerCharacterData::PlayerCharacterData(uint32 BoomNum)
	:m_score(0),m_boom_num(BoomNum)
{
}

PlayerCharacterData::~PlayerCharacterData()
{
}

void PlayerCharacterData::AddScore(const int32 Score)
{
	checkf(Score >= 0, TEXT("Add Scroe argument is over value"));

	m_score += Score;
}

void PlayerCharacterData::UseSuperBoom()
{
	if (m_boom_num > 0)
	{
		--m_boom_num;
	}
}

const uint32 PlayerCharacterData::GetScore() const
{
	return m_score;
}

const uint32 PlayerCharacterData::GetSuperBoomNum() const
{
	return m_boom_num;
}
