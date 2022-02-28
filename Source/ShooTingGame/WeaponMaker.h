// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponStruct.h"

/**
 * ������ ������ template�� �̿��ؼ� Ÿ���� One Two�̷������� �ִ´ٸ� ���.
 */

//���⸦ ����� �Լ���
namespace WeaponMaker {

	WeaponStruct* GetFireBall();

	WeaponStruct* GetBulletLvel_1();
	WeaponStruct* GetBulletLvel_2();

	WeaponStruct* GetLaserBeamLvel_1();
	WeaponStruct* GetLaserBeamLvel_2();

}
