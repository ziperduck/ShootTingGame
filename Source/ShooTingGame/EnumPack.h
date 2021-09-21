// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

UENUM(BlueprintType, Category = "Fuselage")
enum class EFuselageKind : uint8
{
	PlayerFuselage UMETA(DisplayName = "PlayerFuselage")
	, EnemyFuselage UMETA(DisplayName = "EnemyFuselage")
	, RifleFuselage UMETA(DisplayName = "RifleFuselage")
};

UENUM(BlueprintType, Category = "Fuselage'Action")
enum class EVariousAction : uint8
{
	EastMove UMETA(DisplayName = "EastMove ")
	, WestMove UMETA(DisplayName = "WestMove ")
	, SouthMove UMETA(DisplayName = "SouthMove ")
	, NorthMove UMETA(DisplayName = "NorthMove ")
	, Shooting UMETA(DisplayName = "Shooting")
};