// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Action.h"

/**
 * 동서남북으로 움직이는 값을 전달하는 (XXX)Move 물체의 움직임을 제어한다.
 */

class IFuselage;

class EastMove : public IAction
{
public:

	 virtual void execute_Implementation(IFuselage* Fuselage) override;
};
class WestMove : public IAction
{

public:

	virtual void execute_Implementation(IFuselage* Fuselage) override;

};
class SouthMove : public IAction
{
public:

	virtual void execute_Implementation(IFuselage* Fuselage) override;

};
class NorthMove : public IAction
{
public:

	virtual void execute_Implementation(IFuselage* Fuselage) override;

};


class Shooting : public IAction
{
public:

	virtual void execute_Implementation(IFuselage* Fuselage) override;

};