// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageData.h"

/**
 * 
 */

namespace Fuselages
{
	//UFO(플레이어의 동체)의 fuselage값을 리턴한다.
	const FuselageData* GetUFO();

	//불쏘는 드레곤 fuselage값을 리턴한다
	const FuselageData* GetFireDragon();

	//돌진하는 드레곤 fuselage값을 리턴한다
	const FuselageData* GetRushDragon();

}