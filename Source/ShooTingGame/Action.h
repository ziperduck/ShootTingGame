// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <memory>

/**
 *
 */

class IFuselage;

//모든 행동들의 기본이 되는 IAction 움직이는 물체의 행동들은 모두 IAction에서 파생된다.
class IAction
{
public:
	IAction(){}
	virtual ~IAction() = 0 {}

public:

	virtual void execute(IFuselage*) = 0;

};
