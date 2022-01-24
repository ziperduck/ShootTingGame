// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Engine/Classes/Components/SceneComponent.h>
#include "FuselageMove.h"

/**
 * 
 */
class TrackingMove : public FuselageMove
{
public:

	//Ÿ�ٰ� �߰��ڿ� �̵��ӵ��� �޴´�.
	TrackingMove(const USceneComponent* TargetScene,const USceneComponent* ChaserScene);
	virtual ~TrackingMove() final;

	bool Tracking();

	virtual const FVector& GetDirections()const final;

private:

	TrackingMove() = delete;
	TrackingMove(TrackingMove&) = delete;
	const TrackingMove& operator=(const TrackingMove&) = delete;

	//���� Ÿ�� componenet
	const USceneComponent* m_target_scene;

	//������ ������ componenet
	const USceneComponent* m_chaser_scene;
};
