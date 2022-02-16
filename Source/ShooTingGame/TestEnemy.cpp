// Fill out your copyright notice in the Description page of Project Settings.


#include "TestEnemy.h"
#include <Engine/Classes/Kismet/GameplayStatics.h>

#include "MoveEvent.h"
#include "FuselageAttack.h"

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

	m_base_data = std::make_shared<FuselageCharacter>(this, Fuselages::GetFireDragon());
	m_trackingevent = std::make_shared<MoveEvent::PlayerTracking>();
	m_attackevent = std::make_shared<AttackEvent::FuselageAttack>();
}



// Called every frame
void ATestEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	checkf(m_base_data.get() != nullptr, TEXT("ATestCharacter base data is nullptr"));

	while (!m_behavior.empty())
	{
		checkf(m_behavior.front().get() != nullptr, TEXT("ATestCharacter behavior front is nullptr"));
		m_behavior.front()->execute(m_base_data);
		m_behavior.pop();
	}

	UE_LOG(LogTemp, Log, TEXT("Enemy Location(%s)"), *GetActorLocation().ToString());
	UE_LOG(LogTemp, Log, TEXT("Enemy HP %d"), m_base_data->GetCurrentHP());
	m_behavior.push(m_trackingevent);

}


void ATestEnemy::NotifyActorBeginOverlap(AActor* other)
{
	if (m_base_data->GetCurrentHP() > 0)
	{
		m_behavior.push(m_attackevent);
	}
}