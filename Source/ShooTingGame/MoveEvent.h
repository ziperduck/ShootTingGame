// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "FuselageStatus.h"

/**
* Status�� �޾Ƽ� Actor�� ���������� �����̴� Ŭ����
 */

class MoveEvent
{
public:
	MoveEvent(const FuselageStatus& Speed):m_directions(0.0f, 0.0f, 0.0f),m_speed(Speed.GetSpeed()) { };
	virtual ~MoveEvent() = 0 {};

	virtual  bool Move(AActor* Actor) = 0;

protected:

	FVector m_directions;

	float m_speed;

private:
	MoveEvent() = delete;
};
