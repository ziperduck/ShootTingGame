// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "FuselageStatus.h"

#include "Command.h"

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
	std::shared_ptr<Command> m_shooting_command;

	//���� ���� �ൿ
	std::shared_ptr<Command> m_attack_command;

	std::shared_ptr<Command> m_tracking_command;

	std::shared_ptr<Command> m_death_command;

	//�ش� ��ü�� ��� �ൿ��
	std::queue<std::shared_ptr<Command>> m_behavior;

};
