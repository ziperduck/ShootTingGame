// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnumPack.h"
#include "UObject/Interface.h"
#include "Airframe.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UAirframe : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SHOOTINGGAME_API IAirframe
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = Airframe)
		void Initialize(const float Speed, const int32 MaxHP, EFuselageKind Weapon, const float Delay);

	//airgrame을 dragon이나 character에 상속시키고 action값에서 불러와서 shooting을 만들자
	virtual const EFuselageKind GetWeapon() const { return EFuselageKind::PLAYER_FUSELAGE; }
};