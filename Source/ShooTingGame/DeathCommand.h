// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command.h"

/*
* �״� ��Ȳ�� �̺�Ʈ��
*/
namespace DeathCommand {

	// �״� �̺�Ʈ
	class FuselageRemove : public Command {
	public:
		virtual ~FuselageRemove() final {};

		static Command& getinstance();

	private:
		FuselageRemove() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//���� �״°��
	class EnemyDie : public Command {
	public:
		virtual ~EnemyDie() final {};

		static Command& getinstance();

	private:
		EnemyDie() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//���� �״°��
	class PlayerDie : public Command {
	public:
		virtual ~PlayerDie() final {};

		static Command& getinstance();

	private:
		PlayerDie() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};
}
