// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "PlayerCommand.h"

/**
 * 
 */
namespace PlayerFinishiMoveCommand
{
	class SpecialBoom : public PlayerCommand
	{
	public:
		virtual ~SpecialBoom() final {};

		static PlayerCommand& getinstance();

		virtual bool execute(std::shared_ptr<PlayerCharacterData> Player) final;

	private:
		SpecialBoom() {};



	};

};
