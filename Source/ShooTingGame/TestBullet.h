// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "FuselageBaseData.h"

#include "MoveCommand.h"
#include "CollisionCommand.h"
#include "DeathCommand.h"

#include "GameFramework/Actor.h"
#include "TestBullet.generated.h"

UCLASS()
class SHOOTINGGAME_API ATestBullet : public AActor, public IFuselageBaseData
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestBullet();

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

	//������ ���� �ൿ
	Command& m_direct_command = MoveCommand::ForwardMove::getinstance();
	
	//���� ���� �ൿ
	Command& m_attack_command = CollisionCommand::CollisionAttack::getinstance();

	//������ �ൿ
	Command& m_death_command = DeathCommand::FuselageRemove::getinstance();

	//�ش� ��ü�� ��� �ൿ��
	std::queue<Command*> m_behavior;
};
