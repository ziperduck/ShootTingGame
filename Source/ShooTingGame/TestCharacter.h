// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FuselageMove.h"
#include <array>
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TestCharacter.generated.h"

UCLASS()
class SHOOTINGGAME_API ATestCharacter : public APawn
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

	UFUNCTION(BlueprintCallable, Category = "TestFuselage")
		void m_left_pressed();
	UFUNCTION(BlueprintCallable, Category = "TestFuselage")
		void m_right_pressed();
	UFUNCTION(BlueprintCallable, Category = "TestFuselage")
		void m_stright_pressed();
	UFUNCTION(BlueprintCallable, Category = "TestFuselage")
		void m_back_pressed();

	UFUNCTION(BlueprintCallable, Category = "TestFuselage")
		void m_left_released();
	UFUNCTION(BlueprintCallable, Category = "TestFuselage")
		void m_right_released();
	UFUNCTION(BlueprintCallable, Category = "TestFuselage")
		void m_stright_released();
	UFUNCTION(BlueprintCallable, Category = "TestFuselage")
		void m_back_released();

private:
	FuselageMove* m_move;

	std::array<bool, 4> m_pressed_array_key;

	const float m_speed = 3.0f;
};
