// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "PlayerCharacterData.h"
/**
 * 
 */
class PlayerCommand
{
public:	
	PlayerCommand() {};
	PlayerCommand(int32) {};
	virtual ~PlayerCommand() = 0 {};

	virtual bool execute(std::shared_ptr<PlayerCharacterData> Player) = 0;
};
