// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnumPack.h"
#include "CoreMinimal.h"
#include "WeaponStruct.generated.h"

/**
 */
USTRUCT(BlueprintType)
struct SHOOTINGGAME_API FWeaponStruct
{
public:
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite)
	float m_speed;

	UPROPERTY(BlueprintReadWrite)
	float m_shooting_delay;

	UPROPERTY(BlueprintReadWrite)
	EVariousWeapon m_weapon;

	UPROPERTY(BlueprintReadWrite)
	int32 m_attack_power;

};
