// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Engine/Classes/Components/SceneComponent.h>
#include "FuselageBehavior.h"
#include "FuselageStatus.h"

/**
 * int�� �̿��ؼ� ������ �Ʊ����� 0x1���� ������ äũ����
 */
class TrackingMove : public FuselageBehavior
{
public:

	//Ÿ�ٰ� �߰��ڿ� �̵��ӵ��� �޴´�.
	TrackingMove(const FuselageStatus& Speed,const USceneComponent* TargetScene,const USceneComponent* ChaserScene);
	TrackingMove(const TrackingMove& Temporary);
	virtual ~TrackingMove() final;

	virtual  bool execute(AActor* Actor) final;

private:

	TrackingMove() = delete;

	//���� Ÿ�� componenet
	const USceneComponent* m_target_scene;

	//������ ������ componenet
	const USceneComponent* m_chaser_scene;

	FVector m_directions;

	float m_speed;

};
