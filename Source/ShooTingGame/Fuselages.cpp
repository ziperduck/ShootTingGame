// Fill out your copyright notice in the Description page of Project Settings.


#include "Fuselages.h"

namespace Fuselages
{

	std::shared_ptr<FuselageData> GetUFO()
	{
		UE_LOG(LogTemp, Log, TEXT("GetUFO"));
		static const FuselageStatus UFOStatus { 1,1.0f, 1 };
		static const FuselageUnion UFOUnion{ 0b1,0b100 };
		return std::make_shared<FuselageData>(UFOStatus, UFOUnion);
	}

	std::shared_ptr<FuselageData> GetFireDragon()
	{
		UE_LOG(LogTemp, Log, TEXT("GetFireDragon"));
		static const FuselageStatus& FireDragonStatus{ 1,1.0f, 1 };
		static const FuselageUnion& FireDragonUnion{ 0b100, 0b1 };
		return std::make_shared<FuselageData>(FireDragonStatus, FireDragonUnion);
	}

	std::shared_ptr<FuselageData> GetRushDragon()
	{
		UE_LOG(LogTemp, Log, TEXT("GetRushDragon"));
		static const FuselageStatus& RushDragonStatus{ 1,1.0f, 1 };
		static const FuselageUnion& RushDragonUnion{ 0b100, 0b1 };
		return std::make_shared<FuselageData>(RushDragonStatus, RushDragonUnion);
	}

}