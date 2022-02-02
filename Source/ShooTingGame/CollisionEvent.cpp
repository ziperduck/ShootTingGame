// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionEvent.h"

CollisionEvent::CollisionEvent(std::shared_ptr<FuselageData> Fuselage)
:m_fuselage(Fuselage){}

TSet<AActor*> SearchOverlapActors(AActor* Target)
{
	if (!Target->GetActorEnableCollision())
	{
		return TSet<AActor*>();
	}

	TSet<AActor*> OverlapActiors;
	Target->GetOverlappingActors(OverlapActiors);
    return OverlapActiors;
}
