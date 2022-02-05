// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class SHOOTINGGAME_API FuselageState
{
public:
	FuselageState() {};
	virtual ~FuselageState() = 0{};

	virtual FuselageState* HandleInput() = 0;
	virtual void Update() = 0;
};
