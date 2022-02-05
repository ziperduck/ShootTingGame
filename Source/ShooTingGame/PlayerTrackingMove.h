// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Engine/Classes/Components/SceneComponent.h>
#include "FuselageBehavior.h"
#include "FuselageData.h"

/**
 * int를 이용해서 적인지 아군인지 0x1같은 식으로 채크하자
 */
class PlayerTrackingMove : public FuselageBehavior
{
public:

	//타겟과 추격자와 이동속도를 받는다.
	PlayerTrackingMove(const std::shared_ptr<FuselageData> Speed);
	PlayerTrackingMove(const PlayerTrackingMove& Temporary);
	virtual ~PlayerTrackingMove() final;

	virtual  bool execute(AActor* Actor) final;

private:

	PlayerTrackingMove() = delete;

	FVector m_directions;

	float m_speed;

};
