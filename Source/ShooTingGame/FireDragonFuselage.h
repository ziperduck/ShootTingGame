// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageCharacter.h"

#include "PlayerTrackingMove.h"
#include "FuselageAttack.h"

#include "FuselageData.h"

/**
 * 
 */
class SHOOTINGGAME_API FireDragonFuselage : public FuselageCharacter
{
public:
	FireDragonFuselage(AActor* Actor, std::shared_ptr<FuselageData> BaseData);
	virtual ~FireDragonFuselage() final;

	virtual bool Move() final;
	virtual bool Collision() final;
	virtual bool Death() final;

private:

	FireDragonFuselage() =delete;

private:

	PlayerTrackingMove m_move;

	FuselageAttack m_collision;

	std::shared_ptr<FuselageData> m_base_data;

};
