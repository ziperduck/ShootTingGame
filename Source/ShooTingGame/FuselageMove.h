// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
/**
 * ����Ű �̵��� �׳� ����Ű ���� �����ͷ� �޾Ƽ� ���� �����ϸ� �ȴ�.
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
