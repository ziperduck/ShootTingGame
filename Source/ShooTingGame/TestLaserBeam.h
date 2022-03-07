// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FuselageBaseData.h"

#include "Command.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestLaserBeam.generated.h"

//레이저 빔은 죽지 않는다.
UCLASS()
class SHOOTINGGAME_API ATestLaserBeam : public AActor, public IFuselageBaseData
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATestLaserBeam();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	virtual void NotifyActorBeginOverlap(AActor* Actor) final;

private:

	//공격 관련 행동
	std::shared_ptr<Command> m_attatch_command;

	//공격 관련 행동
	std::shared_ptr<Command> m_attack_command;

	//해당 객체의 모든 행동들
	std::queue<std::shared_ptr<Command>> m_behavior;

};
