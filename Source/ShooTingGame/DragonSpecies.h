// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnumPack.h"
#include "UObject/Interface.h"
#include "DragonSpecies.generated.h"

// This class does not need to be modified.
UINTERFACE(BlueprintType, MinimalAPI)
class UDragonSpecies : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SHOOTINGGAME_API IDragonSpecies
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Fuselage")
		void SetDeathActions(const TArray<EVariousAction>& NextActions);
	virtual void SetDeathActions_Implementation(const TArray<EVariousAction>& DeathActions) {};
};
