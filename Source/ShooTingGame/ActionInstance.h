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

	static std::shared_ptr<IAction> GetEastMove(){
		static std::shared_ptr<IAction> East = std::make_shared<EastMove>();
		return East;
	}
	static std::shared_ptr<IAction> GetWestMove() {
		static std::shared_ptr<IAction> West = std::make_shared<WestMove>();
		return West;
	}
	static std::shared_ptr<IAction> GetNorthMove() {
		static std::shared_ptr<IAction> North = std::make_shared<NorthMove>();
		return North;
	}
	static std::shared_ptr<IAction> GetSouthMove() {
		static std::shared_ptr<IAction> South = std::make_shared<SouthMove>();
		return South;
	}
};
