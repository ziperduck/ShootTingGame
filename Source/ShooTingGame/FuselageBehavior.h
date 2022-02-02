// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class FuselageBehavior
{
public:
	FuselageBehavior();
	virtual ~FuselageBehavior() = 0 {};

	virtual bool execute(AActor* Actor) = 0;
};
