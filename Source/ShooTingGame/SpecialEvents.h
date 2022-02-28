// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpecialEvent.h"


/**
 * 
 */

 //�÷��̾�� ������ �ش�.
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

//������ ���ȵ������� �ִ� ������ �Ѵ�.
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

//������ ���ȵ������� �ִ� ������ �Ѵ�.
class RandomItemDrop : public SpecialEvent
{
public:

	RandomItemDrop() {};
	virtual ~RandomItemDrop() final {};

private:

	virtual void EventPlay(FuselageCharacter* Character) final;

};