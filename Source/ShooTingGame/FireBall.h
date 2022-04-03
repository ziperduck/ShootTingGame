// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "FuselageStatus.h"

#include "MoveCommand.h"
#include "CollisionCommand.h"
#include "DeathCommand.h"

#include "FuselageBaseData.h"
#include "GameFramework/Actor.h"
#include "FireBall.generated.h"


UCLASS()
class SHOOTINGGAME_API AFireBall : public AActor, public IFuselageBaseData
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFireBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//충돌시 호출되는 함수
	virtual void NotifyActorBeginOverlap(AActor* other) final;

private:

	//공격 관련 행동
	Command& m_attack_command = CollisionCommand::CollisionAttack::getinstance();

	//움직임 관련 행동
	Command& m_direct_command = MoveCommand::BackwardMove::getinstance();

	//죽을때 행동
	Command& m_death_command = DeathCommand::FuselageRemove::getinstance();

	//해당 객체의 모든 행동들
	std::queue<Command*> m_behavior;
};
