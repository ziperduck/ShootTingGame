// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Command.h"

 /*
 * �����̴� ��Ȳ�� �̺�Ʈ��
 */
namespace AttackCommand {

	// �ε��� ��뿡�� �������� �ִ� �̺�Ʈ
	class CollisionAttack : public Command
	{
	public:
		CollisionAttack() {};
		virtual ~CollisionAttack() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

}