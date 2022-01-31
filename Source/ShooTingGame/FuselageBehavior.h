// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 상태패턴을 사용한다면 키보드를 어떻게 받아서 레이저와 슈팅을 어떻게 구분할것인가?
 * 
 */
class FuselageBehavior
{
public:
	FuselageBehavior();
	virtual ~FuselageBehavior() = 0 {};

	virtual bool execute(AActor* Actor) = 0;
};
