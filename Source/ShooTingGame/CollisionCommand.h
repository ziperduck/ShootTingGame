// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Command.h"

 /*
 * �����̴� ��Ȳ�� �̺�Ʈ��
 */
namespace CollisionCommand {

	// �ε��� ��뿡�� �������� �ִ� �̺�Ʈ
	class CollisionAttack : public Command
	{
	public:
		CollisionAttack() {};
		virtual ~CollisionAttack() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//�ε����� ���� �ִ� ������ �̺�Ʈ ������ ���ݷ��� ġ�����̴�.
	class CollisionHeal : public Command
	{
	public:
		CollisionHeal() {};
		virtual~CollisionHeal() final{};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};

	//�ε����� ���� �ִ� ������ �̺�Ʈ ������ ���ݷ��� ġ�����̴�.
	class CollisionChangeWeapon : public Command
	{
	public:
		CollisionChangeWeapon() {};
		virtual~CollisionChangeWeapon() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};
}