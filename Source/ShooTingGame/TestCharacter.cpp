// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCharacter.h"
#include "FuselageMovement.h"
#include "DirectMove.h"

// Sets default values
ATestCharacter::ATestCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Fuselage RootComponenet"));

	m_base_data = Fuselages::GetUFO();
}

// Called when the game starts or when spawned
void ATestCharacter::BeginPlay()
{
	Super::BeginPlay();
	m_move = std::make_shared<DirectMove>(m_base_data->GetStatus());
	m_behavior = std::make_unique<FuselageMovement>(m_move);
}

// Called every frame
void ATestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_behavior->execute(this))
	{
		UE_LOG(LogTemp, Log, TEXT("Actor Location(%s)"), *GetActorLocation().ToString());
	}
	//나중에 수정하자
	m_move->Resetkey();
}

// Called to bind functionality to input
void ATestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATestCharacter::m_left_right(int Direction)
{
	switch (Direction)
	{
	case -1:
		m_move->LeftPresses();
		break;
	case 1:
		m_move->RightPresses();
		break;
	default:
		break;
	}
}

void ATestCharacter::m_up_dawn(int Direction)
{
	switch (Direction)
	{
	case -1:
		m_move->BackwardPresses();
		break;
	case 1:
		m_move->ForwardPresses();
		break;
	default:
		break;
	}
}

