// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageCharacter.h"

#include "DirectMove.h"
#include "FuselageAttack.h"

#include "FuselageData.h"

/**
 * 
 */
class SHOOTINGGAME_API PlayerFuselage : public FuselageCharacter
{
public:
	PlayerFuselage(AActor* Actor, std::shared_ptr<FuselageData> BaseData);
	virtual ~PlayerFuselage() final;

	virtual bool Move() final;
	virtual bool Collision() final;
	virtual bool Death() final;

	void LeftPresses();

	void RightPresses();

	void ForwardPresses();

	void BackwardPresses();


	void LeftRelease();

	void RightRelease();

	void ForwardRelease();

	void BackwardRelease();

	void Resetkey();

private:

	PlayerFuselage() = delete;

	DirectMove m_move;

	FuselageAttack m_collision;

	std::shared_ptr<FuselageData> m_base_data;

};
