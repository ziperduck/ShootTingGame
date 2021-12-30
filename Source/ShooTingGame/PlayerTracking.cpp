// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerTracking.h"

PlayerTracking::PlayerTracking(USceneComponent* ChaserScene, const float Speed)
	: m_chaser_scene(ChaserScene),m_speed(Speed){

	checkf(ChaserScene != nullptr , TEXT("ChaserScene is nullptr"));
}

PlayerTracking::~PlayerTracking()
{
	m_chaser_scene = nullptr;
}

bool PlayerTracking::Move()
{
	checkf(m_chaser_scene != nullptr, TEXT("m_chaser_scene is nullptr"));

	//에러가 나서 일단 잠가놨다. 나중에 플레이어로 바꿔놓자
	USceneComponent* PlayerScene = m_chaser_scene;

	//움직일 위치와의 거리를 재고 cos와 sin을 구해고 스피드 만큼 곱해 이동시킨다.

	FVector DistanceBetween = PlayerScene->GetComponentLocation()- m_chaser_scene->GetComponentLocation();

	float Hypotenuse = sqrt(pow(DistanceBetween.X, 2) + pow(DistanceBetween.Y, 2));

	FVector MoveingLocation = { DistanceBetween.X / Hypotenuse, DistanceBetween.Y / Hypotenuse,0.0f };
	MoveingLocation *= m_speed;

	m_chaser_scene->SetRelativeLocation(m_chaser_scene->GetComponentLocation()+ MoveingLocation);

	return true;
}