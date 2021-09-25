// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Airframe.h"
#include "Fuselage.h"
#include "EnumPack.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerCharacter.generated.h"

UCLASS(Blueprintable, BlueprintType, ClassGroup = "Fuselage")
class SHOOTINGGAME_API APlayerCharacter : public APawn, public IFuselage, public IAirframe
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	virtual void Tick(float Delta) override;
	
	//Getter
	virtual const EFuselageKind GetKind() const override;

	virtual const float GetSpeed() const override;

	virtual const FVector GetLocation() const override;

	virtual const FRotator GetRotation() const override;

	virtual UWorld* GetFuselageWorld() const override;

	virtual const int32 GetStruckDamage() const override;

	virtual const int32 GetAttackPower() const override;

	//Setter
	virtual void SetCurrentHP(const int8 HP) override;

	virtual void MoveLocation(const FVector& MoveLocation) override;
	
	//Event
	virtual void EventUpdate() override;
	
	UFUNCTION(BlueprintCallable)
	void MoveX(float Direction);

	UFUNCTION(BlueprintCallable)
	void MoveY(float Direction);

	UFUNCTION(BlueprintCallable)
		void MoveA(float Direction);

	virtual void NotifyActorBeginOverlap(AActor* Actor) override;


	virtual void ShootingGun() override;

public:

private:

	USceneComponent* m_characterScene;

private:

	EFuselageKind m_kind;

	float m_speed;

	int8 m_max_HP;

	int8 m_current_HP;

	const int32 m_struck_damage = 1;

	const int32 m_attack_power = 1;

	std::queue<EVariousAction> m_actions;

	EFuselageKind m_weapon;
};
