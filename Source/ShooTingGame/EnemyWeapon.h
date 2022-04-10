// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "WeaponStruct.h"

#include <memory>
/**
 * 
 */
namespace EnemyWeapon {

	//총알 무기
	class FireBallLvel_1 : public WeaponStruct, public std::enable_shared_from_this<FireBallLvel_1>
	{
	public:
		FireBallLvel_1();
		virtual ~FireBallLvel_1() final;

		//무기의 데이터를 토대로 Actor를 생성한다.
		virtual void CreateWeapon(AActor* Gunner) final;

		virtual std::shared_ptr<WeaponStruct> GetUpgradeWeapon() final;

		virtual void PressedShoot(AActor* Gunner) final;

		virtual void ReleaseShoot(AActor* Gunner) final;
	};
}