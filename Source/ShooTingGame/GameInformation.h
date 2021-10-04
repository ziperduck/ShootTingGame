// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class GameInformation
{
public:
	GameInformation();
	~GameInformation();

	static GameInformation* GetInstance();

	const float GetMapWidthMinLocation();

	const float GetMapWidthMaxLocation();

	const float GetMapHeightMinLocation();

	const float GetMapHeightMaxLocation();
private:

	const float m_map_width;

	const float m_map_height;

};
