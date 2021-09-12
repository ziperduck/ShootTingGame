// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <memory>
#include "Action.h"

UENUM(BlueprintType,Category = "Fuselage")
enum class FuselageKind : uint8
{
	PlayerFuselage UMETA(DisplayName = "PlayerFuselage")
	, EnemyFuselage UMETA(DisplayName = "EnemyFuselage")
	, RifleFuselage UMETA(DisplayName = "RifleFuselage")
};
