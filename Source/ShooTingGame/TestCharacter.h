// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FuselageMaker.h"

#include "FuselageBaseData.h"
#include "PlayerBaseData.h"

#include "PlayerState.h"

#include "CoreMinimal.h"
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
	void ReleasedAttackKey();

	//총을 쏘는 함수
	void PressedAttackKey();

private:

	IPlayerState* m_player_state;

	//공격키를 누른 시간을 체크한다.
	float m_preesed_time;
};
