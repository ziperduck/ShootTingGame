// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackCommand.h"
#include "FuselageBaseData.h"

namespace AttackCommand {

	bool CollisionAttack::execute(std::shared_ptr<FuselageCharacter> Character)
	{

		checkf(Character.get() != nullptr, TEXT("CollisionAttack execute function in Parameter Character is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("CollisionAttack execute"));

		if (Character->GetActor() == nullptr)
		{
			return false;
		}

		//�⵹�� �ߴ��� Ȯ���Ѵ�.
		if (!Character->GetActor()->GetActorEnableCollision())
		{
			return false;
		}

		TSet<AActor*> OverlapActors;
		Character->GetActor()->GetOverlappingActors(OverlapActors);

		for (auto Actor : OverlapActors)
		{
			//�浹�� ��ü�� Fuselage���� Ȯ���Ѵ�.
			IFuselageBaseData* OverlapData = Cast<IFuselageBaseData>(Actor);
			if (!OverlapData)
			{
				continue;
			}

			std::shared_ptr<FuselageCharacter> OverlapFuselage = OverlapData->GetBaseData();

			//�浹�� Fuselage�� �������� ����ϴ��� Ȯ���Ѵ�.
			if (Character->GetUnion() & OverlapFuselage->GetCollision())
			{
				UE_LOG(LogTemp, Log, TEXT("other fuselage Attack"));
				OverlapFuselage->AddHP(-Character->GetAttackPower());
			}
		}

		return false;
	}
}