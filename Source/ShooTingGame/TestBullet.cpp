// Fill out your copyright notice in the Description page of Project Settings.


#include "TestBullet.h"

#include "FuselageMaker.h"

#include "MoveCommand.h"
#include "CollisionCommand.h"
#include "DeathCommand.h"

#include "SpecialEvents.h"

// Sets default values
ATestBullet::ATestBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Fuselage RootComponenet"));
}

// Called when the game starts or when spawned
void ATestBullet::BeginPlay()
{
	Super::BeginPlay();

	m_base_data = std::make_shared<FuselageCharacter>(this, FuselageMaker::GetBullet());

	m_direct_command = std::make_shared<MoveCommand::ForwardMove>();
	m_attack_command = std::make_shared<CollisionCommand::CollisionAttack>();
	m_death_command = std::make_shared<DeathCommand::FuselageRemove>();
}

// Called every frame
void ATestBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	while (!m_behavior.empty())
	{
		checkf(m_base_data.get() != nullptr, TEXT("ATestLaserBeam m_base_data is nullptr"));
		checkf(m_behavior.front().get() != nullptr, TEXT("ATestLaserBeam Behavior is nullptr"));
		
		m_behavior.front()->execute(m_base_data);
		m_behavior.pop();
	}

	UE_LOG(LogTemp, Log, TEXT("Bullet Location(%s)"), *GetActorLocation().ToString());
	UE_LOG(LogTemp, Log, TEXT("Bullet HP %f"), m_base_data->GetCurrentHP());
	m_behavior.push(m_direct_command);

	if (m_base_data->GetCurrentHP() <= 0.0f)
	{
		m_behavior.push(m_death_command);
	}

}



void ATestBullet::NotifyActorBeginOverlap(AActor* other)
{
	m_behavior.push(m_attack_command);


}