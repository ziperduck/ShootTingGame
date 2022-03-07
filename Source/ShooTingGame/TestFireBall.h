// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "FuselageStatus.h"

#include "Command.h"

#include "FuselageBaseData.h"
#include "GameFramework/Actor.h"
#include "TestFireBall.generated.h"


UCLASS()
class SHOOTINGGAME_API ATestFireBall : public AActor, public IFuselageBaseData
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestFireBall();

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
	std::shared_ptr<Command> m_attack_command;

	//움직임 관련 행동
	std::shared_ptr<Command> m_direct_command;

	//죽을때 행동
	std::shared_ptr<Command> m_death_command;

	//해당 객체의 모든 행동들
	std::queue<std::shared_ptr<Command>> m_behavior;
};
