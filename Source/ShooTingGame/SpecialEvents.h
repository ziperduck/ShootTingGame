// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpecialEvent.h"


/**
 * 
 */

 //플레이어에게 점수를 준다.
class PlayerRaiseScore :public SpecialEvent
{
public:
	PlayerRaiseScore(const uint32 Score);
	virtual ~PlayerRaiseScore() final {};

private:

	virtual void EventPlay(FuselageCharacter* Character) final;

private:

	uint32 m_score;

};

//범위에 폭팔데미지를 주는 공격을 한다.
class RangeBoom : public SpecialEvent
{
public:

	RangeBoom(const float Radius, const float Damage, const float Delay);
	virtual ~RangeBoom() final {};

private:

	virtual void EventPlay(FuselageCharacter* Character) final;

private:

	const float m_radius;

	const float m_damage;

	const float m_delay;

};

//범위에 폭팔데미지를 주는 공격을 한다.
class RandomItemDrop : public SpecialEvent
{
public:

	RandomItemDrop() {};
	virtual ~RandomItemDrop() final {};

private:

	virtual void EventPlay(FuselageCharacter* Character) final;

};