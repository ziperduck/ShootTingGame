// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"

#include "Fuselages.h"

#include "FuselageBaseData.h"
#include "FuselageData.h"
#include "FuselageStatus.h"

#include "FuselageBehavior.h"
#include "FuselageAttack.h"

#include "FuselageCharacter.h"

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

	//공격 관련 행동
	std::shared_ptr<FuselageBehavior> m_attackevent;

	//이동 관련 행동들
	std::shared_ptr<FuselageBehavior> m_leftevent;
	std::shared_ptr<FuselageBehavior> m_rightevent;
	std::shared_ptr<FuselageBehavior> m_forwardevent;
	std::shared_ptr<FuselageBehavior> m_backwardevent;

	//해당 객체의 모든 행동들
	std::queue<std::shared_ptr<FuselageBehavior>> m_behavior;
};
