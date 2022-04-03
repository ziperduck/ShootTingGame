// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "FuselageStatus.h"

#include "ShootingCommand.h"
#include "MoveCommand.h"
#include "CollisionCommand.h"
#include "DeathCommand.h"

#include "FuselageBaseData.h"

#include "GameFramework/Actor.h"
#include "BoomDragon.generated.h"

UCLASS()
class SHOOTINGGAME_API ABoomDragon : public AActor, public IFuselageBaseData
{
	GENERATED_BODY()
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this actor's properties
	ABoomDragon();

	virtual void Tick(float Delta) override;

private:
	//충돌시 호출되는 함수
	virtual void NotifyActorBeginOverlap(AActor* other) final;

private:

	//충돌 관련 행동
	Command& m_attack_command = CollisionCommand::CollisionAttack::getinstance();

	//이동 관련 행동
	Command& m_down_move_command = MoveCommand::BackwardMove::getinstance();

	//죽음 관련 행동
	Command& m_death_command = DeathCommand::EnemyDie::getinstance();


	//모든 동작
	std::queue<Command*> m_all_command;



};
