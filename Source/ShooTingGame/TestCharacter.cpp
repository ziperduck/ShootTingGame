// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCharacter.h"
#include "DirectMove.h"

// Sets default values
ATestCharacter::ATestCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Fuselage RootComponenet"));

	m_move = new DirectMove(GetRootComponent(), m_pressed_array_key, m_speed);
}


void ATestCharacter::m_left_pressed()
{
	m_pressed_array_key.at(static_cast<int>(EDirectMove::LEFT_MOVE)) = true;
}
void ATestCharacter::m_right_pressed()
{
	m_pressed_array_key.at(static_cast<int>(EDirectMove::RIGHT_MOVE)) = true;
}
void ATestCharacter::m_stright_pressed()
{
	m_pressed_array_key.at(static_cast<int>(EDirectMove::STRAIGHT_MOVE)) = true;
}
void ATestCharacter::m_back_pressed()
{
	m_pressed_array_key.at(static_cast<int>(EDirectMove::BACK_MOVE)) = true;
}

void ATestCharacter::m_left_released()
{
	m_pressed_array_key.at(static_cast<int>(EDirectMove::LEFT_MOVE)) = false;
}
void ATestCharacter::m_right_released()
{
	m_pressed_array_key.at(static_cast<int>(EDirectMove::RIGHT_MOVE)) = false;
}
void ATestCharacter::m_stright_released()
{
	m_pressed_array_key.at(static_cast<int>(EDirectMove::STRAIGHT_MOVE)) = false;
}
void ATestCharacter::m_back_released()
{
	m_pressed_array_key.at(static_cast<int>(EDirectMove::BACK_MOVE)) = false;
}

// Called when the game starts or when spawned
void ATestCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATestCharacter::m_left_right(int Direction)
{
	m_pressed_array_key.at(static_cast<int>(EDirectMove::LEFT_MOVE)) = false;
	m_pressed_array_key.at(static_cast<int>(EDirectMove::RIGHT_MOVE)) = false;
	switch (Direction)
	{
	case -1:
		m_pressed_array_key.at(static_cast<int>(EDirectMove::LEFT_MOVE)) = true;
		break;
	case 1:
		m_pressed_array_key.at(static_cast<int>(EDirectMove::RIGHT_MOVE)) = true;
		break;
	default:
		break;
	}
}

void ATestCharacter::m_up_dawn(int Direction)
{
	m_pressed_array_key.at(static_cast<int>(EDirectMove::BACK_MOVE)) = false;
	m_pressed_array_key.at(static_cast<int>(EDirectMove::STRAIGHT_MOVE)) = false;
	switch (Direction)
	{
	case -1:
		m_pressed_array_key.at(static_cast<int>(EDirectMove::BACK_MOVE)) = true;
		break;
	case 1:
		m_pressed_array_key.at(static_cast<int>(EDirectMove::STRAIGHT_MOVE)) = true;
		break;
	default:
		break;
	}
}

