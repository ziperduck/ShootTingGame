// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Engine/Classes/Components/SceneComponent.h>
#include "MoveEvent.h"

/**
 * int�� �̿��ؼ� ������ �Ʊ����� 0x1���� ������ äũ����
 */
class TrackingMove : public MoveEvent
{
public:

	//Ÿ�ٰ� �߰��ڿ� �̵��ӵ��� �޴´�.
	TrackingMove(const FuselageStatus& Speed,const USceneComponent* TargetScene,const USceneComponent* ChaserScene);
	virtual ~TrackingMove() final;

	virtual  bool Move(AActor* Actor) final;

private:

	TrackingMove() = delete;

	//���� Ÿ�� componenet
	const USceneComponent* m_target_scene;

	//������ ������ componenet
	const USceneComponent* m_chaser_scene;
};
