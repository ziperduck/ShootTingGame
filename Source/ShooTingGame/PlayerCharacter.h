// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerCharacter.generated.h"

class IObject;

UCLASS()
class SHOOTINGGAME_API APlayerCharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveX(float);
	void MoveY(float);

	UPROPERTY(EditAnywhere,Category = "Component")
	USceneComponent* OurVisibleComponent;

private:

	std::shared_ptr<IObject> m_character_componenet;

};
