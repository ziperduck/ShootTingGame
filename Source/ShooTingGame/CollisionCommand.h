// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Command.h"

 /*
 * 움직이는 상황의 이벤트들
 */
namespace CollisionCommand {

	// 부딪힌 상대에게 데미지를 주는 이벤트
	class CollisionAttack : public Command
	{
	public:
		virtual ~CollisionAttack() final {};

		static Command& getinstance();

	private:
		CollisionAttack() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//부딪히면 힐을 주는 데이터 이벤트 힐팩은 공격력이 치유력이다.
	class CollisionHeal : public Command
	{
	public:
		virtual~CollisionHeal() final{};

		static Command& getinstance();

	private:
		CollisionHeal() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};

	//부딪히면 부딪힌 대상의 무기를 교체한다. 만약 같은 무기일경우 업그레이드 시킨다.
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