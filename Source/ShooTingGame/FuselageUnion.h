// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

 /*
 * � ��ü�� �浹���� �ڽ��� ��� �Ҽ������� ��Ÿ���� Struct
 */

struct FuselageUnion
{
public:
	~FuselageUnion();

	const int8 GetUnion() const;

	const int8 GetCollision() const;

	//�÷��̾��� �Ҽ�
	static const FuselageUnion* PlayerUnion();

	//�÷��̾ ���������� �Ҽ�
	static const FuselageUnion* PlayerInvincibilityUnion();

	//ȭ������ �Ҽ�
	static const FuselageUnion* FireDragonUnion();

	//�������� �Ҽ�
	static const FuselageUnion* RushDragonUnion();

	//���ȿ��� �Ҽ�
	static const FuselageUnion* BoomDragonUnion();

	//��� �Ҽ�
	static const FuselageUnion* MeteoricStoneUnion();


	//������ ���̾�� �Ҽ�
	static const FuselageUnion* FireBallUnion();

	//�÷��̾��� �Ѿ��� �Ҽ�
	static const FuselageUnion* BulletUnion();

	//�÷��̾��� ������ ���� �Ҽ�
	static const FuselageUnion* LaserBeamUnion();


	//�÷��̾��� ������ �Ҽ�
	static const FuselageUnion* HealPackUnion();

	//�÷��̾��� ���ⱳü�� �Ҽ�
	static const FuselageUnion* WeaponKitUnion();

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

