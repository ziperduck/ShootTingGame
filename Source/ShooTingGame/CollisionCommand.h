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
		CollisionAttack() {};
		virtual ~CollisionAttack() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//부딪히면 힐을 주는 데이터 이벤트 힐팩은 공격력이 치유력이다.
	class CollisionHeal : public Command
	{
	public:
		CollisionHeal() {};
		virtual~CollisionHeal() final{};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};

	//부딪히면 힐을 주는 데이터 이벤트 힐팩은 공격력이 치유력이다.
	class CollisionChangeWeapon : public Command
	{
	public:
		CollisionChangeWeapon() {};
		virtual~CollisionChangeWeapon() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};
}