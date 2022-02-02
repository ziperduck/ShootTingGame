// Fill out your copyright notice in the Description page of Project Settings.


#include "TrackingMove.h"

TrackingMove::TrackingMove
(const FuselageStatus& Speed, const USceneComponent* TargetScene,const USceneComponent* ChaserScene)
	: m_speed(Speed.GetSpeed()), m_directions(0.0f,0.0f,0.0f) ,m_target_scene(TargetScene),m_chaser_scene(ChaserScene){

	checkf(m_target_scene != nullptr, TEXT("TrackingMove m_target_scene is nullptr"));
	checkf(m_chaser_scene != nullptr , TEXT("TrackingMove m_chaser_scene is nullptr"));
}

TrackingMove::TrackingMove(const TrackingMove& Temporary)
	: m_speed(Temporary.m_speed), m_directions(Temporary.m_directions)
	, m_target_scene(Temporary.m_target_scene), m_chaser_scene(Temporary.m_chaser_scene) {}

TrackingMove::~TrackingMove()
{
	m_chaser_scene = nullptr;
}

bool TrackingMove::execute(AActor* Actor)
{
	if (Actor == nullptr)
	{
		return false;
	}

	if (m_target_scene == nullptr || m_chaser_scene == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("TrackingMove m_target_scene or m_chaser_scene is nullptr"));
		m_directions = FVector::ZeroVector;
		return false;
	}

	//움직일 위치와의 거리를 재고 cos와 sin을 구해고 스피드 만큼 곱해 이동시킨다.

	FVector DistanceBetween = m_target_scene->GetComponentLocation() - m_chaser_scene->GetComponentLocation();

	float Hypotenuse = sqrt(pow(DistanceBetween.X, 2) + pow(DistanceBetween.Y, 2));

	m_directions = { DistanceBetween.X / Hypotenuse, DistanceBetween.Y / Hypotenuse,0.0f };

	Actor->SetActorLocation(Actor->GetActorLocation() + (m_directions * m_speed));
	return true;
}