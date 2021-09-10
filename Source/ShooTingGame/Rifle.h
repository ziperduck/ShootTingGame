// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageFoundation.h"
#include "Fuselage.h"
#include "GameFramework/Actor.h"
#include "Rifle.generated.h"

UCLASS()
class SHOOTINGGAME_API ARifle : public AActor, public IFuselage
{
	GENERATED_BODY()
	
public:	
	ARifle();

	//Getter
	virtual const FuselageKind GetKind() const override;

	virtual const float GetSpeed() const override;

	virtual const FVector GetLocation() const override;

	virtual const FRotator GetRotation() const override;

	virtual UWorld* GetFuselageWorld() const override;

	virtual  UClass* GetComponentClass() const override;

	//Setter
	virtual void SetLocation(const FVector& MoveLocation) override;


	//Event
	void AddNextAction(std::queue<std::shared_ptr<IAction>>);

	virtual void AddAction(std::shared_ptr<IAction>) override;

	virtual void Update() override;
private:

	UStaticMeshComponent* CharacterMesh;

private:
	FuselageKind m_kind;

	uint16 m_damage;

	float m_speed;

	int8 m_max_HP;

	int8 m_current_HP;

	std::queue<std::shared_ptr<IAction>> m_actions;

	std::queue<std::shared_ptr<IAction>> m_animation;
};
