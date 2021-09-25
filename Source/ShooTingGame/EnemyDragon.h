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

	virtual void Tick(float Delta) override;

	//Getter
	virtual const EFuselageKind GetKind() const override;

	virtual const float GetSpeed() const override;

	virtual const FVector GetLocation() const override;

	virtual const FRotator GetRotation() const override;

	virtual UWorld* GetFuselageWorld() const override;

	virtual const int32 GetStruckDamage() const override;

	virtual const int32 GetAttackPower() const override;


	IFuselage*  GetWeapon() const;

	//Setter
	virtual void SetCurrentHP(const int8 HP) override;

	virtual void MoveLocation(const FVector& MoveLocation) override;

	//Event
	virtual void EventUpdate() override;

	virtual void NotifyActorBeginOverlap(AActor* Actor) override;

private:
	UStaticMeshComponent* CharacterMesh;

private:
	EFuselageKind m_kind;

	float m_speed;

	int8 m_max_HP;

	int8 m_current_HP;

	int32 m_struck_damage;

	const int32 m_attack_power = 1;

	IFuselage*  m_weapon;
	
	std::queue<EVariousAction> m_actions;

	std::queue<EVariousAction> m_next_actions;
};
