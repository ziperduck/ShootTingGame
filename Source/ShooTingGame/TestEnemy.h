// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Fuselages.h"
#include "FuselageStatus.h"

#include "FuselageBehavior.h"
#include "FuselageAttack.h"
#include "PlayerTrackingMove.h"

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

	//충돌시 호출되는 함수
	virtual void NotifyActorBeginOverlap(AActor* other) final;

private:

	//충돌시 하는 행동
	std::shared_ptr<FuselageAttack> m_collision;

	//움직이는 방법
	std::shared_ptr<PlayerTrackingMove> m_move;

	//해당 객체의 모든 행동들
	std::queue<std::shared_ptr<FuselageBehavior>> m_behavior;

};
