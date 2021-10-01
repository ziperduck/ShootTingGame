// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WeaponStruct.h"
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


	UFUNCTION(BlueprintCallable)
		void FuselageInitialize(const float Speed);


	//Getter
	virtual const EFuselageKind GetKind() const override;

	virtual const float GetSpeed() const override;

	//공격력은 1로 고정한다.
	virtual const int32 GetAttackPower() const override;

	//Setter

	virtual void SetSpeed(const float Speed) override;

	virtual void SetAttackPower(const int32 Power) override;


	//Event

	//공격을 받으면 체력이 없기때문에 그냥 죽는다.
	virtual void AttackFuselage(const int32 HP) override;

	virtual void MoveLocation(const FVector& MoveLocation) override;

	virtual void EventUpdate() override;

	virtual void NotifyActorBeginOverlap(AActor* Actor) override;

private:
	const EFuselageKind m_kind = EFuselageKind::ENEMY_WEAPON;

	float m_speed;

	int32 m_attack_power;

	bool mb_initialize;

	std::queue<EVariousAction> m_actions;
};
