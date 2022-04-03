// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <memory>
#include "FuselageData.h"

/**
 * ��ü���� �⺻ �����͸� �������ִ� �Լ���
 * ���߿��� fix���� �����ϴ� ������ �������Ѵ�. �ƴϸ� �����͸� �����ϴ°� �ƴ϶� ���縦 �Ͼ�� �ص� �ɰͰ���.
 * 
 * FuselageMaker�� ȣ���ϴ� �ֵ��� ��� 
 */

namespace FuselageMaker
{
	//UFO(�÷��̾��� ��ü)�� fuselage���� �����Ѵ�.
	std::shared_ptr<FuselageData> GetUFO();

	//�ҽ�� �巹�� fuselage���� �����Ѵ�
	std::shared_ptr<FuselageData> GetFireDragon();

	//�����ϴ� �巹�� fuselage���� �����Ѵ�
	std::shared_ptr<FuselageData> GetRushDragon();

	//�����ϴ� �巹�� fuselage���� �����Ѵ�
	std::shared_ptr<FuselageData> GetBoomDragon();

	//� fuselage���� �����Ѵ�
	std::shared_ptr<FuselageData> GetMeteoricStone();


	//�Ѿ� fuselage���� �����Ѵ�.
	std::shared_ptr<FuselageData> GetBullet();

	//���̾ fuselage���� �����Ѵ�.
	std::shared_ptr<FuselageData> GetFireBall();

	//������ �� fuselage���� �����Ѵ�.
	std::shared_ptr<FuselageData> GetLaserBeam();

	//���� fuselage���� �����Ѵ�.
	std::shared_ptr<FuselageData> GetHealPack();

	//���ⱳüŰƮ fuselage���� �����Ѵ�.
	std::shared_ptr<FuselageData> GetWeaponKit();

}