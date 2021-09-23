// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Fuselage.h"
#include "CoreMinimal.h"

/**
 * 
 */
class IAction
{
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	virtual void Execute(AActor* Target) = 0;
};
