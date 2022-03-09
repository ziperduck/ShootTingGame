// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "WeaponStruct.h"
/**
 * 
 */
namespace EnemyWeapon {

	//총알 무기
	class FireBallLvel_1 : public WeaponStruct
	{
	public:
		FireBallLvel_1();
		virtual ~FireBallLvel_1() final;

		//무기의 데이터를 토대로 Actor를 생성한다.
		virtual void CreateWeapon(AActor* Gunner) final;

		virtual WeaponStruct* GetUpgradeWeapon() final;

	};
}