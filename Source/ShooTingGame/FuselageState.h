// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "EnumPack.h"

#include "Command.h"

#include <memory>

/*상태를 입력하는 enum
*/
enum class EInputBehavior {
	IDLE = 0,
	LEFT_MOVE,
	RIGHT_MOVE,
	FORWARD_MOVE,
	BACKWARD_MOVE,
	TRACKING_MOVE,
	COLLISION,
	SHOOTING
};

/*동체의 상태를 객체화한 클래스 
*/
class SHOOTINGGAME_API IFuselageState
{
public:
	IFuselageState() {};
	virtual ~IFuselageState() = 0{};

	//현재상태에 input을 받고 알맞는 다음행동을 리턴하는 함수
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) = 0;

	//현재상태에 입력된 이벤트를 실행하고 상태에 맞는 특정 행동을 하는 함수
	virtual IFuselageState* Update(std::shared_ptr<FuselageCharacter> Character) = 0;
	
	//상태에 들어설때 호출하는 함수
	virtual void Enter(std::shared_ptr<FuselageCharacter> Character) = 0;

protected:

	//입력된 모든 command를 실행시키고 비우는 일
	void m_knot_command(std::shared_ptr<FuselageCharacter> Character);

protected:

	std::queue<Command*> m_all_command;

	IFuselageState* m_update_state;
};
