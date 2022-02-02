// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Fuselages.h"
#include "FuselageStatus.h"

#include "FuselageBehavior.h"
#include "AttackEvent.h"
#include "TrackingMove.h"

#include "FuselageBaseData.h"
#include "GameFramework/Actor.h"
#include "TestEnemy.generated.h"

UCLASS()
class SHOOTINGGAME_API ATestEnemy : public AActor, public IFuselageBaseData
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

	virtual void NotifyActorBeginOverlap(AActor* other) final;

private:

	std::shared_ptr<AttackEvent> m_collision;

	std::shared_ptr<TrackingMove> m_movey;
	
	std::unique_ptr<FuselageBehavior> m_behavior;

};
