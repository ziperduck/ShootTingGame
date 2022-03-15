// Fill out your copyright notice in the Description page of Project Settings.


#include "FuselageUnion.h"

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

const FuselageUnion* FuselageUnion::PlayerUnion()
{
	static const FuselageUnion* Union = new FuselageUnion{ 
		static_cast<int8>(EUnionBinary::PLAYER_BINARY)
		, static_cast<int8>(EUnionBinary::ENEMY_BINARY) 
		| static_cast<int8>(EUnionBinary::ENEMY_WEAPON_BINARY) 
		| static_cast<int8>(EUnionBinary::KIT_BINARY) };
	return Union;
}

const FuselageUnion* FuselageUnion::PlayerInvincibilityUnion()
{
	static const FuselageUnion* Union = new FuselageUnion{ 
		static_cast<int8>(EUnionBinary::PLAYER_INVINCIBILITY_BINARY)
		, static_cast<int8>(EUnionBinary::ENEMY_BINARY) 
		| static_cast<int8>(EUnionBinary::ENEMY_WEAPON_BINARY) 
		| static_cast<int8>(EUnionBinary::KIT_BINARY) };
	return Union;
}

const FuselageUnion* FuselageUnion::FireDragonUnion()
{
	static const FuselageUnion* Union = new FuselageUnion{ 
		static_cast<int8>(EUnionBinary::ENEMY_BINARY)
		, static_cast<int8>(EUnionBinary::PLAYER_BINARY) 
		| static_cast<int8>(EUnionBinary::PLAYER_WEAPON_BINARY) };
	return Union;
}


const FuselageUnion* FuselageUnion::FireBallUnion()
{
	static const FuselageUnion* Union = new FuselageUnion{ 
		static_cast<int8>(EUnionBinary::ENEMY_WEAPON_BINARY)
		, static_cast<int8>(EUnionBinary::PLAYER_BINARY) };
	return Union;
}

const FuselageUnion* FuselageUnion::BulletUnion()
{
	static const FuselageUnion* Union = new FuselageUnion{ 
		static_cast<int8>(EUnionBinary::PLAYER_WEAPON_BINARY)
		, static_cast<int8>(EUnionBinary::ENEMY_BINARY) };
	return Union;
}

const FuselageUnion* FuselageUnion::LaserBeamUnion()
{
	static const FuselageUnion* Union = new FuselageUnion{ 
		static_cast<int8>(EUnionBinary::PLAYER_WEAPON_BINARY)
		, static_cast<int8>(EUnionBinary::ENEMY_BINARY)};
	return Union;
}


const FuselageUnion* FuselageUnion::HealPackUnion()
{
	static const FuselageUnion* Union = new FuselageUnion{ 
		static_cast<int8>(EUnionBinary::KIT_BINARY)
		, static_cast<int8>(EUnionBinary::PLAYER_BINARY) 
		| static_cast<int8>(EUnionBinary::PLAYER_INVINCIBILITY_BINARY) };
	return Union;
}
