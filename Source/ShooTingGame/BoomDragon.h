// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnumPack.h"
#include "Fuselage.h"
#include "Airframe.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoomDragon.generated.h"

UCLASS()
class SHOOTINGGAME_API ABoomDragon : public AActor, public IFuselage,public IAirframe
{
	GENERATED_BODY()
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this actor's properties
	ABoomDragon();

	void Initialize_Implementation(
		const float Speed, const int32 MaxHP, FWeaponStruct Weapon) override;

	virtual void Tick(float Delta) override;

	virtual void NotifyActorBeginOverlap(AActor* Actor) override;

	//Getter
	virtual const EFuselageKind GetKind() const override;

	virtual const float GetSpeed() const override;

	virtual const int32 GetAttackPower() const override;

	virtual const int32 GetMaxHP() const override;

	//Setter
	virtual void AttackFuselage(const int32 HP) override;

	virtual void MoveLocation(const FVector& MoveLocation) override;


	//Event
	virtual void EventUpdate() override;

	virtual const FWeaponStruct GetWeapon() const override;
protected:

	FTimerHandle m_boom_timer_handle;

private:

	const EFuselageKind m_kind = EFuselageKind::ENEMY_FUSELAGE;

	int32 m_max_HP;

	int32 m_current_HP;

	bool mb_initialize;

	TQueue<EVariousAction> m_actions;

	TQueue<EVariousAction> m_next_actions;

	FWeaponStruct m_weapon;

};