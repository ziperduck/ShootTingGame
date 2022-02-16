// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageCharacter.h"

/**
 * 
 */
class FuselageBehavior
{
public:
	FuselageBehavior();
	virtual ~FuselageBehavior() = 0 {};

	virtual bool execute(std::shared_ptr<FuselageCharacter> Character) = 0;
};
