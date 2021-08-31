// Fill out your copyright notice in the Description page of Project Settings.

#include"Character.h"
#include "ObjectManager.h"
#include "ActionInstance.h"
#include <Engine/Classes/Camera/CameraComponent.h>
#include "PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurCamera->SetupAttachment(RootComponent);
	OurCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));
	OurCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);
	
	UE_LOG(LogTemp, Log, TEXT("BeginPlay"));
	m_character_componenet = std::make_shared<ActorCharacter>("Player", 10, 1.0f, OurVisibleComponent);
	ObjectManager::GetInstance()->AddObject(m_character_componenet);
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveX", this, &APlayerCharacter::MoveX);
	InputComponent->BindAxis("MoveY", this, &APlayerCharacter::MoveY);
}


void APlayerCharacter::MoveX(float Ancho) {

	
	int8 Defense = Ancho;
	UE_LOG(LogTemp, Log, TEXT("%d"), Defense);

	switch (Defense) {
	case 1:
		m_character_componenet->AddAction(ActionInstance::GetEastMove());
		break;
	case 2:
		m_character_componenet->AddAction(ActionInstance::GetWestMove());
		break;

	}
}
void APlayerCharacter::MoveY(float Ancho) {


	int8 Defense = Ancho;
	UE_LOG(LogTemp, Log, TEXT("%d"), Defense);

	switch (Defense) {
	case 1:
		m_character_componenet->AddAction(ActionInstance::GetSouthMove());
		break;
	case 2:
		m_character_componenet->AddAction(ActionInstance::GetNorthMove());
		break;

	}
}
