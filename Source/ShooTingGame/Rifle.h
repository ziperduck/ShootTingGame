// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageFoundation.h"
#include "Fuselage.h"
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


	//Event
	void AddNextAction(std::queue<std::shared_ptr<IAction>>);

	virtual void AddAction_Implementation(IAction* Action) override;

	virtual void EventUpdate_Implementation() override;
private:

	UStaticMeshComponent* CharacterMesh;

private:
	FuselageKind m_kind;

	uint16 m_damage;

	float m_speed;

	int8 m_max_HP;

	int8 m_current_HP;

	std::queue<IAction*> m_actions;

	std::queue<std::shared_ptr<IAction>> m_animation;
};
