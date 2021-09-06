// Fill out your copyright notice in the Description page of Project Settings.


#include "Rifle.h"

// Sets default values
ARifle::ARifle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CharacterMeshAsset(TEXT("/Game/PhysicMash/PuzzleCube.PuzzleCube"));

	CharacterMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CharacterMesh"));
	CharacterMesh->SetStaticMesh(CharacterMeshAsset.Object);
	RootComponent = CharacterMesh;

	this->SetActorScale3D(FVector{ 0.1f,0.1f,0.1f });
}

// Called when the game starts or when spawned
void ARifle::BeginPlay()
{
	Super::BeginPlay();
	
}


