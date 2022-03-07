// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command.h"

/*
* 죽는 상황의 이벤트들
*/
namespace DeathCommand {

	// 죽는 이벤트
	class FuselageRemove : public Command {
	public:
		FuselageRemove() {};
		virtual ~FuselageRemove() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//적이 죽는경우
	class EnemyDie : public Command {
	public:
		EnemyDie() {};
		virtual ~EnemyDie() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};
}
