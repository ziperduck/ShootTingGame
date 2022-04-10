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

FuselageStatus& FuselageStatus::PlayerStatus()
{
	static FuselageStatus* UFOStatus = new FuselageStatus{ 3.0f,2.0f, 2.0f };
	return *UFOStatus;
}

FuselageStatus& FuselageStatus::FireDragonStatus()
{
	static FuselageStatus* FireDragonStatus = new FuselageStatus{ 1.0f,2.0f, 1.0f };
	return *FireDragonStatus;
}

FuselageStatus& FuselageStatus::RushDragonStatus()
{
	static FuselageStatus* RushDragonStatus = new FuselageStatus{ 1.0f,3.0f, 1.0f };
	return *RushDragonStatus;
}

FuselageStatus& FuselageStatus::BoomDragonStatus()
{
	static FuselageStatus* BoomDragonStatus = new FuselageStatus{ 1.0f,1.0f, 2.0f };
	return *BoomDragonStatus;
}

FuselageStatus& FuselageStatus::MeteoricStoneStatus()
{
	static FuselageStatus* MeteoricStoneStatus = new FuselageStatus{ 1.0f,2.0f, 1.0f };
	return *MeteoricStoneStatus;
}

FuselageStatus& FuselageStatus::BulletStatus()
{
	static FuselageStatus* BulletStatus = new FuselageStatus{ 1.0f,3.0f, 0.0f };
	return *BulletStatus;
}

FuselageStatus& FuselageStatus::LaserBeamStatus()
{
	static FuselageStatus* LaserBeamStatus = new FuselageStatus{ 1.0f,1.0f,0.0f };
	return *LaserBeamStatus;
}

FuselageStatus& FuselageStatus::FireBallStatus()
{
	static FuselageStatus* BulletStatus = new FuselageStatus{ 1.0f,3.0f, 0.0f };
	return *BulletStatus;
}

FuselageStatus& FuselageStatus::HealPackStatus()
{
	static FuselageStatus* HealPackStatus = new FuselageStatus{ 1.0f,1.0f, 1.0f };
	return *HealPackStatus;
}

FuselageStatus& FuselageStatus::WeaponKitStatus()
{
	static FuselageStatus* WeaponKitStatus = new FuselageStatus{ 1.0f,1.0f, 1.0f };
	return *WeaponKitStatus;
}
