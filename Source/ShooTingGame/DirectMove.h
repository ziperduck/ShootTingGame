// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FuselageMove.h"
#include <Engine/Classes/Components/SceneComponent.h>
#include "CoreMinimal.h"
#include "EnumPack.h"
#include <array>

/**
 * 
 */
class DirectMove : public FuselageMove
{
public:

	//움직일 물체의 위치와 이동속도 그리고 움직일 위치들을 받는다.
	DirectMove(USceneComponent* Fuselage, const std::array<bool, 4>& Directions, const float Speed);
	virtual ~DirectMove() final;
	
	virtual bool Move() final;

public:

	DirectMove() = delete;


	USceneComponent* m_fuselage;
	
	const std::array<bool, 4>& m_directions;

	const float m_speed;

};
