// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Command.h"

/**
 * ���� ��� Ŀ�ǵ�
 */
namespace ShootingCommand {

	// �ε��� ��뿡�� �������� �ִ� �̺�Ʈ
	class ShotAttack : public Command
	{
	public:
		ShotAttack() {};
		virtual ~ShotAttack() final {};

		static Command& getinstance();

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};
}