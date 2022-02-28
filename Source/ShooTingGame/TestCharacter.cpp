// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCharacter.h"

#include "MoveCommand.h"
#include "CollisionCommand.h"
#include "ShootingCommand.h"

#include "FuselageData.h"
#include "FuselageStatus.h"


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

	m_player_data = std::make_shared<PlayerCharacterData>(3);

	m_shooting_command = std::make_shared<ShootingCommand::ShotAttack>();

	m_left_command = std::make_shared<MoveCommand::LeftMove>();
	m_right_command = std::make_shared<MoveCommand::RightMove>();
	m_forward_command = std::make_shared<MoveCommand::ForwardMove>();
	m_backward_command = std::make_shared<MoveCommand::BackwardMove>();

	m_attack_command = std::make_shared<CollisionCommand::CollisionAttack>();
}

// Called to bind functionality to input
void ATestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("EventA",IE_Pressed, this, &ATestCharacter::Shooting);

}

// Called every frame
void ATestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	checkf(m_base_data.get() != nullptr, TEXT("ATestCharacter base data is nullptr"));

	while (!m_behavior.empty())
	{
		checkf(m_behavior.front().get() != nullptr, TEXT("ATestCharacter behavior front is nullptr"));
		m_behavior.front()->execute(m_base_data);
		m_behavior.pop();
	}

	UE_LOG(LogTemp, Log, TEXT("Player Location(%s)"), *GetActorLocation().ToString());
	UE_LOG(LogTemp, Log, TEXT("Player HP %d"), m_base_data->GetCurrentHP());
	UE_LOG(LogTemp, Log, TEXT("Player Score %d"), m_player_data->GetScore());

}

void ATestCharacter::NotifyActorBeginOverlap(AActor* other)
{
	
	if (m_base_data->GetCurrentHP() > 0)
	{
		m_behavior.push(m_attack_command);
	}
}

//임시로 모든 방향키에 move를 push했다
void ATestCharacter::m_left_right(int Direction)
{
	switch (Direction)
	{
	case -1:
		m_behavior.push(m_left_command);
		break;
	case 1:
		m_behavior.push(m_right_command);
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
		m_behavior.push(m_backward_command);
		break;
	case 1:
		m_behavior.push(m_forward_command);
		break;
	default:
		break;
	}
}

void ATestCharacter::Shooting()
{
	m_behavior.push(m_shooting_command);
}

