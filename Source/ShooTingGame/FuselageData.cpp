// Fill out your copyright notice in the Description page of Project Settings.


#include "FuselageData.h"


FuselageData::FuselageData(const FuselageStatus& Status, const FuselageUnion& Union)
	:m_fix_status(Status), m_union(Union) {
	m_current_hp = Status.GetMaxHP();
}


void FuselageData::AddHP(int32 Num)
{
	UE_LOG(LogTemp, Log, TEXT("AddHP +=%d "),Num);
	m_current_hp += Num;

	if (m_current_hp > m_fix_status.GetMaxHP())
	{
		m_current_hp = m_fix_status.GetMaxHP();
	}
}

const int32 FuselageData::GetCurrentHP() const
{
	return m_current_hp;
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

const bool FuselageUnion::MatchUnion(const FuselageUnion& Union) const
{
	return Union.m_union | m_collision;
}

const int8 FuselageUnion::GetUnion() const
{
	return m_union;
}

const int8 FuselageUnion::GetCollision() const
{
	return m_collision;
}
