// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Fuselage.h"
#include "EnumPack.h"
#include "Airframe.h"
#include <Engine/Classes/Components/SphereComponent.h>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyDragon.generated.h"


UCLASS()
class SHOOTINGGAME_API AEnemyDragon : public AActor , public IFuselage, public IAirframe
{
	GENERATED_BODY()

protected:
	
	virtual void BeginPlay() override;

public:

	AEnemyDragon();

	void Initialize_Implementation(
		const float Speed, const int32 MaxHP, FWeaponStruct Weapon) override;

	virtual void Tick(float Delta) override;

	virtual void NotifyActorBeginOverlap(AActor* Actor) override;

	//Getter
	virtual const EFuselageKind GetKind() const override;

	virtual const float GetSpeed() const override;

	virtual const int32 GetAttackPower() const override;

	virtual const FWeaponStruct GetWeapon() const override;

	virtual const int32 GetMaxHP() const override;

	//Event

	virtual void AttackFuselage(const int32 HP) override;

	virtual void MoveLocation(const FVector& MoveLocation) override;

	virtual void EventUpdate() override;

private:

	//USphereComponent* m_character_mesh;

	FTimerHandle m_shooting_timer;

public:
	UPROPERTY(BlueprintReadOnly,Category = "Fuselage")
		TArray<EVariousAction> m_next_actions;

private:
	const EFuselageKind m_kind = EFuselageKind::ENEMY_FUSELAGE;

	float m_speed;

	int32 m_max_HP;

	int32 m_current_HP;

	bool mb_initialize;
	
	TArray<EVariousAction> m_actions;

	//플레이어의 무기에 관한 변수들
	FWeaponStruct m_weapon;
};
