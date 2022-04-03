// Fill out your copyright notice in the Description page of Project Settings.


#include "RushDragon.h"
#include <Engine/Classes/Kismet/GameplayStatics.h>

#include "FuselageMaker.h"

#include "SpecialEvents.h"


// Sets default values
ARushDragon::ARushDragon() 
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Fuselage RootComponenet"));
}


void ARushDragon::BeginPlay()
{
	Super::BeginPlay();

	m_base_data = std::make_shared<FuselageCharacter>(this, 20.0f, FuselageMaker::GetRushDragon());

	m_base_data->AddDeathEvent(std::make_shared<PlayerRaiseScore>(100));
	m_base_data->AddDeathEvent(std::make_shared<RandomItemDrop>());
}


//타임머 만들고 드레곤에 붙이자
void ARushDragon::Tick(float Delta)
{
	Super::Tick(Delta);
	checkf(m_base_data.get() != nullptr, TEXT("ARushDragon base data is nullptr"));

	if (m_base_data->GetCurrentHP() <= 0.0f)
	{
		m_all_command.push(&m_death_command);
	}

	while (!m_all_command.empty())
	{
		m_all_command.front()->execute(m_base_data);
		m_all_command.pop();
	}

	UE_LOG(LogTemp, Log, TEXT("ARushDragon Location(%s)"), *GetActorLocation().ToString());
	UE_LOG(LogTemp, Log, TEXT("ARushDragon HP %f"), m_base_data->GetCurrentHP());
	m_all_command.push(&m_tracking_command);

}

void ARushDragon::NotifyActorBeginOverlap(AActor* Actor)
{
	UE_LOG(LogTemp, Log, TEXT("Overlap ARushDragon"));
	m_all_command.push(&m_attack_command);
}
