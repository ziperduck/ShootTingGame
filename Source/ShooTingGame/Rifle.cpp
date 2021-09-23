// Fill out your copyright notice in the Description page of Project Settings.


#include "Rifle.h"
#include "Movement.h"

// Sets default values
ARifle::ARifle()
{
	PrimaryActorTick.bCanEverTick = false;

	m_characterScene = CreateAbstractDefaultSubobject<USceneComponent>(TEXT("Scene"));
	m_characterScene->SetupAttachment(RootComponent);


	m_kind = EFuselageKind::RifleFuselage;
	m_speed = 4.0f;
	m_damage = 3;
	m_max_HP = 1;
	m_current_HP = m_max_HP;

}

//Getter

const EFuselageKind ARifle::GetKind() const
{
	return m_kind;
}

const float ARifle::GetSpeed() const
{
	return m_speed;
}

const FVector ARifle::GetLocation() const
{
	return K2_GetActorLocation();
}

const FRotator ARifle::GetRotation() const
{
	return K2_GetActorRotation();
}

UWorld* ARifle::GetFuselageWorld() const
{
	return GetWorld();
}

 UClass* ARifle::GetComponentClass() const
{
	return GetClass();
}


 //Setter

void ARifle::MoveLocation(const FVector& MoveLocation) {
	/*
	* setLocatino은 충돌처리를 못하고 랜더링 값을 가지고있기때문에
	* USceneComponenet를 이용해 충돌처리와 이동을 같이 처리하게 만들었다.
	*/

	FHitResult Hit(1.f);
	checkf(this != nullptr, TEXT("ARifle is nullptr"));

	m_characterScene->MoveComponent(MoveLocation, K2_GetActorRotation(), true, &Hit);
	if (Hit.IsValidBlockingHit())
	{
		UE_LOG(LogTemp, Log, TEXT("is Hit Actor"));
	}
}


//Event
void ARifle::EventUpdate()
{
	IAction* Action = ChangeAction(EVariousAction::EastMove);
	if (Action != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Change Action had Action"));
		Action->Execute(this);
	}
}

void ARifle::Tick(float Delta)
{
	Super::Tick(Delta);

	EventUpdate();
}