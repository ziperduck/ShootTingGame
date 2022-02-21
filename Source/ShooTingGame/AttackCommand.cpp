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

		//출돌을 했는지 확인한다.
		if (!Character->GetActor()->GetActorEnableCollision())
		{
			return false;
		}

		TSet<AActor*> OverlapActors;
		Character->GetActor()->GetOverlappingActors(OverlapActors);

		for (auto Actor : OverlapActors)
		{
			//충돌한 객체가 Fuselage인지 확인한다.
			IFuselageBaseData* OverlapData = Cast<IFuselageBaseData>(Actor);
			if (!OverlapData)
			{
				continue;
			}

			std::shared_ptr<FuselageCharacter> OverlapFuselage = OverlapData->GetBaseData();

			//충돌한 Fuselage가 데미지를 줘야하는지 확인한다.
			if (Character->GetUnion() & OverlapFuselage->GetCollision())
			{
				UE_LOG(LogTemp, Log, TEXT("other fuselage Attack"));
				OverlapFuselage->AddHP(-Character->GetAttackPower());
			}
		}

		return false;
	}
}