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
#include "RushDragon.generated.h"


UCLASS()
class SHOOTINGGAME_API ARushDragon : public AActor, public IFuselageBaseData
{
	GENERATED_BODY()

protected:
	
	virtual void BeginPlay() override;

public:

	ARushDragon();

	virtual void NotifyActorBeginOverlap(AActor* Actor) override;

	virtual void Tick(float Delta) override;

private:

	//�浹 ���� �ൿ
	Command& m_attack_command = CollisionCommand::CollisionAttack::getinstance();

	//�̵� ���� �ൿ
	Command& m_tracking_command = MoveCommand::PlayerTracking::getinstance();

	//���� ���� �ൿ
	Command& m_death_command = DeathCommand::EnemyDie::getinstance();


	//��� ����
	std::queue<Command*> m_all_command;

};