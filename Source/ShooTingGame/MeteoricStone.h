// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Fuselage.h"
#include "Airframe.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MeteoricStone.generated.h"

UCLASS()
class SHOOTINGGAME_API AMeteoricStone : public AActor, public IFuselage
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this actor's properties
	AMeteoricStone();

	UFUNCTION(BlueprintCallable, Category = "Fuselage")
		void FuselageInitialize(const float Speed, const int32 MaxHP);

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

	USoundBase* m_death_sound_asset;

	UAudioComponent* m_death_sound;

private:

	const EFuselageKind m_kind = EFuselageKind::ENEMY_FUSELAGE;

	int32 m_max_HP;

	int32 m_current_HP;

	int32 m_attack_power;

	float m_speed;

	bool mb_initialize;

	TQueue<EVariousAction> m_actions;

	TArray<EVariousAction> m_next_actions;
};
