// Fill out your copyright notice in the Description page of Project Settings.


#include "Fuselages.h"

namespace Fuselages
{

	FuselageStatus* GetUFO()
	{
		static FuselageStatus* UFO = new FuselageStatus{ 10,2.0f, 1 };
		return UFO;
	}

	FuselageStatus* GetFireDragon()
	{
		static FuselageStatus* FireDragon = new FuselageStatus{ 10,1.0f, 1 };
		return FireDragon;
	}

	FuselageStatus* GetRushDragon()
	{
		static FuselageStatus* RushDragon = new FuselageStatus{ 10,2.0f, 1 };
		return RushDragon;
	}

}