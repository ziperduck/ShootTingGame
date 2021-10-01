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

	void Initialize_Implementation(
		const float Speed, const int32 MaxHP, FWeaponStruct Weapon) override;

	virtual void Tick(float Delta) override;

	virtual void NotifyActorBeginOverlap(AActor* Actor) override;


	//Getter
	virtual const EFuselageKind GetKind() const override;

	virtual const float GetSpeed() const override;

	virtual const int32 GetAttackPower() const override;

	virtual const int32 GetMaxHP() const override;

	//Setter
	void UpgradeWeapon();

	//Event
	virtual void EventUpdate() override;
	
	UFUNCTION(BlueprintCallable)
	void MoveX(float Direction);

	UFUNCTION(BlueprintCallable)
	void MoveY(float Direction);

	UFUNCTION(BlueprintCallable)
		void PressAttack(float Direction);

	UFUNCTION(BlueprintCallable)
		void ReleaseAttack(float Direction);

	virtual void AttackFuselage(const int32 HP) override;

	virtual void MoveLocation(const FVector& MoveLocation) override;

	virtual const FWeaponStruct GetWeapon() const override;

private:
	//외형 및 언리얼에서 제공해주는 기능들

	//USceneComponent* m_characterScene;

	FTimerHandle m_shooting_timer;

private:

	//캐릭터에 관한 필요한 정보들

	const EFuselageKind m_kind = EFuselageKind::PLAYER_FUSELAGE;

	float m_speed;

	int32 m_max_HP;

	int32 m_current_HP;

	bool mb_initialize;

	std::queue<EVariousAction> m_actions;

	//플레이어의 무기에 관한 변수들
	FWeaponStruct m_weapon;

	bool mb_press;

	int32 m_press_time;

	bool m_available_shooting;
};
