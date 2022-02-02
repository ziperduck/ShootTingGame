// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"

#include "Fuselages.h"

#include "FuselageBaseData.h"
#include "FuselageData.h"
#include "FuselageStatus.h"

#include "FuselageBehavior.h"
#include "DirectMove.h"
#include "FuselageAttack.h"

#include "GameFramework/Pawn.h"
#include "TestCharacter.generated.h"


UCLASS()
class SHOOTINGGAME_API ATestCharacter : public APawn, public IFuselageBaseData
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


private:

	//충돌시 하는 행동
	std::shared_ptr<FuselageAttack> m_collision;

	//움직이는 방법
	std::shared_ptr<DirectMove> m_move;

	//해당 객체의 모든 행동들
	std::queue<std::shared_ptr<FuselageBehavior>> m_behavior;
};
