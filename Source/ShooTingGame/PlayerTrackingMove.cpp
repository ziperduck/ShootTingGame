// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerTrackingMove.h"

PlayerTrackingMove::PlayerTrackingMove(const std::shared_ptr<FuselageData> Speed)	
	: m_speed(Speed->GetStatus().GetSpeed()), m_directions(0.0f,0.0f,0.0f){}

PlayerTrackingMove::PlayerTrackingMove(const PlayerTrackingMove& Temporary)
	: m_speed(Temporary.m_speed), m_directions(Temporary.m_directions){}

PlayerTrackingMove::~PlayerTrackingMove()
{
}

bool PlayerTrackingMove::execute(AActor* Actor)
{
	if (Actor == nullptr)
	{
		return false;
	}

	FVector Target = Actor->GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	FVector Chaser = Actor->GetActorLocation();

	//������ ��ġ���� �Ÿ��� ��� cos�� sin�� ���ذ� ���ǵ� ��ŭ ���� �̵���Ų��.

	FVector DistanceBetween = Target - Chaser;

	float Hypotenuse = sqrt(pow(DistanceBetween.X, 2) + pow(DistanceBetween.Y, 2));

	m_directions = { DistanceBetween.X / Hypotenuse, DistanceBetween.Y / Hypotenuse,0.0f };

	Actor->SetActorLocation(Actor->GetActorLocation() + (m_directions * m_speed));
	return true;
}