// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <memory>
#include "CoreMinimal.h"

/**
 *
 */

const FVector& CalculationRatioSpeed(const FVector& Ratio);

class IObject;

class IAction
{
public:
	IAction(){}
	virtual ~IAction() = 0 {}

private:

public:

	virtual void execute(std::shared_ptr<IObject>) = 0;

};
