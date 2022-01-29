// Fill out your copyright notice in the Description page of Project Settings.


#include "FuselageStatus.h"

FuselageStatus::FuselageStatus()
	:m_max_hp(0), m_speed(0.0f), m_attack_power(0)
{
}

FuselageStatus::FuselageStatus(const int32 MaxHP, const float Speed, const int32 AttackPower)
	: m_current_hp(MaxHP),m_max_hp(MaxHP),m_speed(Speed),m_attack_power(AttackPower){}

FuselageStatus::~FuselageStatus()
{
}

void FuselageStatus::AddHP(int32 Num)
{
	m_current_hp += Num;
	
	if (m_current_hp > m_max_hp)
	{
		m_current_hp = m_max_hp;
	}
}
