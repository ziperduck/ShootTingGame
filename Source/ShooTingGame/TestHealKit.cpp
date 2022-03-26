// Fill out your copyright notice in the Description page of Project Settings.


#include "TestHealKit.h"

#include "FuselageMaker.h"

// Sets default values
ATestHealKit::ATestHealKit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestHealKit::BeginPlay()
{
	Super::BeginPlay();
	m_base_data = std::make_shared<FuselageCharacter>(this,FuselageMaker::GetHealPack());

	m_all_directs_command.push_back(&MoveCommand::BoundsBackwardMove::getinstance());
	m_all_directs_command.push_back(&MoveCommand::BoundsLeftMove::getinstance());
	m_all_directs_command.push_back(&MoveCommand::BoundsForwardMove::getinstance());
	m_all_directs_command.push_back(&MoveCommand::BoundsRightMove::getinstance());

	m_directs_number[0] = 0;
	m_directs_number[1] = 1;

}

// Called every frame
void ATestHealKit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//움직이기전에 location을 받는다.
	m_actor_befor_location = GetActorLocation();

	for (int i = 0; i < 2; i++)
	{
		UE_LOG(LogTemp, Log, TEXT("m_directs_number[%d] = %d"), i, m_directs_number[i]);
		m_behavior.push(m_all_directs_command.at(m_directs_number[i]));
	}

	if (m_base_data->GetCurrentHP() <= 0.0f)
	{
		m_behavior.push(&m_death_command);
	}

	while (!m_behavior.empty())
	{
		m_behavior.front()->execute(m_base_data);
		m_behavior.pop();
	}

	UE_LOG(LogTemp, Log, TEXT("HealKit Location(%s)"), *GetActorLocation().ToString());
	UE_LOG(LogTemp, Log, TEXT("HealKit HP %f"), m_base_data->GetCurrentHP());


	//움직인후에 벽에 닿았을경우를 찾는다.
	if (m_actor_befor_location.X == GetActorLocation().X)	
	{
		m_directs_number[0] = (m_directs_number[0]+ 2) % 4;
	}
	else if (m_actor_befor_location.Y == GetActorLocation().Y)
	{
		m_directs_number[1] = (m_directs_number[1] + 2) % 4;
	}
}

void ATestHealKit::NotifyActorBeginOverlap(AActor* Actor)
{
	m_behavior.push(&m_collision_heal_command);
}

