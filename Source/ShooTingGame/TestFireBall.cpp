// Fill out your copyright notice in the Description page of Project Settings.


#include "TestFireBall.h"
#include <Engine/Classes/Kismet/GameplayStatics.h>

#include "FuselageMaker.h"


#include "SpecialEvents.h"

// Sets default values
ATestFireBall::ATestFireBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Fuselage RootComponenet"));

}

// Called when the game starts or when spawned
void ATestFireBall::BeginPlay()
{
	Super::BeginPlay();

	m_base_data = std::make_shared<FuselageCharacter>(this, FuselageMaker::GetFireBall());

}

// Called every frame
void ATestFireBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	checkf(m_base_data.get() != nullptr, TEXT("ATestCharacter base data is nullptr"));

	while (!m_behavior.empty())
	{
		m_behavior.front()->execute(m_base_data);
		UE_LOG(LogTemp, Log, TEXT("m_behavior Enum Pop"));
		m_behavior.pop();
	}

	UE_LOG(LogTemp, Log, TEXT("FireBall Location(%s)"), *GetActorLocation().ToString());
	UE_LOG(LogTemp, Log, TEXT("FireBall HP %f"), m_base_data->GetCurrentHP());
	m_behavior.push(&m_direct_command);

	if (m_base_data->GetCurrentHP() <= 0.0f)
	{
		m_behavior.push(&m_death_command);
	}

}

void ATestFireBall::NotifyActorBeginOverlap(AActor* other)
{
	m_behavior.push(&m_attack_command);


}
