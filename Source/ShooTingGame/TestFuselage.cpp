// Fill out your copyright notice in the Description page of Project Settings.


#include "TestFuselage.h"
#include "DirectMove.h"

ATestFuselage::ATestFuselage()
{

	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Fuselage RootComponenet"));

	m_move = new DirectMove(GetRootComponent(), m_pressed_array_key, m_speed);
}


void ATestFuselage::m_left_pressed()
{
	m_pressed_array_key.at(static_cast<int>(EDirectMove::LEFT_MOVE)) = true;
}
void ATestFuselage::m_right_pressed()
{
	m_pressed_array_key.at(static_cast<int>(EDirectMove::RIGHT_MOVE)) = true;
}
void ATestFuselage::m_stright_pressed()
{
	m_pressed_array_key.at(static_cast<int>(EDirectMove::STRAIGHT_MOVE)) = true;
}
void ATestFuselage::m_back_pressed() 
{
	m_pressed_array_key.at(static_cast<int>(EDirectMove::BACK_MOVE)) = true;
}

void ATestFuselage::m_left_released()
{
	m_pressed_array_key.at(static_cast<int>(EDirectMove::LEFT_MOVE)) = false;
}
void ATestFuselage::m_right_released()
{
	m_pressed_array_key.at(static_cast<int>(EDirectMove::RIGHT_MOVE)) = false;
}
void ATestFuselage::m_stright_released()
{
	m_pressed_array_key.at(static_cast<int>(EDirectMove::STRAIGHT_MOVE)) = false;
}
void ATestFuselage::m_back_released()
{
	m_pressed_array_key.at(static_cast<int>(EDirectMove::BACK_MOVE)) = false;
}

// Called when the game starts or when spawned
void ATestFuselage::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestFuselage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

