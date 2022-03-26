// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FuselageBaseData.h"

#include "CollisionCommand.h"
#include "MoveCommand.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestLaserBeam.generated.h"

//������ ���� ���� �ʴ´�.
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

	//�̵� ���� �ൿ
	Command& m_attatch_command = MoveCommand::AttatchMove::getinstance();

	//���� ���� �ൿ
	Command& m_attack_command = CollisionCommand::CollisionAttack::getinstance();

	//�ش� ��ü�� ��� �ൿ��
	std::queue<Command*> m_behavior;

};
