// Fill out your copyright notice in the Description page of Project Settings.


#include "FireDragon.h"
#include <Engine/Classes/Kismet/GameplayStatics.h>

#include "FuselageMaker.h"

#include "SpecialEvents.h"

// Sets default values
AFireDragon::AFireDragon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Fuselage RootComponenet"));


}

// Called when the game starts or when spawned
void AFireDragon::BeginPlay()
{
	Super::BeginPlay();

	m_base_data = std::make_shared<FuselageCharacter>(this, 20.0f, FuselageMaker::GetFireDragon());

	m_base_data->AddDeathEvent(std::make_shared<PlayerRaiseScore>(100));
	m_base_data->AddDeathEvent(std::make_shared<RandomItemDrop>());

}



// Called every frame
void AFireDragon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	checkf(m_base_data.get() != nullptr, TEXT("AFireDragon base data is nullptr"));

	if (m_base_data->GetCurrentHP() <= 0.0f)
	{
		m_all_command.push(&m_death_command);
	}

	while (!m_all_command.empty())
	{
		m_all_command.front()->execute(m_base_data);
		m_all_command.pop();
	}

	UE_LOG(LogTemp, Log, TEXT("AFireDragon Location(%s)"), *GetActorLocation().ToString());
	UE_LOG(LogTemp, Log, TEXT("AFireDragon HP %f"), m_base_data->GetCurrentHP());
	
	m_all_command.push(&m_down_move_command);
	m_all_command.push(&m_pressedshoot_command);

}


void AFireDragon::NotifyActorBeginOverlap(AActor* other)
{
		m_all_command.push(&m_attack_command);
}