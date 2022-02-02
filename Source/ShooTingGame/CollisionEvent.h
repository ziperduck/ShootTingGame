// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageData.h"

/**
 * 충돌 이벤트
 */
class CollisionEvent
{
public:
	CollisionEvent(std::shared_ptr<FuselageData> Fuselage);
	virtual ~CollisionEvent() = 0 {};

	virtual bool Collision(AActor* Actor) = 0;

private:

	CollisionEvent() = delete;

protected:

	std::shared_ptr<FuselageData> m_fuselage;

};

TSet<AActor*> SearchOverlapActors(AActor* Target);