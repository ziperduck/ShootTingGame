// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "WeaponStruct.h"

/**
 * �÷��̾ ����ϴ� ������� ����
 */

constexpr float ONE_TICK();

namespace PlayerWeapon {

	//�Ѿ� ����
	class BulletLvel_1 : public WeaponStruct
	{
	public:
		BulletLvel_1();
		virtual ~BulletLvel_1() final;

		virtual WeaponStruct* GetUpgradeWeapon() final;

		virtual void PressedShoot(AActor* Gunner) final;

		virtual void ReleaseShoot(AActor* Gunner) final;

	protected:

		//������ �����͸� ���� Actor�� �����Ѵ�.
		virtual void CreateWeapon(AActor* Gunner) final;

	};

	class BulletLvel_2 : public WeaponStruct
	{
	public:
		BulletLvel_2();
		virtual ~BulletLvel_2() final;

		virtual WeaponStruct* GetUpgradeWeapon() final;

		virtual void PressedShoot(AActor* Gunner) final;

		virtual void ReleaseShoot(AActor* Gunner) final;

	protected:

		//������ �����͸� ���� Actor�� �����Ѵ�.
		virtual void CreateWeapon(AActor* Gunner) final;

	private:
		const int32 m_bullet_number;
	};


	class LaserBeamLvel_1 : public WeaponStruct
	{
	public:
		LaserBeamLvel_1();
		virtual ~LaserBeamLvel_1() final;

		virtual WeaponStruct* GetUpgradeWeapon() final;

		virtual void PressedShoot(AActor* Gunner) final;

		virtual void ReleaseShoot(AActor* Gunner) final;

	protected:

		//������ �����͸� ���� Actor�� �����Ѵ�.
		virtual void CreateWeapon(AActor* Gunner) final;

	private:

		//�⸦ ������ �ִ� �Ѱ�ð�
		const int32 m_lifespan_tick_limit;
	};

	//������ ����
	class LaserBeamLvel_2 : public WeaponStruct
	{
	public:
		LaserBeamLvel_2();
		virtual ~LaserBeamLvel_2() final;

		virtual WeaponStruct* GetUpgradeWeapon() final;

		virtual void PressedShoot(AActor* Gunner) final;

		virtual void ReleaseShoot(AActor* Gunner) final;

	protected:

		//������ �����͸� ���� Actor�� �����Ѵ�.
		virtual void CreateWeapon(AActor* Gunner) final;

	private:

		//�⸦ ������ �ִ� �Ѱ�ð�
		const int32 m_lifespan_tick_limit;
	};


}