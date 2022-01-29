// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Fuselages.h"
#include "MovingData.h"
#include "Fuselages.h"
#include "FuselageStatus.h"
#include "FuselageBehavior.h"
#include "TrackingMove.h"
#include "GameFramework/Actor.h"
#include "TestEnemy.generated.h"

UCLASS()
class SHOOTINGGAME_API ATestEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FuselageStatus* m_base_data;

	FuselageBehavior* m_behavior;

	std::unique_ptr<TrackingMove> m_movey;
	
};
