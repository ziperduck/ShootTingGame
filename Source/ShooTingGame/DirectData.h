// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MovingData.h"
#include "CoreMinimal.h"
#include "EnumPack.h"
#include <array>

/**
 * ���ø��� ����ؼ� ������ ��������
 * 
 * ������ Ŭ������ 
 * 
 * 
 */

class DirectData 
{
public:

	DirectData();

	DirectData(const DirectData& Data);

	~DirectData();

	void LeftPresses();

	void RightPresses();

	void StrightPresses();

	void BackPresses();

	void ResetPressed();

	const std::array<EDirectMove, 4>& GetPressedKey() const;

private:

	std::array<EDirectMove, 4> m_pressed_key;

	int m_current_point;
};
