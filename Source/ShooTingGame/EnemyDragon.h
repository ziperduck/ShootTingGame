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

	UFUNCTION(BlueprintCallable, Category = "Fuselage")
	void FuselageInitialize(const float Speed, const int32 MaxHP,const EVariousWeapon Weapon, const float ShootingDelay);

	virtual void Tick(float Delta) override;

	virtual void NotifyActorBeginOverlap(AActor* Actor) override;

	//Getter
	virtual const EFuselageKind GetKind() const override;

	virtual const float GetSpeed() const override;

	virtual const int32 GetAttackPower() const override;

	virtual const int32 GetWeaponLevel() const override;

	virtual const float GetWeaponLiflespan() const override;

	virtual const EVariousWeapon GetWeaponKind() const override;

	virtual const TArray<EVariousAction> GetNextActions() override;

	//Setter

	virtual void SetNextActions_Implementation(const TArray<EVariousAction>& NextActions)  override;

	virtual void SetSpeed(const float Speed) override;

	virtual void SetAttackPower(const int32 Power) override;

	//Event

	virtual void AttackFuselage(const int32 HP) override;

	virtual void MoveLocation(const FVector& MoveLocation) override;

	virtual void EventUpdate() override;

private:

	USoundWave* m_death_sound_asset;

	UAudioComponent* m_death_sound;

	//USphereComponent* m_character_mesh;

	FTimerHandle m_shooting_timer;

private:
	const EFuselageKind m_kind = EFuselageKind::ENEMY_FUSELAGE;

	float m_speed;

	int32 m_max_HP;

	int32 m_current_HP;

	bool mb_initialize;
	
	int32 m_attack_power;

	TQueue<EVariousAction> m_actions;

	TArray<EVariousAction> m_next_actions;

	//플레이어의 무기에 관한 변수들
	EVariousWeapon m_weapon_kind;

	float m_shooting_delay;

};
