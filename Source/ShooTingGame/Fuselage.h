// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnumPack.h"
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Fuselage.generated.h"


// This class does not need to be modified.
UINTERFACE(BlueprintType,MinimalAPI)
class UFuselage : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SHOOTINGGAME_API IFuselage
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	//Getter
	virtual const EFuselageKind GetKind() const { return EFuselageKind::PlayerFuselage; };

	virtual const float GetSpeed() const { return 1.0f; };

	virtual const FVector GetLocation() const { return FVector::ZeroVector; };

	virtual const FRotator GetRotation() const { return FRotator::ZeroRotator; };

	virtual UWorld* GetFuselageWorld() const { return nullptr; };

	virtual const int32 GetStruckDamage() const { return 0; };

	virtual const int32 GetAttackPower() const { return 0; };

	//Setter
	virtual void SetCurrentHP(const int8 HP){}

	//Event
	virtual void EventUpdate(){}

	virtual void MoveLocation(const FVector& Vector) {
		UE_LOG(LogTemp, Log, TEXT("Pure virtual MoveLocation"));
	};
};