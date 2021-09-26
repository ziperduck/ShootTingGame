// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Fuselage.h"
#include "EnumPack.h"
#include "Airframe.h"
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

	virtual void ShootingGun() override;

private:

	UStaticMeshComponent* m_character_mesh;

	FTimerHandle m_shooting_timer;

public:
	UPROPERTY(BlueprintReadOnly,Category = "Fuselage")
		TArray<EVariousAction> m_next_actions;

private:
	EFuselageKind m_kind;

	float m_speed;

	int8 m_max_HP;

	int8 m_current_HP;

	
	TArray<EVariousAction> m_actions;


	//캐릭터가 받은 피해
	int32 m_struck_damage;

	//캐필터가 충돌시 주는 피해
	const int32 m_attack_power = 1;


	//플레이어의 무기에 관한 변수들

	EFuselageKind m_weapon;

	float m_shooting_delay;
};
