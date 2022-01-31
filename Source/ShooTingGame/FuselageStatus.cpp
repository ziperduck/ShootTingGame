// Fill out your copyright notice in the Description page of Project Settings.


#include "FuselageStatus.h"

FuselageStatus::FuselageStatus(const int32 MaxHP, const float Speed, const int32 AttackPower)
	: m_max_hp(MaxHP), m_speed(Speed), m_attack_power(AttackPower) {}

FuselageStatus::~FuselageStatus()
{
}
