// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Engine/Classes/Components/SceneComponent.h>
#include "FuselageBehavior.h"
#include "FuselageData.h"

/**
 * int�� �̿��ؼ� ������ �Ʊ����� 0x1���� ������ äũ����
 */
class PlayerTrackingMove : public FuselageBehavior
{
public:

	//Ÿ�ٰ� �߰��ڿ� �̵��ӵ��� �޴´�.
	PlayerTrackingMove(const std::shared_ptr<FuselageData> Speed);
	PlayerTrackingMove(const PlayerTrackingMove& Temporary);
	virtual ~PlayerTrackingMove() final;

	virtual  bool execute(AActor* Actor) final;

private:

	PlayerTrackingMove() = delete;

	FVector m_directions;

	float m_speed;

};
