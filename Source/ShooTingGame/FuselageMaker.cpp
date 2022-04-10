// Fill out your copyright notice in the Description page of Project Settings.


#include "FuselageMaker.h"

#include "PlayerWeapon.h"

#include "EnemyWeapon.h"

#include "FuselageUnion.h"

namespace FuselageMaker
{

	std::shared_ptr<FuselageData> GetUFO()
	{
		UE_LOG(LogTemp, Log, TEXT("GetUFO"));

		return std::make_shared<FuselageData>(
			std::make_shared<PlayerWeapon::LaserBeamLvel_1>(), FuselageStatus::PlayerStatus(), FuselageUnion::PlayerUnion());
	}

	std::shared_ptr<FuselageData> GetFireDragon()
	{
		UE_LOG(LogTemp, Log, TEXT("GetFireDragon"));
		return std::make_shared<FuselageData>(
			std::make_shared<EnemyWeapon::FireBallLvel_1>(), FuselageStatus::FireDragonStatus(), FuselageUnion::FireDragonUnion());
	}

	std::shared_ptr<FuselageData> GetRushDragon()
	{
		UE_LOG(LogTemp, Log, TEXT("GetRushDragon"));
		return std::make_shared<FuselageData>(nullptr, FuselageStatus::RushDragonStatus(), FuselageUnion::RushDragonUnion());
	}

	std::shared_ptr<FuselageData> GetBoomDragon()
	{
		UE_LOG(LogTemp, Log, TEXT("GetRushDragon"));
		return std::make_shared<FuselageData>(nullptr, FuselageStatus::BoomDragonStatus(), FuselageUnion::BoomDragonUnion());
	}

	std::shared_ptr<FuselageData> GetMeteoricStone()
	{
		UE_LOG(LogTemp, Log, TEXT("GetRushDragon"));
		return std::make_shared<FuselageData>(nullptr, FuselageStatus::MeteoricStoneStatus(), FuselageUnion::MeteoricStoneUnion());
	}


	std::shared_ptr<FuselageData> GetBullet()
	{
		UE_LOG(LogTemp, Log, TEXT("GetRushDragon"));
		return std::make_shared<FuselageData>(nullptr, FuselageStatus::BulletStatus(), FuselageUnion::BulletUnion());
	}

	std::shared_ptr<FuselageData> GetLaserBeam()
	{
		UE_LOG(LogTemp, Log, TEXT("GetLaserBeam"));
		return std::make_shared<FuselageData>(nullptr, FuselageStatus::LaserBeamStatus(), FuselageUnion::LaserBeamUnion());
	}

	std::shared_ptr<FuselageData> GetFireBall()
	{
		UE_LOG(LogTemp, Log, TEXT("GetFireBall"));
		return std::make_shared<FuselageData>(nullptr, FuselageStatus::FireBallStatus(), FuselageUnion::FireBallUnion());
	}

	std::shared_ptr<FuselageData> GetHealPack()
	{
		UE_LOG(LogTemp, Log, TEXT("GetHealPack"));
		return std::make_shared<FuselageData>(nullptr, FuselageStatus::HealPackStatus(), FuselageUnion::HealPackUnion());
	}

	std::shared_ptr<FuselageData> GetWeaponKit()
	{
		UE_LOG(LogTemp, Log, TEXT("GetWeaponKit"));
		return std::make_shared<FuselageData>(nullptr, FuselageStatus::WeaponKitStatus(), FuselageUnion::WeaponKitUnion());
	}
}