// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "WeaponStruct.h"
/**
 * 
 */
namespace EnemyWeapon {

	//�Ѿ� ����
	class FireBallLvel_1 : public WeaponStruct
	{
	public:
		FireBallLvel_1();
		virtual ~FireBallLvel_1() final;

		//������ �����͸� ���� Actor�� �����Ѵ�.
		virtual void CreateWeapon(AActor* Gunner) final;

		virtual WeaponStruct* GetUpgradeWeapon() final;

	};
}