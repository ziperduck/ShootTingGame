// Fill out your copyright notice in the Description page of Project Settings.


#include "FuselageData.h"

#include "WeaponStruct.h"

FuselageData::FuselageData(WeaponStruct* Weapon, FuselageStatus& Status, const FuselageUnion& Union)
	:m_weapon(Weapon),m_fix_status(Status), m_union(Union) {
	m_current_hp = Status.GetMaxHP();
}


void FuselageData::AddHP(float Num)
{
	UE_LOG(LogTemp, Log, TEXT("AddHP +=%d "),Num);
	m_current_hp += Num;

	if (m_current_hp > m_fix_status.GetMaxHP())
	{
		m_current_hp = m_fix_status.GetMaxHP();
	}
}

void FuselageData::ChangeWeapon(WeaponStruct* Weapon)
{
	m_weapon = Weapon;
}

void FuselageData::SetAttackPower(const float Power)
{
	m_fix_status.SetAttackPower(Power);
}

const float FuselageData::GetCurrentHP() const
{
	return m_current_hp;
}

WeaponStruct* FuselageData::GetWeapon() const
{
	return m_weapon;
}

const FuselageStatus& FuselageData::GetStatus() const
{
	return m_fix_status;
}

const FuselageUnion& FuselageData::GetUnion() const
{
	return m_union;
}

FuselageUnion::FuselageUnion(const int8 Union, const int8 Collision)
	: m_union(Union), m_collision(Collision) {}

FuselageUnion::~FuselageUnion()
{
}

const int8 FuselageUnion::GetUnion() const
{
	return m_union;
}

const int8 FuselageUnion::GetCollision() const
{
	return m_collision;
}
