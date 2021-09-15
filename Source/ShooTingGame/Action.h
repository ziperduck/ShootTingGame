// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Fuselage.h"
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Action.generated.h"

// This class does not need to be modified.
UINTERFACE(BlueprintType, MinimalAPI)
class UAction : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SHOOTINGGAME_API IAction
{
	GENERATED_BODY()
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Fuselage")
		void Execute(TSubclassOf<UFuselage> Fuselage);
	virtual void Execute_Implementation(TSubclassOf<UFuselage>  Fuselage) {};
};
