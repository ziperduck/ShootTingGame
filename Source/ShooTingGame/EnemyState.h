// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageState.h"

/**
 * 
 */
class LivingState : public IFuselageState
{
public:
	LivingState();
	~LivingState();

private:

	virtual IFuselageState* HandleInput(FuselageCharacter& Fuselage, EInputBehavior Input) final;
	virtual void Update(FuselageCharacter& Fuselage) final;
};
