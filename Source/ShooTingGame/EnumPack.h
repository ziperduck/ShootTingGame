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
	PLAYER_WEAPON UMETA(DisplayName = "PLAYER_WEAPON"),
	ENEMY_FUSELAGE UMETA(DisplayName = "ENEMY_FUSELAGE"),
	ENEMY_WEAPON UMETA(DisplayName = "ENEMY_WEAPON"),
	ITEM_FUSELAGE UMETA(DisplayName = "ITEM_FUSELAGE"),
};

UENUM(BlueprintType, Category = "Fuselage")
enum class EVariousWeapon : uint8
{
	RIFLE_WEAPON  UMETA(DisplayName = "RIFLE_WEAPON"),
	LASERBEAM_WEAPON  UMETA(DisplayName = "LASERBEAM_WEAPON"),
	METEORICSTONE_WEAPON  UMETA(DisplayName = "METEORICSTONE_WEAPON"),
	MISSILEDRAGON_WEAPON  UMETA(DisplayName = "MISSILEDRAGON_WEAPON"),
	BOOM_WEAPON  UMETA(DisplayName = "BOOM_WEAPON"),
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
	ATTACHPLAYER_MOVE UMETA(DisplayName = "ATTACHPLAYER_MOVE"),
	SHOOTING UMETA(DisplayName = "SHOOTING"),
	DEATH UMETA(DisplayName = "DEATH"),
	ATTACK UMETA(DisplayName = "ATTACK"),
	BOOM_ATTACK UMETA(DisplayName = "BOOM_ATTACK"),
	HEALING UMETA(DisplayName = "HEALING"),
	WEAPON_UPGRADE UMETA(DisplayName = "WEAPON_UPGRADE"),
	DROP_ITEM UMETA(DisplayName = "DROP_ITEM"),
	FUSELAGE_DIVIDE UMETA(DisplayName = "FUSELAGE_DIVIDE"),
};