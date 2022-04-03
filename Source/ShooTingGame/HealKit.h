// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "FuselageBaseData.h"

#include "MoveCommand.h"
#include "CollisionCommand.h"
#include "DeathCommand.h"

#include "SpecialEvent.h"

#include "GameFramework/Actor.h"
#include "HealKit.generated.h"

UCLASS()
class SHOOTINGGAME_API AHealKit : public AActor, public IFuselageBaseData
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHealKit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* Actor) final;
private:

	//��� ������. 
	std::vector<Command*> m_all_directs_command;

	//�浹������ ������. 
	int32 m_directs_number[2] ;

	//�浹 ���� command
	Command& m_collision_heal_command = CollisionCommand::CollisionHeal::getinstance();

	//���� ���� command
	Command& m_death_command = DeathCommand::FuselageRemove::getinstance();

	//��� �ൿ���� �����Ű�� �Լ�
	std::queue<Command*> m_behavior;

	//���� ���� event
	std::shared_ptr<SpecialEvent> m_death_event;

	//�����̱� �� �÷��̾��� ��ġ
	FVector m_actor_befor_location;

};
