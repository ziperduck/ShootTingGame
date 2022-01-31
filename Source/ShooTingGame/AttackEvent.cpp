// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackEvent.h"

AttackEvent::AttackEvent(std::shared_ptr<FuselageData> Fuselage)
	:CollisionEvent(Fuselage){}

AttackEvent::~AttackEvent()
{
}

bool AttackEvent::Collision(AActor* Actor)
{
	if (Actor != nullptr)
	{
		TSet<AActor*> OverlapActors;
		Actor->GetOverlappingActors(OverlapActors);

		return true;
	}
	return false;
}
