// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageData.h"

/**
 * 
 */

namespace Fuselages
{
	//UFO(�÷��̾��� ��ü)�� fuselage���� �����Ѵ�.
	const FuselageData* GetUFO();

	//�ҽ�� �巹�� fuselage���� �����Ѵ�
	const FuselageData* GetFireDragon();

	//�����ϴ� �巹�� fuselage���� �����Ѵ�
	const FuselageData* GetRushDragon();

}