// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjectManager.h"
#include "GameFramework/Pawn.h"
#include "PlayerCharacterController.generated.h"

UCLASS()
class SHOOTINGGAME_API APlayerCharacterController : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCharacterController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	//player object에게 MoveAction값을 제공하는 함수
	void MoveX(float);
	void MoveY(float);

private:

	ObjectManager* m_object_manager;

	std::unique_ptr<ObjectId> m_player_id;

};
