// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Fuselages.h"
#include "FuselageStatus.h"

#include "FuselageBehavior.h"

#include "FuselageCharacter.h"

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

	//공격 관련 행동
	std::shared_ptr<FuselageBehavior> m_attackevent;

	std::shared_ptr<FuselageBehavior> m_trackingevent;

	//해당 객체의 모든 행동들
	std::queue<std::shared_ptr<FuselageBehavior>> m_behavior;

};
