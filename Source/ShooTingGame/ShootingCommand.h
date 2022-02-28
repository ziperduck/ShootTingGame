// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Command.h"

/**
 * 
 */
namespace ShootingCommand {

	// 부딪힌 상대에게 데미지를 주는 이벤트
	class ShotAttack : public Command
	{
	public:
		ShotAttack() {};
		virtual ~ShotAttack() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};
}