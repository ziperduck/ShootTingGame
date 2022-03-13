// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnumPack.h"
#include "FuselageCharacter.h"


/*상태를 입력하는 enum
*/
enum class EInputBehavior {
	IDLE = 0,
	LEFT_MOVE,
	RIGHT_MOVE,
	FORWORLD_MOVE,
	BACKWORLD_MOVE,
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

	virtual IFuselageState* HandleInput(FuselageCharacter& Fuselage, EInputBehavior Input) = 0;
	virtual void Update(FuselageCharacter& Fuselage) = 0;
};
