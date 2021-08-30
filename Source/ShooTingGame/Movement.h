// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Action.h"
#include "CoreMinimal.h"

/**
 * 동서남북으로 움직이는 값을 전달하는 (XXX)Move 물체의 움직임을 제어한다.
 */

class IObject;

class EastMove : public IAction
{
public:
	EastMove();
	virtual ~EastMove() override;
public:

	virtual void execute(IObject*) override;
};
class WestMove : public IAction
{
public:
	WestMove();
	virtual~WestMove()override;

public:

	virtual void execute(IObject*) override;

};
class SouthMove : public IAction
{
public:
	SouthMove();
	virtual ~SouthMove() override;
public:

	virtual void execute(IObject*) override;

};
class NorthMove : public IAction
{
public:
	NorthMove();
	virtual ~NorthMove() override;
public:

	virtual void execute(IObject*) override;

};

