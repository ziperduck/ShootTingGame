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
	~FuselageStatus();

	//���ݷ��� �ٲ۴�.
	void SetAttackPower(const float Power);


	//�ִ� HP�� �޴´�.
	const int32 GetMaxHP() const { return m_max_hp; };

	//�̵��ӵ��� �޴´�.
	const float& GetSpeed() const { return m_speed; };

	//���ݷ��� �޴´�.
	const float GetAttackPower() const { return m_attack_power; };
	
	//�÷��̾��� �ɷ�ġ
	static FuselageStatus& PlayerStatus();

	//ȭ������ �ɷ�ġ
	static FuselageStatus& FireDragonStatus();

	//�������� �ɷ�ġ
	static FuselageStatus& RushDragonStatus();

	//���ȿ��� �ɷ�ġ
	static FuselageStatus& BoomDragonStatus();

	//��� �ɷ�ġ
	static FuselageStatus& MeteoricStoneStatus();


	//������ ���̾�� �ɷ�ġ
	static FuselageStatus& BulletStatus();

	//�÷��̾��� �Ѿ��� �ɷ�ġ
	static FuselageStatus& LaserBeamStatus();

	//�÷��̾��� ������ ���� �ɷ�ġ
	static FuselageStatus& FireBallStatus();


	//�÷��̾��� ������ �ɷ�ġ
	static FuselageStatus& HealPackStatus();

	//�÷��̾��� ���ⱳü�� �ɷ�ġ
	static FuselageStatus& WeaponKitStatus();

private:

	FuselageStatus(const float MaxHP, const float Speed, const float AttackPower);

private:

	const float m_max_hp;

	const float m_speed;

	float m_attack_power;

};
