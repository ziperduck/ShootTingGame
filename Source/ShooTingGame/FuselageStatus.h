// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * max speed attack power같은경우 static 변수로 사용할려면 current hp를 따로 만들어 놓아야한다,
 * union도 있으니 같이 고정 static값으로 만들어 놓으면 될것같다.
 * 아 하필 USTRUCT를 사용해서 인터페이스를 완성해야하네
 * 
 * 나중에는 현재체력도 여기다 놓자
 */

class FuselageStatus
{
public:
	FuselageStatus(const float MaxHP, const float Speed, const float AttackPower);
	~FuselageStatus();

	//공격력을 바꾼다.
	void SetAttackPower(const float Power);


	//최대 HP를 받는다.
	const int32 GetMaxHP() const { return m_max_hp; };

	//이동속도를 받는다.
	const float& GetSpeed() const { return m_speed; };

	//공격력을 받는다.
	const float GetAttackPower() const { return m_attack_power; };

private:

	const float m_max_hp;

	const float m_speed;

	float m_attack_power;

};
