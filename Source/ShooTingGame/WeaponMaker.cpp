// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponMaker.h"

#include "TestBullet.h"
#include "TestLaserBeam.h"

namespace WeaponMaker {

	WeaponStruct* GetFireBall()
	{
		static WeaponStruct* FireBall = new WeaponStruct(ATestBullet::StaticClass(), 1, 1.0f, 10.0f, FVector::OneVector);
		return FireBall;
	}

	WeaponStruct* GetBulletLvel_1()
	{
		static UClass* WeaponClass = Cast<UClass>(StaticLoadClass(UObject::StaticClass(), NULL,
			TEXT("Class'/Game/Blueprint/BP_TestBullet.BP_TestBullet_C'")));
		static WeaponStruct* Bullet = new WeaponStruct(WeaponClass, 1, 1.0f, 10.0f, FVector::OneVector);
		return Bullet;
	}
	WeaponStruct* GetBulletLvel_2()
	{
		static WeaponStruct* Bullet = new WeaponStruct(ATestBullet::StaticClass(), 2, 1.0f, 10.0f, FVector::OneVector);
		return Bullet;
	}

	WeaponStruct* GetLaserBeamLvel_1()
	{
		static WeaponStruct* LaserBeam = new WeaponStruct(ATestLaserBeam::StaticClass(), 1, 1.0f, 1.0f, FVector::OneVector);
		return LaserBeam;
	}
	WeaponStruct* GetLaserBeamLvel_2()
	{
		static WeaponStruct* LaserBeam = new WeaponStruct(ATestLaserBeam::StaticClass(),2, 1.0f, 1.0f, FVector(3.0f,3.0f,3.0f));
		return LaserBeam;
	}

}
