// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFinishiMoveCommand.h"

#include "FuselageBaseData.h"

#include "FuselageCharacter.h"

#include <Engine/Classes/Kismet/GameplayStatics.h>

namespace PlayerFinishiMoveCommand {

	PlayerCommand& SpecialBoom::getinstance()
	{
		static PlayerCommand* instance = new SpecialBoom;
		return *instance;
	}

	bool SpecialBoom::execute(std::shared_ptr<PlayerCharacterData> Player)
	{
		checkf(Player.get() != nullptr, TEXT("SpecialBoom::execute in Player is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("into the SpecialBoom::execute"));

		if (Player->GetSuperBoomNum() == 0)
		{
			return false;
		}

		//월드에있는 모든 엑터를 다 받고
		TArray<AActor*> AllActor;
		UGameplayStatics::GetAllActorsOfClass(Player->GetPlayerActor()->GetWorld(), AActor::StaticClass(), AllActor);

		//받은 엑터들중에 적들과 적들의 무기들을 찾아서 데미지를 입힌다.
		for ( auto i : AllActor )
		{
			checkf(i != nullptr, TEXT("All actor element is nullptr"));

			IFuselageBaseData* BaseData = Cast<IFuselageBaseData>(i);
			if (BaseData == nullptr)
			{
				continue;
			}

			std::shared_ptr<FuselageCharacter> Fuselage = BaseData->GetBaseData();
			checkf(i != nullptr, TEXT("All actor element fuselage is nullptr"));
		
			UE_LOG(LogTemp, Log, TEXT("Fuselage Union %d"), Fuselage->GetUnion());
			switch (Fuselage->GetUnion())
			{
			case static_cast<int8>(EUnionBinary::ENEMY_BINARY):
			case static_cast<int8>(EUnionBinary::ENEMY_WEAPON_BINARY):

				Fuselage->AddHP(-1000.0f);

				break;
			default:
				break;
			}
		
		}

		//폭탄을 소비한다.
		Player->UseSuperBoom();

		return true;
	}

}