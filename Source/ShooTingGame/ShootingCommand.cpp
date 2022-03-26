// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingCommand.h"

#include "FuselageBaseData.h"

namespace ShootingCommand {
	Command& PressedShoot::getinstance()
	{
		static Command* instance = new PressedShoot;
		return *instance;
	}
	bool PressedShoot::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("PressedShoot::execute Chacter is nullptr"));

		Character->PressedShoot();

		return true;
	}
	Command& ReleaseShoot::getinstance()
	{
		static Command* instance = new ReleaseShoot;
		
		return *instance;
	}
	bool ReleaseShoot::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("ReleaseShoot::execute Chacter is nullptr"));

		Character->ReleaseShoot();

		return true;
	}
}
