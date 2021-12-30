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

	//������ ���� �ϴ� �ᰡ����. ���߿� �÷��̾�� �ٲ����
	USceneComponent* PlayerScene = m_chaser_scene;

	//������ ��ġ���� �Ÿ��� ��� cos�� sin�� ���ذ� ���ǵ� ��ŭ ���� �̵���Ų��.

	FVector DistanceBetween = PlayerScene->GetComponentLocation()- m_chaser_scene->GetComponentLocation();

	float Hypotenuse = sqrt(pow(DistanceBetween.X, 2) + pow(DistanceBetween.Y, 2));

	FVector MoveingLocation = { DistanceBetween.X / Hypotenuse, DistanceBetween.Y / Hypotenuse,0.0f };
	MoveingLocation *= m_speed;

	m_chaser_scene->SetRelativeLocation(m_chaser_scene->GetComponentLocation()+ MoveingLocation);

	return true;
}