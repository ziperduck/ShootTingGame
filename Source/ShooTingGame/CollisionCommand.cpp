// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionCommand.h"

#include "FuselageBaseData.h"

#include "WeaponStruct.h"

#include "FuselageUnion.h"

//fuselagecharacter�� �����Ͱ� �����ϴ��� Ȯ���ϰ� �����ϸ� overlap�� ĳ���͸� �����Ѵ�.
TSet<AActor*> ReturnOverlapCharacter(std::shared_ptr<FuselageCharacter> Character);

namespace CollisionCommand {
	
	Command& CollisionAttack::getinstance()
	{
		static Command* instance = new CollisionAttack;
		return *instance;
	}

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
			if (Character->GetCollision() & OverlapFuselage->GetUnion())
			{
				UE_LOG(LogTemp, Log, TEXT("other fuselage Attack"));
				OverlapFuselage->AddHP(-Character->GetAttackPower());
			}
		}

		return true;
	}

	Command& CollisionHeal::getinstance()
	{
		static Command* instance = new CollisionHeal;
		return *instance;
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

	Command& CollisionChangeWeapon::getinstance()
	{
		static Command* instance = new CollisionChangeWeapon;
		return *instance;
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

			//�浹�� Fuselage�� ���⸦ �ٲ۴�.
			if (Character->GetUnion() & OverlapFuselage->GetCollision())
			{
				WeaponStruct* ChangerWeapon = Character->GetWeapon();
				WeaponStruct* TargetWeapon = OverlapFuselage->GetWeapon();

				if (TargetWeapon == nullptr)
				{
					UE_LOG(LogTemp, Log, TEXT("other fuselage Change Weapon"));
					OverlapFuselage->ChangeWeapon(ChangerWeapon);
				}
				else if(ChangerWeapon->GetUClass() != TargetWeapon->GetUClass())
				{
					UE_LOG(LogTemp, Log, TEXT("other fuselage Change Weapon"));
					OverlapFuselage->ChangeWeapon(ChangerWeapon);
				}
				else
				{
					UE_LOG(LogTemp, Log, TEXT("other fuselage Upgrade Weapon"));
					OverlapFuselage->ChangeWeapon(TargetWeapon->GetUpgradeWeapon());
				}

			}
		}

		return true;
	}

	Command& CollisionInvincibilityOn::getinstance()
	{
		static Command* Instance = new CollisionInvincibilityOn;
		return *Instance;
	}

	bool CollisionInvincibilityOn::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("CollisionInvincibilityOn Character is nullptr"));
		switch (Character->GetUnion())
		{
		case static_cast<int8>(EUnionBinary::PLAYER_BINARY):
			Character->ChangeUnion(FuselageUnion::PlayerInvincibilityUnion());
			break;
		default:
			break;
		}
		return true;

	}
	Command& CollisionInvincibilityOff::getinstance()
	{
		static Command* Instance = new CollisionInvincibilityOff;
		return *Instance;
	}

	bool CollisionInvincibilityOff::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("CollisionInvincibilityOff Character is nullptr"));
		switch (Character->GetUnion())
		{
		case static_cast<int8>(EUnionBinary::PLAYER_INVINCIBILITY_BINARY):
			Character->ChangeUnion(FuselageUnion::PlayerUnion());
			break;
		default:
			break;
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