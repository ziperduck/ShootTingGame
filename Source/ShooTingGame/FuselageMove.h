// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
/**
 * 방향키 이동은 그냥 방향키 값을 포인터로 받아서 서로 공유하면 된다.
 */

class FuselageMove
{
public:
	FuselageMove():m_directions(0.0f, 0.0f, 0.0f) { };
	virtual ~FuselageMove() = 0 {};

	virtual const FVector& GetDirections()const = 0;

protected:

	FVector m_directions;
};
