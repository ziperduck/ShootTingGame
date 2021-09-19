// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Action.h"
#include "EnumPack.h"
#include "Fuselage.h"

/**
 * 동서남북으로 움직이는 값을 전달하는 (XXX)Move 물체의 움직임을 제어한다.
 * 어떻게 접근을 막을것인가?
 */

IAction* ChangeAction(EVariousAction Action);

class EastMove : public IAction
{
public:

	 virtual void Execute(TSubclassOf<UFuselage> Target) override;
};
class WestMove : public IAction
{

public:

	virtual void Execute(TSubclassOf<UFuselage> Target) override;

};
class SouthMove : public IAction
{
public:

	virtual void Execute(TSubclassOf<UFuselage> Target) override;

};
class NorthMove : public IAction
{
public:

	virtual void Execute(TSubclassOf<UFuselage> Target) override;

};


class Shooting : public IAction
{
public:
	
	virtual void Execute(TSubclassOf<UFuselage> Target) override;

};