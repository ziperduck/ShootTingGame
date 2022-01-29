// Fill out your copyright notice in the Description page of Project Settings.

#include "FuselageMovement.h"
#include "DirectMove.h"

FuselageMovement::FuselageMovement(USceneComponent* Fuselage, const  FuselageMove* Directions, const FuselageStatus* Speed)
	:m_fuselage(Fuselage), m_directions(Directions->GetDirections()), m_speed(Speed->GetSpeed())
{
	checkf(m_fuselage != nullptr, TEXT("Movement Fuselage is nullptr"));
}

FuselageMovement::~FuselageMovement()
{
}

bool FuselageMovement::execute()
{
	if (m_fuselage != nullptr)
	{
		m_fuselage->SetWorldLocation(m_fuselage->GetComponentLocation() + (m_directions * m_speed));
		return true;

	}
	else
	{
		checkf(m_fuselage != nullptr, TEXT("Movement Fuselage is nullptr"));
		return false;
	}
}
