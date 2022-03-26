// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Command.h"

/**
 * ���� ��� Ŀ�ǵ�
 */
namespace ShootingCommand {

	//�ѽ�� Ű�� ������.
	class PressedShoot : public Command
	{
	public:
		virtual ~PressedShoot() final {};

		static Command& getinstance();

	private:
		PressedShoot() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//�ѽ�� Ű�� ����.
	class ReleaseShoot : public Command
	{
	public:
		virtual ~ReleaseShoot() final {};

		static Command& getinstance();

	private:
		ReleaseShoot() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};
}