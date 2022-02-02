// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageBehavior.h"
#include "CollisionEvent.h"

/**
* Actor의 충돌 이벤트를 실행시키는 클래스
 */
class FuselageCollision : public FuselageBehavior
{
public:
	FuselageCollision(std::shared_ptr<CollisionEvent> Event);
	virtual ~FuselageCollision() final;

	virtual bool execute(AActor* Actor) final;
private:

	FuselageCollision() = delete;

private:

	std::shared_ptr<CollisionEvent> m_collision_event;
	
};
