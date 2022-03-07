// Fill out your copyright notice in the Description page of Project Settings.


#include "TestHealKit.h"

#include "FuselageMaker.h"

#include "MoveCommand.h"
#include "CollisionCommand.h"
#include "DeathCommand.h"

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

	m_direct_command.push_back(std::make_shared<MoveCommand::LeftMove>());
	m_direct_command.push_back(std::make_shared<MoveCommand::BackwardMove>());

	m_collision_heal_command = std::make_shared<CollisionCommand::CollisionHeal>();
	m_death_command = std::make_shared<DeathCommand::FuselageRemove>();
}

// Called every frame
void ATestHealKit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	while (!m_behavior.empty())
	{
		checkf(m_behavior.front().get() != nullptr, TEXT("ATestHealKit behavior front is nullptr"));
		m_behavior.front()->execute(m_base_data);
		UE_LOG(LogTemp, Log, TEXT("m_behavior Enum Pop"));
		m_behavior.pop();
	}

	UE_LOG(LogTemp, Log, TEXT("Enemy Location(%s)"), *GetActorLocation().ToString());
	UE_LOG(LogTemp, Log, TEXT("Enemy HP %f"), m_base_data->GetCurrentHP());

	for (auto i : m_direct_command)
	{
		m_behavior.push(i);
	}
	
	if (m_base_data->GetCurrentHP() <= 0.0f )
	{
		m_behavior.push(m_death_command);
	}

}

void ATestHealKit::NotifyActorBeginOverlap(AActor* Actor)
{
	m_behavior.push(m_collision_heal_command);
}

