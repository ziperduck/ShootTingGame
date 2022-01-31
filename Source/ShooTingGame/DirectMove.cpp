// Fill out your copyright notice in the Description page of Project Settings.


#include "DirectMove.h"


DirectMove::DirectMove(const FuselageStatus& Speed) 
:MoveEvent(Speed){

}


DirectMove::~DirectMove()
{
}

void DirectMove::LeftPresses()
{
	checkf(m_directions.Y > -1, TEXT("LeftPresses over call"));
	m_directions += FVector::LeftVector;
}

void DirectMove::RightPresses()
{
	checkf(m_directions.Y < 1, TEXT("RightPresses over call"));
	m_directions += FVector::RightVector;
}

void DirectMove::ForwardPresses()
{
	checkf(m_directions.X < 1, TEXT("ForwardPresses over call"));
	m_directions += FVector::ForwardVector;
}

void DirectMove::BackwardPresses()
{
	checkf(m_directions.X > -1, TEXT("BackwardPresses over call"));
	m_directions += FVector::BackwardVector;
}

void DirectMove::LeftRelease()
{
	checkf(m_directions.Y < 0, TEXT("LeftRelease over call"));
	m_directions -= FVector::LeftVector;
}

void DirectMove::RightRelease()
{
	checkf(m_directions.Y > 0, TEXT("RightRelease over call"));
	m_directions -= FVector::RightVector;
}

void DirectMove::ForwardRelease()
{
	checkf(m_directions.X > 0, TEXT("ForwardRelease over call"));
	m_directions -= FVector::ForwardVector;
}

void DirectMove::BackwardRelease()
{
	checkf(m_directions.X < 0, TEXT("BackwardRelease over call"));
	m_directions -= FVector::BackwardVector;
}

void DirectMove::Resetkey()
{
	m_directions = FVector::ZeroVector;
}

bool DirectMove::Move(AActor* Actor)
{
	if (Actor != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("m_directions(%s) * Speed = %f"), *m_directions.ToString(), m_speed);
		Actor->SetActorLocation(Actor->GetActorLocation() + (m_directions * m_speed));
		return true;
	}
	return false;
}
