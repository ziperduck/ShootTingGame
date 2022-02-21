// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Command.h"

 /*
 * 움직이는 상황의 이벤트들
 */
namespace AttackCommand {

	// 부딪힌 상대에게 데미지를 주는 이벤트
	class CollisionAttack : public Command
	{
	public:
		CollisionAttack() {};
		virtual ~CollisionAttack() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

}