// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Engine/Classes/Components/SceneComponent.h>
#include "FuselageBehavior.h"
#include "MoveEvent.h"

/**
 * 템플릿을 사용해서 선언을 억제하자
 * 
 * 데이터 클래스와 
 * 
 * 
 */
class FuselageMovement : public FuselageBehavior
{
public:

	FuselageMovement(std::shared_ptr<MoveEvent> Event);
	virtual ~FuselageMovement() final;

	virtual bool execute(AActor* Actor) final;

private:
	FuselageMovement() = delete;

	std::shared_ptr<MoveEvent> m_move_event;

};
