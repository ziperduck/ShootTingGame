// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FuselageFoundation.h"
#include "Fuselage.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UFuselage : public UInterface
{
	GENERATED_IINTERFACE_BODY()
};

/**
 * 
 */
class SHOOTINGGAME_API IFuselage
{
	GENERATED_IINTERFACE_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	//Getter
	virtual const FuselageKind GetKind() const = 0;

	virtual const float GetSpeed() const = 0;

	virtual const FVector GetLocation() const = 0;

	virtual const FRotator GetRotation() const = 0;

	virtual UWorld* GetFuselageWorld() const = 0;

	virtual  UClass* GetComponentClass() const = 0;

	//Setter
	virtual void SetLocation(const FVector&) = 0;


	//Event
	virtual void AddAction(std::shared_ptr<IAction>) = 0;

	virtual void Update() = 0;
};
