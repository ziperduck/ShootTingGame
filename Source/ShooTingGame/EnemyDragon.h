// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Fuselage.h"
#include "EnumPack.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyDragon.generated.h"


UCLASS()
class SHOOTINGGAME_API AEnemyDragon : public AActor , public IFuselage
{
	GENERATED_BODY()

protected:
	
	virtual void BeginPlay() override;

public:

	
	AEnemyDragon();

	//Getter
	virtual const EFuselageKind GetKind_Implementation() const override;

	virtual const float GetSpeed_Implementation() const override;

	virtual const FVector GetLocation_Implementation() const override;

	virtual const FRotator GetRotation_Implementation() const override;

	virtual UWorld* GetFuselageWorld_Implementation() const override;

	virtual UClass* GetComponentClass_Implementation() const override;

	IFuselage*  GetWeapon() const;

	//Setter
	virtual void SetLocation_Implementation(const FVector& MoveLocation) override;

	//Event
	virtual void EventUpdate_Implementation() override;


private:
	UStaticMeshComponent* CharacterMesh;

private:
	EFuselageKind m_kind;

	float m_speed;

	int8 m_max_HP;

	int8 m_current_HP;

	IFuselage*  m_weapon;
	
	std::queue<EVariousAction> m_actions;

	std::queue<EVariousAction> m_next_actions;
};
