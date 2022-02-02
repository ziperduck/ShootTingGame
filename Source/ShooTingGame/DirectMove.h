// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Engine/Classes/Components/SceneComponent.h>
#include "CoreMinimal.h"
#include "FuselageBehavior.h"
#include "FuselageStatus.h"
#include <array>


/**
 * 움직일 위치를 계산하는것과 움직일 위치 데이터를 따로 두려고 했으나 MoveEvent들을 싱글톤화 해야해서 그냥 합쳐버렸다. 
 */
class DirectMove : public FuselageBehavior
{
public:

	//움직일 물체의 위치와 이동속도 그리고 움직일 위치들을 받는다.
	DirectMove(const FuselageStatus& Speed);
	DirectMove(const DirectMove& Temporary);
	virtual ~DirectMove() final;

	//나중에는 템플릿을 이용해서 compile과정에서 수정하자

	void LeftPresses();

	void RightPresses();

	void ForwardPresses();

	void BackwardPresses();


	void LeftRelease();

	void RightRelease();

	void ForwardRelease();

	void BackwardRelease();

	void Resetkey();

	virtual bool execute(AActor* Actor) final;

private:

	FVector m_directions;

	float m_speed;

};
