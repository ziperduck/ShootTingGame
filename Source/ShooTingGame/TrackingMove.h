// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Engine/Classes/Components/SceneComponent.h>
#include "MoveEvent.h"

/**
 * int를 이용해서 적인지 아군인지 0x1같은 식으로 채크하자
 */
class TrackingMove : public MoveEvent
{
public:

	//타겟과 추격자와 이동속도를 받는다.
	TrackingMove(const FuselageStatus& Speed,const USceneComponent* TargetScene,const USceneComponent* ChaserScene);
	virtual ~TrackingMove() final;

	virtual  bool Move(AActor* Actor) final;

private:

	TrackingMove() = delete;

	//따라갈 타겟 componenet
	const USceneComponent* m_target_scene;

	//움직일 액터의 componenet
	const USceneComponent* m_chaser_scene;
};
