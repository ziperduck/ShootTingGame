// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <memory>
#include "FuselageData.h"

/**
 * 동체들의 기본 데이터를 가지고있는 함수들
 * 나중에는 fix값을 리턴하는 식으로 만들어야한다. 아니면 포인터를 리턴하는게 아니라 복사를 일어나게 해도 될것같다.
 * 
 * Fuselages를 호출하는 애들을 모두 
 */

namespace Fuselages
{
	//UFO(플레이어의 동체)의 fuselage값을 리턴한다.
	std::shared_ptr<FuselageData> GetUFO();

	//불쏘는 드레곤 fuselage값을 리턴한다
	std::shared_ptr<FuselageData> GetFireDragon();

	//돌진하는 드레곤 fuselage값을 리턴한다
	std::shared_ptr<FuselageData> GetRushDragon();

}