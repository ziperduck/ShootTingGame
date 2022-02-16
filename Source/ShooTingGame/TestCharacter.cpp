// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCharacter.h"
#include "MoveEvent.h"


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

	m_base_data = std::make_shared<FuselageCharacter>(this, Fuselages::GetUFO());

	m_leftevent = std::make_shared<MoveEvent::LeftMove>();
	m_rightevent = std::make_shared<MoveEvent::RightMove>();
	m_forwardevent = std::make_shared<MoveEvent::ForwardMove>();
	m_backwardevent = std::make_shared<MoveEvent::BackwardMove>();

	m_attackevent = std::make_shared<AttackEvent::FuselageAttack>();
}

// Called to bind functionality to input
void ATestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

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

}

void ATestCharacter::NotifyActorBeginOverlap(AActor* other)
{
	
	if (m_base_data->GetCurrentHP() > 0)
	{
		m_behavior.push(m_attackevent);
	}
}

//임시로 모든 방향키에 move를 push했다
void ATestCharacter::m_left_right(int Direction)
{
	switch (Direction)
	{
	case -1:
		m_behavior.push(m_leftevent);
		break;
	case 1:
		m_behavior.push(m_rightevent);
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
		m_behavior.push(m_forwardevent);
		break;
	case 1:
		m_behavior.push(m_backwardevent);
		break;
	default:
		break;
	}
}

