// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Engine/Classes/Components/SceneComponent.h>
#include "FuselageBehavior.h"
#include "FuselageMove.h"
#include "FuselageStatus.h"

/**
 * ���ø��� ����ؼ� ������ ��������
 * 
 * ������ Ŭ������ 
 * 
 * 
 */
class FuselageMovement : public FuselageBehavior
{
public:

	FuselageMovement(USceneComponent* Fuselage,const FuselageMove* Directions, const FuselageStatus* Speed);
	virtual ~FuselageMovement() final;

	virtual bool execute() final;

private:
	FuselageMovement() = delete;

	USceneComponent* m_fuselage;

	const FVector& m_directions;

	const float& m_speed;


};
