// Fill out your copyright notice in the Description page of Project Settings.


#include "FuselageAttack.h"
#include "FuselageBaseData.h"

namespace AttackEvent {

	bool FuselageAttack::execute(std::shared_ptr<FuselageCharacter> Character)
	{

		if (Character->GetActor() == nullptr)
		{
			return false;
		}

		//�⵹�� �ߴ��� Ȯ���Ѵ�.
		if (!Character->GetActor()->GetActorEnableCollision())
		{
			return false;
		}



		UE_LOG(LogTemp, Log, TEXT("In FuselageAttack"));

		TSet<AActor*> OverlapActors;
		Character->GetActor()->GetOverlappingActors(OverlapActors);

		for (auto Actor : OverlapActors)
		{
			//�浹�� ��ü�� Fuselage���� Ȯ���Ѵ�.
			IFuselageBaseData* OverlapData = Cast<IFuselageBaseData>(Actor);
			if (!OverlapData)
			{
				UE_LOG(LogTemp, Log, TEXT("executeActor cast fail"));
				continue;
			}

			std::shared_ptr<FuselageCharacter> OverlapFuselage = OverlapData->GetBaseData();

			//�浹�� Fuselage�� �������� ����ϴ��� Ȯ���Ѵ�.
			UE_LOG(LogTemp, Log, TEXT("GetUnion & GetCollision"));
			if (Character->GetUnion() & OverlapFuselage->GetCollision())
			{
				UE_LOG(LogTemp, Log, TEXT("other fuselage Attack"));
				OverlapFuselage->AddHP(-Character->GetAttackPower());
			}
		}

		return false;
	}
}