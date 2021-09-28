// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

UENUM(BlueprintType, Category = "Fuselage")
enum class EFuselageKind : uint8
{
	PLAYER_FUSELAGE UMETA(DisplayName = "PLAYER_FUSELAGE"),
	RIFLE_WEAPON UMETA(DisplayName = "RIFLE_WEAPON"),
	LASERBEAM_WEAPON UMETA(DisplayName = "LASERBEAM_WEAPON"),
	ENEMY_FUSELAGE UMETA(DisplayName = "ENEMY_FUSELAGE"),
	METEORICSTONE_FUSELAGE UMETA(DisplayName = "METEORICSTONE_FUSELAGE"),
	MISSILEDRAGON_FUSELAGE UMETA(DisplayName = "MISSILEDRAGON_FUSELAGE"),
	FIRESHOOT_WEAPON UMETA(DisplayName = "FIRESHOOT_WEAPON"),
};

UENUM(BlueprintType, Category = "Fuselage'Action")
enum class EVariousAction : uint8
{
	EAST_MOVE UMETA(DisplayName = "EAST_MOVE"),
	WEST_MOVE UMETA(DisplayName = "WEST_MOVE"),
	SOUTH_MOVE UMETA(DisplayName = "SOUTH_MOVE "),
	NORTH_MOVE UMETA(DisplayName = "NORTH_MOVE"),
	GUIDANCE_MOVE UMETA(DisplayName = "GUIDANCE_MOVE"),
	SHOOTING UMETA(DisplayName = "SHOOTING"),
	STRUCK UMETA(DisplayName = "STRUCK"),
	DEATH UMETA(DisplayName = "DEATH"),
	ATTACK UMETA(DisplayName = "ATTACK"),
};