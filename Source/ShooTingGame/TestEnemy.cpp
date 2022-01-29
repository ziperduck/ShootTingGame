// Fill out your copyright notice in the Description page of Project Settings.


#include "TestEnemy.h"
#include "FuselageMovement.h"
#include <Engine/Classes/Kismet/GameplayStatics.h>

// Sets default values
ATestEnemy::ATestEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Fuselage RootComponenet"));

}

// Called when the game starts or when spawned
void ATestEnemy::BeginPlay()
{
	Super::BeginPlay();

	const USceneComponent* PlayerComponenet
		= GetWorld()->GetFirstPlayerController()->GetPawn()->GetRootComponent();
	m_base_data = Fuselages::GetFireDragon();
	m_movey = std::make_unique<TrackingMove>(PlayerComponenet, RootComponent);
	m_behavior = new FuselageMovement(RootComponent, m_movey.get(), m_base_data);
}

// Called every frame
void ATestEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	m_movey->Tracking();
	m_behavior->execute();

}

