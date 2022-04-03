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
		virtual ~CollisionAttack() final {};

		static Command& getinstance();

	private:
		CollisionAttack() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//�ε����� ���� �ִ� ������ �̺�Ʈ ������ ���ݷ��� ġ�����̴�.
	class CollisionHeal : public Command
	{
	public:
		virtual~CollisionHeal() final{};

		static Command& getinstance();

	private:
		CollisionHeal() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};

	//�ε����� �ε��� ����� ���⸦ ��ü�Ѵ�. ���� ���� �����ϰ�� ���׷��̵� ��Ų��.
	class CollisionChangeWeapon : public Command
	{
	public:
		virtual~CollisionChangeWeapon() final {};

		static Command& getinstance();

	private:
		CollisionChangeWeapon() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};

	class CollisionInvincibilityOn : public Command
	{
	public:
		virtual ~CollisionInvincibilityOn() final {};

		static Command& getinstance();

	private:
		CollisionInvincibilityOn() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};

	class CollisionInvincibilityOff : public Command
	{
	public:
		virtual ~CollisionInvincibilityOff() final {};

		static Command& getinstance();

	private:
		CollisionInvincibilityOff() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};

}