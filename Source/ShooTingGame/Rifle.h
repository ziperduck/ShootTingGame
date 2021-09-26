// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Fuselage.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rifle.generated.h"

UCLASS(Blueprintable, BlueprintType, ClassGroup = "Fuselage")
class SHOOTINGGAME_API ARifle : public AActor, public IFuselage
{
	GENERATED_BODY()
	
public:	
	ARifle();

	virtual void Tick(float Delta) override;

	//Getter
	virtual const EFuselageKind GetKind() const override;

	virtual const float GetSpeed() const override;

	virtual const int32 GetStruckDamage() const override;

	virtual const int32 GetAttackPower() const override;

	//Setter
	virtual void AddCurrentHP(const int8 HP) override;

	void MoveLocation(const FVector& MoveLocation) ;

	void SetKind(const EFuselageKind& Kind);

	//Event
	virtual void EventUpdate() override;

	virtual void NotifyActorBeginOverlap(AActor* Actor) override;

private:

	USceneComponent* m_characterScene;

private:
	EFuselageKind m_kind;

	uint16 m_damage;

	float m_speed;

	int8 m_max_HP;

	int8 m_current_HP;

	const int32 m_struck_damage = 1;

	int32 m_attack_power;

	std::queue<EVariousAction> m_actions;
};
