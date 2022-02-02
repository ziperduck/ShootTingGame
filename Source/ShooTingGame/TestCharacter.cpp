// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCharacter.h"

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
	m_move = std::make_shared<DirectMove>(m_base_data.get()->GetStatus());
	m_collision = std::make_shared<FuselageAttack>(m_base_data);
	m_behavior.push(m_move);
}

// Called every frame
void ATestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	while (!m_behavior.empty())
	{
		m_behavior.front()->execute(this);
		m_behavior.pop();
	}

	//나중에 수정하자
	m_move->Resetkey();
}

// Called to bind functionality to input
void ATestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATestCharacter::NotifyActorBeginOverlap(AActor* other)
{
	
	if (m_base_data->GetCurrentHP() > 0)
	{
		m_behavior.push(m_collision);
	}
	UE_LOG(LogTemp, Log, TEXT("Player Location(%s)"), *GetActorLocation().ToString());
	UE_LOG(LogTemp, Log, TEXT("Player HP %d"), m_base_data->GetCurrentHP());
}

//임시로 모든 방향키에 move를 push했다
void ATestCharacter::m_left_right(int Direction)
{
	switch (Direction)
	{
	case -1:
		m_move->LeftPresses();
		m_behavior.push(m_move);
		break;
	case 1:
		m_move->RightPresses();
		m_behavior.push(m_move);
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
		m_behavior.push(m_move);
		break;
	case 1:
		m_move->ForwardPresses();
		m_behavior.push(m_move);
		break;
	default:
		break;
	}
}

