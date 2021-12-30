// Fill out your copyright notice in the Description page of Project Settings.


#include "DirectMove.h"

DirectMove::DirectMove(USceneComponent* Fuselage, const std::array<bool, 4>& Directions, const float Speed)
	:m_fuselage(Fuselage), m_directions( Directions ), m_speed(Speed){

	checkf(Fuselage != nullptr, TEXT("Direct Move in parameter Fuselage is nullptr"));

}
DirectMove::~DirectMove()
{
}

bool DirectMove::Move()
{
	checkf(m_fuselage != nullptr , TEXT("DirectMove class memver m_fuselage is nullptr "));


	FVector MoveingLocation{0.0f,};

	for (auto i = 0; i < 4; i++)
	{
		if (!m_directions[i])
			continue;
		switch (static_cast<EDirectMove>(i))
		{
		case EDirectMove::LEFT_MOVE:
			MoveingLocation.X -= 1;
			break;
		case EDirectMove::RIGHT_MOVE:
			MoveingLocation.X += 1;
			break;
		case EDirectMove::STRAIGHT_MOVE:
			MoveingLocation.Y += 1;
			break;
		case EDirectMove::BACK_MOVE:
			MoveingLocation.Y -= 1;
			break;
		default:
			break;
		}
	}

	m_fuselage->SetRelativeLocation(m_fuselage->GetComponentLocation() + MoveingLocation);

	return true;
}