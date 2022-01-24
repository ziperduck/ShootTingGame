// Fill out your copyright notice in the Description page of Project Settings.


#include "TestEnemy.h"
#include <Engine/Classes/Kismet/GameplayStatics.h>
#include "TrackingMove.h"

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
	//m_movey = new TrackingMove(PlayerComponenet, RootComponent, m_base_data->GetSpeed());
}

// Called every frame
void ATestEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

