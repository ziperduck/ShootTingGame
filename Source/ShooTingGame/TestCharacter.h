// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"

#include "FuselageMaker.h"

#include "FuselageBaseData.h"
#include "PlayerBaseData.h"

#include "Command.h"

#include "GameFramework/Pawn.h"
#include "TestCharacter.generated.h"


UCLASS()
class SHOOTINGGAME_API ATestCharacter : public APawn, public IFuselageBaseData, public IPlayerBaseData
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATestCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//충돌시 호출되는 함수
	virtual void NotifyActorBeginOverlap(AActor* other) final;

	UFUNCTION(BlueprintCallable, Category = "TestFuselage")
	void m_left_right(int Direction);
	UFUNCTION(BlueprintCallable, Category = "TestFuselage")
	void m_up_dawn(int Direction);

	//총을 쏘는 함수
	void Shooting();

private:

	//공격 관련 행동
	std::shared_ptr<Command> m_shooting_command;

	//공격 관련 행동
	std::shared_ptr<Command> m_attack_command;

	//이동 관련 행동들
	std::shared_ptr<Command> m_left_command;
	std::shared_ptr<Command> m_right_command;
	std::shared_ptr<Command> m_forward_command;
	std::shared_ptr<Command> m_backward_command;

	//해당 객체의 모든 행동들
	std::queue<std::shared_ptr<Command>> m_behavior;
};
