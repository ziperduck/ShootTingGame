// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageData.h"

/**
 * 
 */
class CollisionEvent
{
public:
	CollisionEvent(std::shared_ptr<FuselageData> Fuselage);
	virtual ~CollisionEvent() = 0 {};

	virtual bool Collision(AActor* Actor) = 0;

private:
	CollisionEvent() = delete;

	std::shared_ptr<FuselageData> m_fuselage;

};

TSet<AActor*> GetOverlapActors(AActor* Target);