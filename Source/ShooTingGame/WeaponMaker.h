// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponStruct.h"

/**
 * 무기의 레벨은 template를 이용해서 타입을 One Two이런식으로 넣는다면 어떨까.
 */

//무기를 만드는 함수들
namespace WeaponMaker {

	WeaponStruct* GetFireBall();

	WeaponStruct* GetBulletLvel_1();
	WeaponStruct* GetBulletLvel_2();

	WeaponStruct* GetLaserBeamLvel_1();
	WeaponStruct* GetLaserBeamLvel_2();

}
