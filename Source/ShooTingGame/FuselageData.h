// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <GenericPlatform/GenericPlatform.h>

/**
 * 
 */
class FuselageData
{
public:
	FuselageData(const float Speed, int32 Attack_Power) : m_speed(Speed), m_attack_power(Attack_Power) {};
	~FuselageData() {};

	const float& GetSpeed() const { return m_speed; };
	int32 GetAttackPower() const { return m_attack_power; };

private:
	FuselageData() = delete;

	const float m_speed;

	int32 m_attack_power;


};
