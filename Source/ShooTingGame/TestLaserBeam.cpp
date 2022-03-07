// Fill out your copyright notice in the Description page of Project Settings.


#include "TestLaserBeam.h"

#include "FuselageMaker.h"

#include "CollisionCommand.h"
#include "MoveCommand.h"

// Sets default values
ATestLaserBeam::ATestLaserBeam()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestLaserBeam::BeginPlay()
{
	Super::BeginPlay();
	m_base_data = std::make_shared<FuselageCharacter>(this, FuselageMaker::GetLaserBeam());

	m_attatch_command = std::make_shared<MoveCommand::AttatchMove>();

	m_attack_command = std::make_shared<CollisionCommand::CollisionAttack>();

}

// Called every frame
void ATestLaserBeam::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	while (!m_behavior.empty())
	{
		checkf(m_base_data.get() != nullptr, TEXT("ATestLaserBeam m_base_data is nullptr"));
		checkf(m_behavior.front().get() != nullptr, TEXT("ATestLaserBeam Behavior is nullptr"));
		
		m_behavior.front()->execute(m_base_data);
		m_behavior.pop();
	}

	m_behavior.push(m_attack_command);
}

void ATestLaserBeam::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("Laser Beam Overlap"));
}
