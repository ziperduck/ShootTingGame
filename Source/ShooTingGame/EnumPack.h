// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

UENUM(BlueprintType, Category = "Fuselage")
enum class EFuselageKind : uint8
{
	PLAYER_FUSELAGE = 0 UMETA(DisplayName = "PLAYER_FUSELAGE"),
	PLAYER_WEAPON UMETA(DisplayName = "PLAYER_WEAPON"),
	ENEMY_FUSELAGE UMETA(DisplayName = "ENEMY_FUSELAGE"),
	ENEMY_WEAPON UMETA(DisplayName = "ENEMY_WEAPON"),
	ITEM_FUSELAGE UMETA(DisplayName = "ITEM_FUSELAGE"),
};

UENUM(BlueprintType, Category = "Fuselage")
enum class EVariousWeapon : uint8
{
	RIFLE_WEAPON = 0 UMETA(DisplayName = "RIFLE_WEAPON"),
	LASERBEAM_WEAPON  UMETA(DisplayName = "LASERBEAM_WEAPON"),
	FIRESHOOT_WEAPON UMETA(DisplayName = "FIRESHOOT_WEAPON"),
};

UENUM(BlueprintType, Category = "FuselageAction")
enum class EVariousAction : uint8
{
	EAST_MOVE = 0 UMETA(DisplayName = "EAST_MOVE"),
	WEST_MOVE UMETA(DisplayName = "WEST_MOVE"),
	SOUTH_MOVE UMETA(DisplayName = "SOUTH_MOVE "),
	NORTH_MOVE UMETA(DisplayName = "NORTH_MOVE"),
	GUIDANCE_MOVE UMETA(DisplayName = "GUIDANCE_MOVE"),
	ATTACHPLAYER_MOVE UMETA(DisplayName = "ATTACHPLAYER_MOVE"),
	BOUNCE_MOVE UMETA(DisplayName = "BOUNCE_MOVE"),
	SHOOTING UMETA(DisplayName = "SHOOTING"),
	DEATH UMETA(DisplayName = "DEATH"),
	ATTACK UMETA(DisplayName = "ATTACK"),
	BOOM_ATTACK UMETA(DisplayName = "BOOM_ATTACK"),
	SPECIAL_BOOM UMETA(DisplayName = "SPECIAL_BOOM"),
	HEALING UMETA(DisplayName = "HEALING"),
	PLAYER_WEAPON_CHANGE UMETA(DisplayName = "PLAYER_WEAPON_CHANGE"),
	DROP_ITEM UMETA(DisplayName = "DROP_ITEM"),
	FUSELAGE_DIVIDE UMETA(DisplayName = "FUSELAGE_DIVIDE"),
};

UENUM(BlueprintType, Category = "DirectMove")
enum class EDirectMove : uint8
{
	LEFT_MOVE = 0 UMETA(DisplayName = "LEFT_MOVE "),
	RIGHT_MOVE UMETA(DisplayName = "RIGHT_MOVE "),
	STRAIGHT_MOVE UMETA(DisplayName = "STRAIGHT_MOVE "),
	BACK_MOVE UMETA(DisplayName = "BACK_MOVE ")

};