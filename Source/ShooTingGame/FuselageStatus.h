// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * max speed attack power������� static ������ ����ҷ��� current hp�� ���� ����� ���ƾ��Ѵ�,
 * union�� ������ ���� ���� static������ ����� ������ �ɰͰ���.
 * �� ���� USTRUCT�� ����ؼ� �������̽��� �ϼ��ؾ��ϳ�
 * 
 * ���߿��� ����ü�µ� ����� ����
 */

class FuselageStatus
{
public:
	FuselageStatus(const float MaxHP, const float Speed, const int32 AttackPower);
	~FuselageStatus();

	const int32 GetMaxHP() const { return m_max_hp; };

	const float& GetSpeed() const { return m_speed; };

	const int32 GetAttackPower() const { return m_attack_power; };

private:

	const float m_max_hp;

	const float m_speed;

	const int32 m_attack_power;

};
