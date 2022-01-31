// Fill out your copyright notice in the Description page of Project Settings.

#include "FuselageMovement.h"
#include "DirectMove.h"

FuselageMovement::FuselageMovement(std::shared_ptr<MoveEvent> Event)
	: m_move_event(Event)
{
	checkf(m_move_event != nullptr, TEXT("Movement Fuselage is nullptr"));
}

FuselageMovement::~FuselageMovement()
{
}

bool FuselageMovement::execute(AActor* Actor)
{
	if (Actor != nullptr && m_move_event != nullptr)
	{
		return m_move_event->Move(Actor);
	}
	
	return false;
}
