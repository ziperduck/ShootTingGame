// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class PlayerCharacterData
{
public:
	PlayerCharacterData(uint32 BoomNum);
	~PlayerCharacterData();

	void AddScore(const int32 Score);

	void UseSuperBoom();

	const uint32 GetScore() const;

	const uint32 GetSuperBoomNum() const;

private:

	uint32 m_score;

	uint32 m_boom_num;

};
