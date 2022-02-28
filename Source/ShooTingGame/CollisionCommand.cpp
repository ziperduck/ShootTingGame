// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionCommand.h"
#include "FuselageBaseData.h"

//fuselagecharacter의 데이터가 존재하는지 확인하고 존재하면 overlap된 캐릭터를 리턴한다.
TSet<AActor*> ReturnOverlapCharacter(std::shared_ptr<FuselageCharacter> Character);

namespace CollisionCommand {

	bool CollisionAttack::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		TSet<AActor*> OverlapActors = ReturnOverlapCharacter(Character);

		for (auto Actor : OverlapActors)
		{
			//충돌한 객체가 Fuselage인지 확인한다.
			IFuselageBaseData* OverlapData = Cast<IFuselageBaseData>(Actor);
			if (!OverlapData)
			{
				continue;
			}

			std::shared_ptr<FuselageCharacter> OverlapFuselage = OverlapData->GetBaseData();

			UE_LOG(LogTemp, Log, TEXT("Character Union %d & %d = %d"), Character->GetUnion(), OverlapFuselage->GetCollision(), Character->GetUnion() & OverlapFuselage->GetCollision());

			
			//충돌한 Fuselage가 데미지를 줘야하는지 확인한다.
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
			//충돌한 객체가 Fuselage인지 확인한다.
			IFuselageBaseData* OverlapData = Cast<IFuselageBaseData>(Actor);
			if (!OverlapData)
			{
				continue;
			}

			std::shared_ptr<FuselageCharacter> OverlapFuselage = OverlapData->GetBaseData();

			//충돌한 Fuselage가 체력을 회복한다.
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
			//충돌한 객체가 Fuselage인지 확인한다.
			IFuselageBaseData* OverlapData = Cast<IFuselageBaseData>(Actor);
			if (!OverlapData)
			{
				continue;
			}

			std::shared_ptr<FuselageCharacter> OverlapFuselage = OverlapData->GetBaseData();

			//충돌한 무기를 바꾼다.
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

	//출돌을 했는지 확인한다.
	if (!CharacterActor->GetActorEnableCollision())
	{
		return TSet<AActor*>();
	}

	TSet<AActor*> OverlapActors;
	CharacterActor->GetOverlappingActors(OverlapActors);

	return OverlapActors;
}