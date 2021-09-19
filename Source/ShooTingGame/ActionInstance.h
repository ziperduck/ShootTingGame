 //Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnumPack.h"
#include "Movement.h"
#include "CoreMinimal.h"


/**
 * 
 */

//various action의 종류에 따라 액션값을 반환하는 클래스
class ActionInstance
{
public:
	
	IAction* ChangeAction(EVariousAction Action) const;

private:
	//static EastMove* East;
	//static WestMove* West;
	//static SouthMove* South;
	//static NorthMove* North;
};
