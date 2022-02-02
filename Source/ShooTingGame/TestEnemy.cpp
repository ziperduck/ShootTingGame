// Fill out your copyright notice in the Description page of Project Settings.


#include "TestEnemy.h"
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

	m_move = std::make_shared<TrackingMove>(m_base_data.get()->GetStatus(),PlayerComponenet, RootComponent);
	m_collision = std::make_shared<FuselageAttack>(m_base_data);
	m_behavior.push(m_move);
}



// Called every frame
void ATestEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	while (!m_behavior.empty())
	{
		m_behavior.front()->execute(this);
		m_behavior.pop();
	}

	UE_LOG(LogTemp, Log, TEXT("Enemy Location(%s)"), *GetActorLocation().ToString());
	UE_LOG(LogTemp, Log, TEXT("Enemy HP %d"), m_base_data->GetCurrentHP());
	m_behavior.push(m_move);
}


void ATestEnemy::NotifyActorBeginOverlap(AActor* other)
{
	if (m_base_data->GetCurrentHP() > 0)
	{
		m_behavior.push(m_collision);
	}
}