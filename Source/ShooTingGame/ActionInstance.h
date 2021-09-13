// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Movement.h"
#include "CoreMinimal.h"

/**
 * 
 */
//모든 액션의 인스턴스 값을 가진 클래스
class SHOOTINGGAME_API ActionInstance
{
public:
	ActionInstance(){}
	~ActionInstance(){}

	static TScriptInterface<IAction>  GetEastMove(){
		return nullptr;
	}
	static TScriptInterface<IAction>  GetWestMove() {
		return nullptr;
	}
	static TScriptInterface<IAction>  GetNorthMove() {
		return nullptr;
	}
	static TScriptInterface<IAction>  GetSouthMove() {
		return nullptr;
	}
	static TScriptInterface<IAction>  GetShoot() {
		return nullptr;
	}
};
