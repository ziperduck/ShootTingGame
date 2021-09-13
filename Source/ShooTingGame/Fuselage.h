// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Action.h"
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FuselageFoundation.h"
#include "Fuselage.generated.h"

UENUM(BlueprintType, Category = "Fuselage")
enum class FuselageKind : uint8
{
	PlayerFuselage UMETA(DisplayName = "PlayerFuselage")
	, EnemyFuselage UMETA(DisplayName = "EnemyFuselage")
	, RifleFuselage UMETA(DisplayName = "RifleFuselage")
};

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
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Fuselage")
		const FuselageKind GetKind() const;
	virtual const FuselageKind GetKind_Implementation() const { return FuselageKind::PlayerFuselage; };

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Fuselage")
		const float GetSpeed() const;
	virtual const float GetSpeed_Implementation() const { return 1.0f; };

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Fuselage")
		const FVector GetLocation() const;
	virtual const FVector GetLocation_Implementation() const { return FVector::ZeroVector; };

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Fuselage")
		const FRotator GetRotation() const;
	virtual const FRotator GetRotation_Implementation() const { return FRotator::ZeroRotator; };

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Fuselage")
		UWorld* GetFuselageWorld() const;
	virtual UWorld* GetFuselageWorld_Implementation() const { return nullptr; };

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Fuselage")
		UClass* GetComponentClass() const;
	virtual UClass* GetComponentClass_Implementation() const { return nullptr; };

	//Setter
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Fuselage")
		void SetLocation(const FVector& Vector);
	virtual void SetLocation_Implementation(const FVector& Vector) {};

	//Event
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Fuselage")
		void AddAction(TScriptInterface<IAction>  Action);
	virtual void AddAction_Implementation(TScriptInterface<IAction>  Action) {};

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Fuselage")
		void EventUpdate();
	virtual void EventUpdate_Implementation() {};
};