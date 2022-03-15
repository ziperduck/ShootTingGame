// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCharacter.h"

#include "PlayerState.h"

#include "FuselageData.h"
#include "FuselageStatus.h"

#include "WeaponStruct.h"


// Sets default values
ATestCharacter::ATestCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Fuselage RootComponenet"));

}

// Called when the game starts or when spawned
void ATestCharacter::BeginPlay()
{
	Super::BeginPlay();

	m_base_data = std::make_shared<FuselageCharacter>(this, FuselageMaker::GetUFO());

	m_player_data = std::make_shared<PlayerCharacterData>(5);

	m_player_state = new PlayerLiving;

}

// Called to bind functionality to input
void ATestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("EventA",IE_Pressed, this, &ATestCharacter::PressedAttackKey);
	InputComponent->BindAction("EventA", IE_Released, this, &ATestCharacter::ReleasedAttackKey);

}

// Called every frame
void ATestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	IFuselageState* UpdateState = m_player_state->Update(m_base_data);

	if (m_player_state != UpdateState)
	{
		UE_LOG(LogTemp, Log, TEXT("UpdateState"));
		std::swap(m_player_state, UpdateState);
		delete(UpdateState);

		m_player_state->Enter(m_base_data);
	}

	UE_LOG(LogTemp, Log, TEXT("Player Location(%s)"), *GetActorLocation().ToString());
	UE_LOG(LogTemp, Log, TEXT("Player HP %f"), m_base_data->GetCurrentHP());
	UE_LOG(LogTemp, Log, TEXT("Player Score %d"), m_player_data->GetScore());

}

void ATestCharacter::NotifyActorBeginOverlap(AActor* other)
{
	m_player_state->HandleInput(m_base_data, EInputBehavior::COLLISION);
}

//임시로 모든 방향키에 move를 push했다
void ATestCharacter::m_left_right(int Direction)
{
	switch (Direction)
	{
	case -1:
		m_player_state->HandleInput(m_base_data, EInputBehavior::LEFT_MOVE);
		break;
	case 1:
		m_player_state->HandleInput(m_base_data, EInputBehavior::RIGHT_MOVE);
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
		m_player_state->HandleInput(m_base_data, EInputBehavior::BACKWARD_MOVE);
		break;
	case 1:
		m_player_state->HandleInput(m_base_data, EInputBehavior::FORWARD_MOVE);
		break;
	default:
		break;
	}
}

void ATestCharacter::ReleasedAttackKey()
{
	m_base_data->GetWeapon()->SetLifeSpan(m_preesed_time);
	m_preesed_time = 0.0f;
}

void ATestCharacter::PressedAttackKey()
{
	m_preesed_time += 10.0f;
}

