// Fill out your copyright notice in the Description page of Project Settings.


#include "FuselageAttack.h"


FuselageAttack::FuselageAttack(std::shared_ptr<CollisionEvent> Event)
	:m_collision_event(Event)
{
}

FuselageAttack::~FuselageAttack()
{
}

bool FuselageAttack::execute(AActor* Actor)
{
	if (m_collision_event != nullptr && Actor != nullptr)
	{
		return m_collision_event->Collision(Actor);
	}
	return false;
}