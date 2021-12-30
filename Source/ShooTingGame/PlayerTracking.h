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

	//Ÿ�ٰ� �߰��ڿ� �̵��ӵ��� �޴´�.
	PlayerTracking(USceneComponent* ChaserScene, const float Speed);
	virtual ~PlayerTracking() final;

	virtual bool Move() final;

public:

	PlayerTracking() = delete;

	//������ ������ componenet
	USceneComponent* m_chaser_scene;

	//������ ������ �ӵ�
	float m_speed;

};
