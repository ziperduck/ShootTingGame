// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageBehavior.h"
#include "CollisionEvent.h"

/**
* �浹�� ȣ���ϴ� �̺�Ʈ
 */
class FuselageAttack : public FuselageBehavior
{
public:
	FuselageAttack(std::shared_ptr<CollisionEvent> Event);
	virtual ~FuselageAttack() final;

	virtual bool execute(AActor* Actor) final;
private:

	FuselageAttack() = delete;

private:

	std::shared_ptr<CollisionEvent> m_collision_event;
	
};
