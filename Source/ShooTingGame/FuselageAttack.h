// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "FuselageBehavior.h"
#include "FuselageData.h"

#include <memory>

/**
 * �ε��� ����� �����ϴ� �̺�Ʈ 
 */

namespace AttackEvent {

	class FuselageAttack : public FuselageBehavior
	{
	public:
		FuselageAttack() {};
		virtual ~FuselageAttack() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

}