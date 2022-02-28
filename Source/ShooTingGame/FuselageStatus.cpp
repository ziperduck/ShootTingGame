// Fill out your copyright notice in the Description page of Project Settings.


#include "FuselageStatus.h"

FuselageStatus::FuselageStatus(const float MaxHP, const float Speed, const float AttackPower)
	: m_max_hp(MaxHP), m_speed(Speed), m_attack_power(AttackPower) {}

FuselageStatus::~FuselageStatus()
{
}

void FuselageStatus::SetAttackPower(const float Power)
{
	m_attack_power = Power;
}
