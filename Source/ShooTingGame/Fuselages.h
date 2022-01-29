// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageStatus.h"

/**
 * 
 */

namespace Fuselages
{
	//UFO(�÷��̾��� ��ü)�� fuselage���� �����Ѵ�.
	FuselageStatus* GetUFO();

	//�ҽ�� �巹�� fuselage���� �����Ѵ�
	FuselageStatus* GetFireDragon();

	//�����ϴ� �巹�� fuselage���� �����Ѵ�
	FuselageStatus* GetRushDragon();

}