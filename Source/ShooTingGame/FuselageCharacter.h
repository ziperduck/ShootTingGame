// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class SHOOTINGGAME_API FuselageCharacter
{
public:
	FuselageCharacter(AActor* Actor);
	virtual ~FuselageCharacter() =0 {};

	virtual bool Move() = 0;
	virtual bool Collision() = 0;
	virtual bool Death() = 0;

private:

	FuselageCharacter() = delete;

protected:

	AActor* m_actor;
};
