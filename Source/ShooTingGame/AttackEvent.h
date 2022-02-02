// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollisionEvent.h"

/**
 * 부딪힌 대상을 공격하는 이벤트 
 */
class AttackEvent : public CollisionEvent
{
public:
	AttackEvent(std::shared_ptr<FuselageData> Fuselage);
	virtual ~AttackEvent() final;

	virtual bool Collision(AActor* Actor) final;

};
