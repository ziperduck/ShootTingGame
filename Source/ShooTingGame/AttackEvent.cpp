// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackEvent.h"
#include "FuselageBaseData.h"

AttackEvent::AttackEvent(std::shared_ptr<FuselageData> Fuselage)
	:CollisionEvent(Fuselage){}

AttackEvent::~AttackEvent()
{
}

bool AttackEvent::Collision(AActor* Actor)
{
	if (Actor != nullptr)
	{
		TSet<AActor*> OverlapActors = SearchOverlapActors(Actor);

		for (auto Actor : OverlapActors)
		{
			//충돌한 객체가 Fuselage인지 확인한다.
			IFuselageBaseData* CollisionActor = Cast<IFuselageBaseData>(Actor);
			if (!CollisionActor)
			{
				continue;
			}

			std::shared_ptr<FuselageData> CollisionFuselage = CollisionActor->GetBaseData();

			//충돌한 Fuselage가 데미지를 줘야하는지 확인한다.
			if (m_fuselage->GetUnion().MatchUnion(CollisionFuselage->GetUnion()))
			{
				CollisionFuselage->AddHP(-m_fuselage->GetStatus().GetAttackPower());
			}
		}


		return true;
	}
	return false;
}
