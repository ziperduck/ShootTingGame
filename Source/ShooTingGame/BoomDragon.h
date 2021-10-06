// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnumPack.h"
#include "Fuselage.h"
#include "Airframe.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoomDragon.generated.h"

UCLASS()
class SHOOTINGGAME_API ABoomDragon : public AActor, public IFuselage
{
	GENERATED_BODY()
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this actor's properties
	ABoomDragon();

	UFUNCTION(BlueprintCallable, Category = "Fuselage")
	void FuselageInitialize(const float Speed, const int32 MaxHP,const float BoomDelay);

	virtual void Tick(float Delta) override;

	virtual void NotifyActorBeginOverlap(AActor* Actor) override;

	//Getter
	virtual const EFuselageKind GetKind() const override;

	virtual const float GetSpeed() const override;

	virtual const int32 GetAttackPower() const override;

	virtual const TArray<EVariousAction> GetNextActions() override;

	//Setter

	virtual void SetNextActions_Implementation(const TArray<EVariousAction>& NextActions)  override;

	virtual void SetSpeed(const float Speed) override;

	virtual void SetAttackPower(const int32 Power) override;

	virtual void AttackFuselage(const int32 HP) override;

	virtual void MoveLocation(const FVector& MoveLocation) override;

	//Event
	virtual void EventUpdate() override;

private:

	USoundWave* m_death_sound_asset;

	UAudioComponent* m_death_sound;

	FTimerHandle m_boom_timer_handle;

private:

	const EFuselageKind m_kind = EFuselageKind::ENEMY_FUSELAGE;

	int32 m_max_HP;

	int32 m_current_HP;

	bool mb_initialize;

	float m_speed;

	TQueue<EVariousAction> m_actions;

	TArray<EVariousAction> m_next_actions;

	float m_boom_delay;

	int32 m_attack_power;
};
