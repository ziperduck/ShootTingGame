// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Fuselage.h"
#include "EnumPack.h"
#include "WeaponStruct.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponKit.generated.h"

//플레이어의 체력을 회복시키는 힐팩이다.
UCLASS()
class SHOOTINGGAME_API AWeaponKit : public AActor, public IFuselage
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWeaponKit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	virtual void Tick(float Delta) override;

	virtual void NotifyActorBeginOverlap(AActor* Actor) override;

	//Heal은 attack power가 heal power다
	UFUNCTION(BlueprintCallable, Category = "Healpack")
		void WeaponKitInitalize(const float Spped);

	//Getter
	virtual const EFuselageKind GetKind() const override;

	virtual const float GetSpeed() const override;

	virtual const int32 GetAttackPower() const override;

	//Setter

	virtual void SetSpeed(const float Speed) override;

	virtual void SetAttackPower(const int32 Power) override;

	//Setter
	virtual void AttackFuselage(const int32 HP) override;

	virtual void MoveLocation(const FVector& MoveLocation) override;


	//Event
	virtual void EventUpdate() override;

private:

	const EFuselageKind m_kind = EFuselageKind::ITEM_FUSELAGE;

	float m_speed;

	int32 m_change_term;

	int32 m_count_time;

	bool mb_initialize;

	//업그레이드 키트였다가 무기 변경키트였다가한다.
	bool m_change_event;

	TQueue<EVariousAction> m_actions;
};
