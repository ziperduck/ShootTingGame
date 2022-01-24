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

	//타겟과 추격자와 이동속도를 받는다.
	TrackingMove(const USceneComponent* TargetScene,const USceneComponent* ChaserScene);
	virtual ~TrackingMove() final;

	bool Tracking();

	virtual const FVector& GetDirections()const final;

private:

	TrackingMove() = delete;
	TrackingMove(TrackingMove&) = delete;
	const TrackingMove& operator=(const TrackingMove&) = delete;

	//따라갈 타겟 componenet
	const USceneComponent* m_target_scene;

	//움직일 액터의 componenet
	const USceneComponent* m_chaser_scene;
};
