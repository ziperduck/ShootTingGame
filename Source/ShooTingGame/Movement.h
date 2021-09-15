// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Action.h"
#include "Fuselage.h"

/**
 * 동서남북으로 움직이는 값을 전달하는 (XXX)Move 물체의 움직임을 제어한다.
 */

class EastMove : public IAction
{
public:

	 virtual void Execute_Implementation(TSubclassOf<UFuselage>  Fuselage) override;
};
class WestMove : public IAction
{

public:

	virtual void Execute_Implementation(TSubclassOf<UFuselage>  Fuselage) override;

};
class SouthMove : public IAction
{
public:

	virtual void Execute_Implementation(TSubclassOf<UFuselage>  Fuselage) override;

};
class NorthMove : public IAction
{
public:

	virtual void Execute_Implementation(TSubclassOf<UFuselage>  Fuselage) override;

};


class Shooting : public IAction
{
public:
	
	virtual void Execute_Implementation(TSubclassOf<UFuselage>  Fuselage) override;

};