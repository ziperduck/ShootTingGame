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

	m_base_data = Fuselages::GetFireDragon();

}

// Called when the game starts or when spawned
void ATestEnemy::BeginPlay()
{
	Super::BeginPlay();

	const USceneComponent* PlayerComponenet
		= GetWorld()->GetFirstPlayerController()->GetPawn()->GetRootComponent();
	m_movey = std::make_shared<TrackingMove>(m_base_data->GetStatus(),PlayerComponenet, RootComponent);
	m_collision = std::make_shared<AttackEvent>(m_base_data);
	m_behavior = std::make_unique<FuselageMovement>(m_movey);
}

void ATestEnemy::NotifyActorBeginOverlap(AActor* other)
{
}


// Called every frame
void ATestEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	m_behavior->execute(this);

}

