// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageBehavior.h"
#include "FuselageData.h"
#include <memory>

/**
 * �ε��� ����� �����ϴ� �̺�Ʈ 
 */
class FuselageAttack : public FuselageBehavior
{
public:
	FuselageAttack(std::shared_ptr<FuselageData> Fuselage);
	FuselageAttack(const FuselageAttack& Temporary);
	virtual ~FuselageAttack() final;

	virtual bool execute(AActor* Actor) final;

private:

	std::shared_ptr<FuselageData> m_fuselage;

};
