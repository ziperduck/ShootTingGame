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

private:
	//�浹�� ȣ��Ǵ� �Լ�
	virtual void NotifyActorBeginOverlap(AActor* other) final;

private:

	//���� ���� �ൿ
	Command& m_pressedshoot_command = ShootingCommand::PressedShoot::getinstance();

	Command& m_releaseshoot_command = ShootingCommand::ReleaseShoot::getinstance();

	//�浹 ���� �ൿ
	Command& m_attack_command = CollisionCommand::CollisionAttack::getinstance();
	
	//�̵� ���� �ൿ
	Command& m_tracking_command = MoveCommand::PlayerTracking::getinstance();

	//���� ���� �ൿ
	Command& m_death_command = DeathCommand::EnemyDie::getinstance();


	//��� ����
	std::queue<Command*> m_all_command;



};
