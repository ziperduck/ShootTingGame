// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollisionEvent.h"

/**
 * 
 */
class AttackEvent : public CollisionEvent
{
public:
	AttackEvent(std::shared_ptr<FuselageData> Fuselage);
	virtual ~AttackEvent() final;

	virtual bool Collision(AActor* Actor) final;

private:


};
