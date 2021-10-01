// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WeaponStruct.h"
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

	UFUNCTION(BlueprintCallable)
		void WeaponInitalize(const int32 Power);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Tick(float Delta) override;

	//Getter
	virtual const EFuselageKind GetKind() const override;

	virtual const float GetSpeed() const override;

	virtual const int32 GetAttackPower() const override;

	//Event

	//laser는 피격을 받아도 아무런 데미지를 받지 않는다
	virtual void AttackFuselage(const int32 HP) override;

	virtual void MoveLocation(const FVector& MoveLocation) override;

	virtual void EventUpdate() override;

private:
	const EFuselageKind m_kind = EFuselageKind::PLAYER_WEAPON;

	bool mb_initialize;

	std::queue<EVariousAction> m_actions;

	int32 m_attack_power;
};
