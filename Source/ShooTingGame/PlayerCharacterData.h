// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class PlayerCharacterData
{
public:
	PlayerCharacterData(AActor* PlayerActor,uint32 BoomNum);
	~PlayerCharacterData();

	//점수를 더한다.
	void AddScore(const int32 Score);

	//폭탄을 갯수를 줄인다.
	void UseSuperBoom();


	//현재 플레이어의 엑터를 반환한다.
	const AActor* GetPlayerActor() const;

	//현재 스코어를 반환한다.
	const uint32 GetScore() const;

	//지금 폭탄의 갯수를 반환한다.
	const uint32 GetSuperBoomNum() const;

private:

	uint32 m_score;

	uint32 m_boom_num;

	AActor* m_player_actor;
};
