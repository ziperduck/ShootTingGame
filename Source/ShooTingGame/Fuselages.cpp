// Fill out your copyright notice in the Description page of Project Settings.


#include "Fuselages.h"

namespace Fuselages
{

	const FuselageData* GetUFO()
	{
		static FuselageData* FireDragon = new FuselageData{ 2.0f, 1 };
		return FireDragon;
	}

	const FuselageData* GetFireDragon()
	{
		static FuselageData* FireDragon = new FuselageData{ 1.0f, 1 };
		return FireDragon;
	}

	const FuselageData* GetRushDragon()
	{
		static FuselageData* RushDragon = new FuselageData{ 2.0f, 1 };
		return RushDragon;
	}

}