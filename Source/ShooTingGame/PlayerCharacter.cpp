// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "Movement.h"
#include <Engine/Classes/Camera/CameraComponent.h>

// Sets default values
APlayerCharacter::APlayerCharacter(){

	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	UE_LOG(LogTemp, Log, TEXT("AplayerContorller Constructor"));


	m_characterScene = CreateAbstractDefaultSubobject<USceneComponent>(TEXT("Scene"));
	m_characterScene->SetupAttachment(RootComponent);

	m_kind = EFuselageKind::RifleFuselage;
	m_speed = 1.0f;
	m_max_HP = 1;
	m_current_HP = m_max_HP;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AplayerContorller BeginPlay"));

}


void APlayerCharacter::MoveX(float Direction)
{
	float Speed = Direction * m_speed;
	SetLocation_Implementation(FVector{ 0.0,Speed,0.0 });

	UE_LOG(LogTemp, Log, TEXT("MoveX"));
}

void APlayerCharacter::MoveY(float Direction)
{
	float Speed = Direction * m_speed;
	SetLocation_Implementation(FVector{ Speed,0.0,0.0 });
	
	UE_LOG(LogTemp, Log, TEXT("MoveY"));
}
void APlayerCharacter::EventA()
{
	GetWeapon();
}

const EFuselageKind APlayerCharacter::GetKind_Implementation() const
{
	return m_kind;
}

const float APlayerCharacter::GetSpeed_Implementation() const
{
	return m_speed;
}

const FVector APlayerCharacter::GetLocation_Implementation() const
{
	return K2_GetActorLocation();
}

const FRotator APlayerCharacter::GetRotation_Implementation() const
{
	return K2_GetActorRotation();
};

UWorld* APlayerCharacter::GetFuselageWorld_Implementation() const
{
	return GetWorld();
}

UClass* APlayerCharacter::GetComponentClass_Implementation() const
{
	return GetClass();
}

IFuselage*  APlayerCharacter::GetWeapon() const
{
	return m_weapon;
}


void APlayerCharacter::SetLocation_Implementation(const FVector& MoveLocation) {
	/*
	* setLocatino은 충돌처리를 못하고 랜더링 값을 가지고있기때문에
	* USceneComponenet를 이용해 충돌처리와 이동을 같이 처리하게 만들었다.
	*/
	FHitResult Hit(1.f);

	UE_LOG(LogTemp, Log, TEXT("MoveLocation"));
	m_characterScene->MoveComponent(MoveLocation, Execute_GetRotation(this), true, &Hit);
	if (Hit.IsValidBlockingHit())
	{
		UE_LOG(LogTemp, Log, TEXT("is Hit Actor"));
	}
}

//Event
void APlayerCharacter::EventUpdate_Implementation()
{

}