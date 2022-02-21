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

	RangeBoom(const float Radius, const int32 Damage, const float Timer);
	virtual ~RangeBoom() final {};

private:

	virtual void EventPlay(FuselageCharacter* Character) final;

private:

	float m_radius;

	int32 m_damage;

	float m_timer;

};