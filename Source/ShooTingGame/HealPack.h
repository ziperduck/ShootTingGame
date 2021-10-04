// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Fuselage.h"
#include "EnumPack.h"
#include "WeaponStruct.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealPack.generated.h"

//플레이어의 체력을 회복시키는 힐팩이다.
UCLASS()
class SHOOTINGGAME_API AHealPack : public AActor, public IFuselage
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHealPack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	virtual void Tick(float Delta) override;

	virtual void NotifyActorBeginOverlap(AActor* Actor) override;

	//Heal은 attack power가 heal power다
	UFUNCTION(BlueprintCallable, Category = "Healpack")
	void HealPackInitalize(const float Spped,const int32 HealPower);

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

	const EFuselageKind m_kind = EFuselageKind::ITEM_FUSELAGE;

	float m_speed;

	int32 m_current_HP;

	int32 m_attack_power;

	bool mb_initialize;

	TQueue<EVariousAction> m_actions;

	TArray<EVariousAction> m_next_actions;
};
