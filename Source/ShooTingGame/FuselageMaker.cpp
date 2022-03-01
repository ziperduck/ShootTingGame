// Fill out your copyright notice in the Description page of Project Settings.


#include "FuselageMaker.h"

#include "TestPlayerWeapon.h"

const int8 PLAYER_UNION() { return 0b1; };

const int8 ENEMY_UNION() { return 0b100; };

const int8 PLAYER_WEAPON_UNION() { return 0b10; };

namespace FuselageMaker
{

	std::shared_ptr<FuselageData> GetUFO()
	{
		UE_LOG(LogTemp, Log, TEXT("GetUFO"));
		static FuselageStatus UFOStatus { 5.0f,1.0f, 2.0f };
		static const FuselageUnion UFOUnion{ PLAYER_UNION(),ENEMY_UNION() };
		return std::make_shared<FuselageData>(new PlayerWeapon::BulletLvel_1,UFOStatus, UFOUnion);
	}

	std::shared_ptr<FuselageData> GetFireDragon()
	{
		UE_LOG(LogTemp, Log, TEXT("GetFireDragon"));
		static FuselageStatus FireDragonStatus{ 1.0f,1.0f, 1.0f };
		static const FuselageUnion& FireDragonUnion{ ENEMY_UNION(), PLAYER_UNION() | PLAYER_WEAPON_UNION() };
		return std::make_shared<FuselageData>(nullptr, FireDragonStatus, FireDragonUnion);
	}

	std::shared_ptr<FuselageData> GetRushDragon()
	{
		UE_LOG(LogTemp, Log, TEXT("GetRushDragon"));
		static FuselageStatus RushDragonStatus{ 1.0f,1.0f, 1.0f };
		static const FuselageUnion& RushDragonUnion{ ENEMY_UNION(), PLAYER_UNION()| PLAYER_WEAPON_UNION() };
		return std::make_shared<FuselageData>(nullptr, RushDragonStatus, RushDragonUnion);
	}

	std::shared_ptr<FuselageData> GetBullet()
	{
		UE_LOG(LogTemp, Log, TEXT("GetRushDragon"));
		static FuselageStatus BulletStatus{ 1.0f,3.0f, 0.0f };
		static const FuselageUnion& BulletUnion{ PLAYER_WEAPON_UNION(),ENEMY_UNION() };
		return std::make_shared<FuselageData>(nullptr, BulletStatus, BulletUnion);
	}

}