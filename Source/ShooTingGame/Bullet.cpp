// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"

#include "FuselageMaker.h"


#include "SpecialEvents.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Fuselage RootComponenet"));
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();

	m_base_data = std::make_shared<FuselageCharacter>(this, 0.0f, FuselageMaker::GetBullet());

}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_base_data->GetCurrentHP() <= 0.0f)
	{
		m_behavior.push(&m_death_command);
	}

	while (!m_behavior.empty())
	{
		checkf(m_base_data.get() != nullptr, TEXT("ALaserBeam m_base_data is nullptr"));
		
		m_behavior.front()->execute(m_base_data);
		m_behavior.pop();
	}

	UE_LOG(LogTemp, Log, TEXT("Bullet Location(%s)"), *GetActorLocation().ToString());
	UE_LOG(LogTemp, Log, TEXT("Bullet HP %f"), m_base_data->GetCurrentHP());
	m_behavior.push(&m_direct_command);

}



void ABullet::NotifyActorBeginOverlap(AActor* other)
{
	m_behavior.push(&m_attack_command);


}