// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Engine/Classes/Components/SceneComponent.h>
#include "FuselageMove.h"

/**
 * 
 */
class PlayerTracking : public FuselageMove
{
public:

	//타겟과 추격자와 이동속도를 받는다.
	PlayerTracking(USceneComponent* ChaserScene, const float Speed);
	virtual ~PlayerTracking() final;

	virtual bool Move() final;

public:

	PlayerTracking() = delete;

	//움직일 액터의 componenet
	USceneComponent* m_chaser_scene;

	//움직일 액터의 속도
	float m_speed;

};
