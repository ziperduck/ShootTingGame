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
		FuselageRemove() {};
		virtual ~FuselageRemove() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//���� �״°��
	class EnemyDie : public Command {
	public:
		EnemyDie() {};
		virtual ~EnemyDie() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};
}