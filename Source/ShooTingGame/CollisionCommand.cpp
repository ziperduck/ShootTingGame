// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionCommand.h"
#include "FuselageBaseData.h"

//fuselagecharacter�� �����Ͱ� �����ϴ��� Ȯ���ϰ� �����ϸ� overlap�� ĳ���͸� �����Ѵ�.
TSet<AActor*> ReturnOverlapCharacter(std::shared_ptr<FuselageCharacter> Character);

namespace CollisionCommand {

	bool CollisionAttack::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		TSet<AActor*> OverlapActors = ReturnOverlapCharacter(Character);

		for (auto Actor : OverlapActors)
		{
			//�浹�� ��ü�� Fuselage���� Ȯ���Ѵ�.
			IFuselageBaseData* OverlapData = Cast<IFuselageBaseData>(Actor);
			if (!OverlapData)
			{
				continue;
			}

			std::shared_ptr<FuselageCharacter> OverlapFuselage = OverlapData->GetBaseData();

			UE_LOG(LogTemp, Log, TEXT("Character Union %d & %d = %d"), Character->GetUnion(), OverlapFuselage->GetCollision(), Character->GetUnion() & OverlapFuselage->GetCollision());

			
			//�浹�� Fuselage�� �������� ����ϴ��� Ȯ���Ѵ�.
			if (Character->GetUnion() & OverlapFuselage->GetCollision())
			{
				UE_LOG(LogTemp, Log, TEXT("other fuselage Attack"));
				OverlapFuselage->AddHP(-Character->GetAttackPower());
			}
		}

		return true;
	}
	bool CollisionHeal::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		TSet<AActor*> OverlapActors = ReturnOverlapCharacter(Character);

		for (auto Actor : OverlapActors)
		{
			//�浹�� ��ü�� Fuselage���� Ȯ���Ѵ�.
			IFuselageBaseData* OverlapData = Cast<IFuselageBaseData>(Actor);
			if (!OverlapData)
			{
				continue;
			}

			std::shared_ptr<FuselageCharacter> OverlapFuselage = OverlapData->GetBaseData();

			//�浹�� Fuselage�� ü���� ȸ���Ѵ�.
			if (Character->GetUnion() & OverlapFuselage->GetCollision())
			{
				UE_LOG(LogTemp, Log, TEXT("other fuselage Heal"));
				OverlapFuselage->AddHP(Character->GetAttackPower());
			}
		}

		return true;
	}
	bool CollisionChangeWeapon::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		TSet<AActor*> OverlapActors = ReturnOverlapCharacter(Character);

		for (auto Actor : OverlapActors)
		{
			//�浹�� ��ü�� Fuselage���� Ȯ���Ѵ�.
			IFuselageBaseData* OverlapData = Cast<IFuselageBaseData>(Actor);
			if (!OverlapData)
			{
				continue;
			}

			std::shared_ptr<FuselageCharacter> OverlapFuselage = OverlapData->GetBaseData();

			//�浹�� ���⸦ �ٲ۴�.
			if (Character->GetUnion() & OverlapFuselage->GetCollision())
			{
				UE_LOG(LogTemp, Log, TEXT("other fuselage Heal"));
			}
		}

		return true;
	}
}

TSet<AActor*> ReturnOverlapCharacter(std::shared_ptr<FuselageCharacter> Character)
{
	checkf(Character.get() != nullptr, TEXT(" Overlap Fuselage is nullptr"));
	UE_LOG(LogTemp, Log, TEXT("CollisionHeal execute"));

	const AActor* CharacterActor = Character->GetActor();

	checkf(CharacterActor != nullptr, TEXT("Overlap Actor is nullptr"));

	//�⵹�� �ߴ��� Ȯ���Ѵ�.
	if (!CharacterActor->GetActorEnableCollision())
	{
		return TSet<AActor*>();
	}

	TSet<AActor*> OverlapActors;
	CharacterActor->GetOverlappingActors(OverlapActors);

	return OverlapActors;
}