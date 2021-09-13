// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageFoundation.h"
#include "Fuselage.h"
#include "GameFramework/Actor.h"
#include "EnemyDragon.generated.h"


UCLASS()
class SHOOTINGGAME_API AEnemyDragon : public AActor , public IFuselage
{
	GENERATED_BODY()


public:
	AEnemyDragon();

	//Getter
	virtual const FuselageKind GetKind_Implementation() const override;

	virtual const float GetSpeed_Implementation() const override;

	virtual const FVector GetLocation_Implementation() const override;

	virtual const FRotator GetRotation_Implementation() const override;

	virtual UWorld* GetFuselageWorld_Implementation() const override;

	TScriptInterface<IFuselage>  GetWeapon() const;

	virtual UClass* GetComponentClass_Implementation() const override;

	//Setter
	virtual void SetLocation_Implementation(const FVector& MoveLocation) override;


	//Event
	void AddNextAction(std::queue<TScriptInterface<IAction>>);

	virtual void AddAction_Implementation(TScriptInterface<IAction>  Action) override;

	virtual void EventUpdate_Implementation() override;

private:
	UStaticMeshComponent* CharacterMesh;

private:
	FuselageKind m_kind;

	float m_speed;

	int8 m_max_HP;

	int8 m_current_HP;

	TScriptInterface<IFuselage>  m_weapon;

	std::queue<TScriptInterface<IAction> > m_actions;

	std::queue<TScriptInterface<IAction>> m_animation;
};
