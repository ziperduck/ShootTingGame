// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Fuselage.h"
#include "EnumPack.h"
#include "GameFramework/Actor.h"
#include "LaserBeam.generated.h"

UCLASS()
class SHOOTINGGAME_API ALaserBeam : public AActor, public IFuselage
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaserBeam();
	virtual void Tick(float Delta) override;

	//Getter
	virtual const EFuselageKind GetKind() const override;

	virtual const float GetSpeed() const override;

	virtual const int32 GetAttackPower() const override;

	virtual const int32 GetMaxHP() const override;

	//Setter
	virtual void AddCurrentHP(const int32 HP) override;

	void MoveLocation(const FVector& MoveLocation) ;

	//Event
	virtual void EventUpdate() override;

	virtual void NotifyActorBeginOverlap(AActor* Actor) override;

private:
	const EFuselageKind m_kind = EFuselageKind::LASERBEAM_WEAPON;

	float m_speed;

	int32 m_max_HP;

	int32 m_current_HP;

	std::queue<EVariousAction> m_actions;

	int32 m_attack_power;

	int32 m_attack_term;

	int32 m_term_count;
};
