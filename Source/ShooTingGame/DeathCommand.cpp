// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathCommand.h"


namespace DeathCommand {

	bool FuselageRemove::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("FuselageRemove execute function in Parameter Character is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("FuselageRemove execute"));

		Character->Death();
		return true;
	}

	bool EnemyDie::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("EnemyDie execute function in Parameter Character is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("EnemyDie execute"));

		Character->Death();
		return true;
	}
}