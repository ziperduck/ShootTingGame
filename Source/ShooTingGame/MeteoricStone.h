// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Fuselage.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MeteoricStone.generated.h"

UCLASS()
class SHOOTINGGAME_API AMeteoricStone : public AActor, public IFuselage
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this actor's properties
	AMeteoricStone();

	virtual void Tick(float Delta) override;

	virtual void NotifyActorBeginOverlap(AActor* Actor) override;

	//Getter
	virtual const EFuselageKind GetKind() const override;

	virtual const float GetSpeed() const override;

	virtual const int32 GetStruckDamage() const override;

	virtual const int32 GetAttackPower() const override;

	//Setter
	virtual void AddCurrentHP(const int8 HP) override;

	virtual void MoveLocation(const FVector& MoveLocation) override;


	//Event
	virtual void EventUpdate() override;
private:

	const EFuselageKind m_kind = EFuselageKind::MeteoricStone;

	float m_speed;

	int8 m_max_HP;

	int8 m_current_HP;

	std::queue<EVariousAction> m_actions;

	//캐릭터가 받은 피해
	int32 m_struck_damage;
};
