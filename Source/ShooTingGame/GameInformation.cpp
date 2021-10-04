// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInformation.h"

GameInformation::GameInformation()
 : m_map_width(1400.0f), m_map_height(2800.0f){
}

GameInformation::~GameInformation()
{
}

GameInformation* GameInformation::GetInstance()
{
	static GameInformation* Interface = new GameInformation();
	return Interface;
}

const float GameInformation::GetMapWidthMinLocation()
{
	return -m_map_width *0.5f;
}

const float GameInformation::GetMapWidthMaxLocation()
{
	return m_map_width * 0.5f;
}

const float GameInformation::GetMapHeightMinLocation()
{
	return -m_map_height * 0.5f;
}

const float GameInformation::GetMapHeightMaxLocation()
{
	return m_map_height * 0.5f;
}
