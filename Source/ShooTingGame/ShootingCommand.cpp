// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingCommand.h"

#include "FuselageBaseData.h"

namespace ShootingCommand {
	Command& ShotAttack::getinstance()
	{
		static Command* instance = new ShotAttack;
		return *instance;
	}

	bool ShotAttack::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character != nullptr, TEXT("ShotAttack execte Character is nullptr"));

		Character->Shooting();
		return true;
	}
}
