// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Fuselage.h"
#include "EnumPack.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerCharacter.generated.h"

UCLASS(Blueprintable, BlueprintType, ClassGroup = "Fuselage")
class SHOOTINGGAME_API APlayerCharacter : public APawn, public IFuselage
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	//Getter
	virtual const EFuselageKind GetKind_Implementation() const override;

	virtual const float GetSpeed_Implementation() const override;

	virtual const FVector GetLocation_Implementation() const override;

	virtual const FRotator GetRotation_Implementation() const override;

	virtual UWorld* GetFuselageWorld_Implementation() const override;

	virtual UClass* GetComponentClass_Implementation() const override;

	TSubclassOf<UFuselage>  GetWeapon() const;

	//Setter
	virtual void SetLocation_Implementation(const FVector& MoveLocation) override;

	//Event
	virtual void EventUpdate_Implementation() override;


	// Called to bind functionality to input
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	//player object에게 MoveAction값을 제공하는 함수
	void MoveX(float);
	void MoveY(float);

	void EventA();

	UStaticMeshComponent* CharacterMesh;

private:
	float ApratVector;

	EFuselageKind m_kind;

	float m_speed;

	int8 m_max_HP;

	int8 m_current_HP;

	TSubclassOf<UFuselage>  m_weapon;

	std::queue<EVariousAction> m_actions;

	std::queue<EVariousAction> m_next_actions;
};
