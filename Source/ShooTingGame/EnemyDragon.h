// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Fuselage.h"
#include "Action.h"
#include "CoreMinimal.h"
#include "FuselageFoundation.h"
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

	TSubclassOf<UFuselage>  GetWeapon() const;

	virtual UClass* GetComponentClass_Implementation() const override;

	//Setter
	virtual void SetLocation_Implementation(const FVector& MoveLocation) override;



private:
	UStaticMeshComponent* CharacterMesh;

private:
	FuselageKind m_kind;

	float m_speed;

	int8 m_max_HP;

	int8 m_current_HP;

	TSubclassOf<UFuselage>  m_weapon;

	std::queue<TSubclassOf<IAction> > m_actions;

	std::queue<TSubclassOf<IAction>> m_animation;
};
