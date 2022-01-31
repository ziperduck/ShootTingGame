// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Fuselages.h"
#include "FuselageStatus.h"
#include "DirectMove.h"
#include "FuselageData.h"
#include "FuselageBaseData.h"
#include "FuselageBehavior.h"
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


	UFUNCTION(BlueprintCallable, Category = "TestFuselage")
	void m_left_right(int Direction);
	UFUNCTION(BlueprintCallable, Category = "TestFuselage")
	void m_up_dawn(int Direction);

private:

	std::shared_ptr<DirectMove> m_move;

	std::unique_ptr<FuselageBehavior> m_behavior;
};
