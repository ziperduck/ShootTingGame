// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Fuselage.h"
#include "FuselageFoundation.h"
#include "Action.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rifle.generated.h"

UCLASS(Blueprintable, BlueprintType, ClassGroup = "Fuselage")
class SHOOTINGGAME_API ARifle : public AActor, public IFuselage
{
	GENERATED_BODY()
	
public:	
	ARifle();

	//Getter
	virtual const FuselageKind GetKind_Implementation() const override;

	virtual const float GetSpeed_Implementation() const override;

	virtual const FVector GetLocation_Implementation() const override;

	virtual const FRotator GetRotation_Implementation() const override;

	virtual UWorld* GetFuselageWorld_Implementation() const override;

	virtual UClass* GetComponentClass_Implementation() const override;

	//Setter
	void SetLocation_Implementation(const FVector& MoveLocation) ;


private:

	UStaticMeshComponent* CharacterMesh;

private:
	FuselageKind m_kind;

	uint16 m_damage;

	float m_speed;

	int8 m_max_HP;

	int8 m_current_HP;

	std::queue<TSubclassOf<IAction> > m_actions;

	std::queue<TSubclassOf<IAction>> m_animation;
};
