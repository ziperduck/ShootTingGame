// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageData.h"

/**
 * 
 */

struct FuselageStatus
{
public:

	FuselageStatus();

	FuselageStatus(const int32 MaxHP, const float Speed, const int32 AttackPower);

	~FuselageStatus();

	void AddHP(int32 Num);

	const int32 GetHP() const { return m_current_hp; };

	const int32 GetMaxHP() const { return m_max_hp; };

	const float& GetSpeed() const { return m_speed; };

	const int32 GetAttackPower() const { return m_attack_power; };

private:

	int32 m_current_hp;

	const int32 m_max_hp;

	const float m_speed;

	const int32 m_attack_power;


};