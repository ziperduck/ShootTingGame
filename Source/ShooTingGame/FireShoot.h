// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Fuselage.h"
#include "EnumPack.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FireShoot.generated.h"

UCLASS()
class SHOOTINGGAME_API AFireShoot : public AActor, public IFuselage
{
	GENERATED_BODY()
	
public:
	AFireShoot();

	virtual void Tick(float Delta) override;

	//Getter
	virtual const EFuselageKind GetKind() const override;

	virtual const float GetSpeed() const override;

	virtual const int32 GetStruckDamage() const override;

	virtual const int32 GetAttackPower() const override;

	virtual const int32 GetMaxHP() const override;

	//Setter
	virtual void AddCurrentHP(const int32 HP) override;

	void MoveLocation(const FVector& MoveLocation);

	//Event
	virtual void EventUpdate() override;

	virtual void NotifyActorBeginOverlap(AActor* Actor) override;

private:

	USceneComponent* m_characterScene;

private:
	const EFuselageKind m_kind = EFuselageKind::FireShoot;

	uint16 m_damage;

	float m_speed;

	int32 m_max_HP;

	int32 m_current_HP;

	const int32 m_struck_damage = 1;

	int32 m_attack_power;

	std::queue<EVariousAction> m_actions;
};
