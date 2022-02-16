// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <memory>
#include "FuselageData.h"

/**
 * ��ü���� �⺻ �����͸� �������ִ� �Լ���
 * ���߿��� fix���� �����ϴ� ������ �������Ѵ�. �ƴϸ� �����͸� �����ϴ°� �ƴ϶� ���縦 �Ͼ�� �ص� �ɰͰ���.
 * 
 * Fuselages�� ȣ���ϴ� �ֵ��� ��� 
 */

namespace Fuselages
{
	//UFO(�÷��̾��� ��ü)�� fuselage���� �����Ѵ�.
	std::shared_ptr<FuselageData> GetUFO();

	//�ҽ�� �巹�� fuselage���� �����Ѵ�
	std::shared_ptr<FuselageData> GetFireDragon();

	//�����ϴ� �巹�� fuselage���� �����Ѵ�
	std::shared_ptr<FuselageData> GetRushDragon();

}