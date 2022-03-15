// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathCommand.h"

#include <random>

namespace DeathCommand {
	Command& FuselageRemove::getinstance()
	{
		static Command* instance = new FuselageRemove;
		return *instance;
	}
	bool FuselageRemove::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("FuselageRemove execute function in Parameter Character is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("FuselageRemove execute"));

		Character->Death();
		return true;
	}

	Command& EnemyDie::getinstance()
	{
		static Command* instance = new EnemyDie;
		return *instance;
	}

	bool EnemyDie::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("EnemyDie execute function in Parameter Character is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("EnemyDie execute"));

		Character->Death();
		return true;
	}
	Command& PlayerDie::getinstance()
	{
		static Command* instance = new PlayerDie;
		return *instance;
	}
	bool PlayerDie::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("PlayerDie execute function in Parameter Character is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("PlayerDie execute"));

		Character->Death();
		return false;
	}
}