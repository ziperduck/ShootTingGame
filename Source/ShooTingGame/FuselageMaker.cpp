// Fill out your copyright notice in the Description page of Project Settings.


#include "FuselageMaker.h"

#include "TestPlayerWeapon.h"

#include "TestEnemyWeapon.h"

#include "FuselageUnion.h"

namespace FuselageMaker
{

	std::shared_ptr<FuselageData> GetUFO()
	{
		UE_LOG(LogTemp, Log, TEXT("GetUFO"));
		static FuselageStatus UFOStatus { 5.0f,1.0f, 2.0f };
		return std::make_shared<FuselageData>(new PlayerWeapon::LaserBeamLvel_1(),UFOStatus, FuselageUnion::PlayerUnion());
	}

	std::shared_ptr<FuselageData> GetFireDragon()
	{
		UE_LOG(LogTemp, Log, TEXT("GetFireDragon"));
		static FuselageStatus FireDragonStatus{ 1.0f,1.0f, 1.0f };
		return std::make_shared<FuselageData>(new PlayerWeapon::LaserBeamLvel_1(), FireDragonStatus, FuselageUnion::FireDragonUnion());
	}

	std::shared_ptr<FuselageData> GetRushDragon()
	{
		UE_LOG(LogTemp, Log, TEXT("GetRushDragon"));
		static FuselageStatus RushDragonStatus{ 1.0f,1.0f, 1.0f };
		return std::make_shared<FuselageData>(nullptr, RushDragonStatus, FuselageUnion::FireDragonUnion());
	}

	std::shared_ptr<FuselageData> GetBullet()
	{
		UE_LOG(LogTemp, Log, TEXT("GetRushDragon"));
		static FuselageStatus BulletStatus{ 1.0f,3.0f, 0.0f };
		return std::make_shared<FuselageData>(nullptr, BulletStatus, FuselageUnion::BulletUnion());
	}

	std::shared_ptr<FuselageData> GetLaserBeam()
	{
		UE_LOG(LogTemp, Log, TEXT("GetLaserBeam"));
		static FuselageStatus LaserBeamStatus{ 1.0f,1.0f,0.0f };
		return std::make_shared<FuselageData>(nullptr, LaserBeamStatus, FuselageUnion::LaserBeamUnion());
	}

	std::shared_ptr<FuselageData> GetFireBall()
	{
		UE_LOG(LogTemp, Log, TEXT("GetFireBall"));
		static FuselageStatus BulletStatus{ 1.0f,3.0f, 0.0f };
		return std::make_shared<FuselageData>(nullptr, BulletStatus, FuselageUnion::FireBallUnion());
	}

	std::shared_ptr<FuselageData> GetHealPack()
	{
		UE_LOG(LogTemp, Log, TEXT("GetHealPack"));
		static FuselageStatus HealPackStatus{ 1.0f,1.0f, 1.0f };
		return std::make_shared<FuselageData>(nullptr, HealPackStatus, FuselageUnion::HealPackUnion());
	}

}