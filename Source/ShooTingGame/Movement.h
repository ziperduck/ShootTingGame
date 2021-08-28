// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Action.h"
#include "CoreMinimal.h"

/**
 * 
 */

class IObject;

class EastMove : IAction
{
public:
	EastMove();
	virtual ~EastMove() override;
public:

	virtual void execute(std::shared_ptr<IObject>) override;
};
class WestMove : IAction
{
public:
	WestMove();
	virtual~WestMove()override;

public:

	virtual void execute(std::shared_ptr<IObject>) override;

};
class SouthMove : IAction
{
public:
	SouthMove();
	virtual ~SouthMove() override;
public:

	virtual void execute(std::shared_ptr<IObject>) override;

};
class NorthMove : IAction
{
public:
	NorthMove();
	virtual ~NorthMove() override;
public:

	virtual void execute(std::shared_ptr<IObject>) override;

};

