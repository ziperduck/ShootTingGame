// Fill out your copyright notice in the Description page of Project Settings.


#include "LaserBeam.h"

#include "FuselageMaker.h"


// Sets default values
ALaserBeam::ALaserBeam()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Player RootComponenet"));
}

// Called when the game starts or when spawned
void ALaserBeam::BeginPlay()
{
	Super::BeginPlay();
	m_base_data = std::make_shared<FuselageCharacter>(this,0.0f, FuselageMaker::GetLaserBeam());

}

// Called every frame
void ALaserBeam::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	while (!m_behavior.empty())
	{
		checkf(m_base_data.get() != nullptr, TEXT("ALaserBeam m_base_data is nullptr"));
		
		m_behavior.front()->execute(m_base_data);
		m_behavior.pop();
	}

	m_behavior.push(&m_attack_command);
}

void ALaserBeam::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("Laser Beam Overlap"));
}
