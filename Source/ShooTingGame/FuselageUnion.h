// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

 /*
 * 어떤 물체와 충돌할지 자신은 어디 소속인지를 나타내는 Struct
 */

struct FuselageUnion
{
public:
	~FuselageUnion();

	const int8 GetUnion() const;

	const int8 GetCollision() const;

	//플레이어의 소속
	static const FuselageUnion* PlayerUnion();

	//플레이어가 무적상태의 소속
	static const FuselageUnion* PlayerInvincibilityUnion();

	//화염용의 소속
	static const FuselageUnion* FireDragonUnion();


	//적군의 파이어볼의 소속
	static const FuselageUnion* FireBallUnion();

	//플레이어의 총알의 소속
	static const FuselageUnion* BulletUnion();

	//플레이어의 레이저 빔의 소속
	static const FuselageUnion* LaserBeamUnion();


	//플레이어의 힐팩의 소속
	static const FuselageUnion* HealPackUnion();

private:

	FuselageUnion(const int8 Union, const int8 Collision);

	FuselageUnion() = delete;

private:

	const int8 m_union;

	const int8 m_collision;

};

enum class EUnionBinary {
	PLAYER_BINARY = 0b1
	, PLAYER_WEAPON_BINARY = 0b10
	, PLAYER_INVINCIBILITY_BINARY = 0b100

	, KIT_BINARY = 0b1000
	, ENEMY_BINARY = 0b10000
	, ENEMY_WEAPON_BINARY = 0b100000
};

