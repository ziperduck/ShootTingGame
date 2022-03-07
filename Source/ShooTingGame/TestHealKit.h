// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "FuselageBaseData.h"

#include "Command.h"

#include "SpecialEvent.h"

#include "GameFramework/Actor.h"
#include "TestHealKit.generated.h"

UCLASS()
class SHOOTINGGAME_API ATestHealKit : public AActor, public IFuselageBaseData
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestHealKit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* Actor) final;
private:

	//움직임 관련 command
	std::vector<std::shared_ptr<Command>> m_direct_command;

	//충돌 관련 command
	std::shared_ptr<Command> m_collision_heal_command;

	//죽음 관련 command
	std::shared_ptr<Command> m_death_command;

	//모든 행동들을 실행시키는 함수
	std::queue<std::shared_ptr<Command>> m_behavior;

	//죽음 관련 event
	std::shared_ptr<SpecialEvent> m_death_event;
};
