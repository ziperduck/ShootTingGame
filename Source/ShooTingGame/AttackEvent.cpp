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
			//�浹�� ��ü�� Fuselage���� Ȯ���Ѵ�.
			IFuselageBaseData* CollisionActor = Cast<IFuselageBaseData>(Actor);
			if (!CollisionActor)
			{
				continue;
			}

			std::shared_ptr<FuselageData> CollisionFuselage = CollisionActor->GetBaseData();

			//�浹�� Fuselage�� �������� ����ϴ��� Ȯ���Ѵ�.
			if (m_fuselage->GetUnion().MatchUnion(CollisionFuselage->GetUnion()))
			{
				CollisionFuselage->AddHP(-m_fuselage->GetStatus().GetAttackPower());
			}
		}


		return true;
	}
	return false;
}
