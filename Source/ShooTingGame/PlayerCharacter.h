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

	UFUNCTION(BlueprintCallable)
		void FuselageInitialize(const float Speed, const int32 MaxHP,const EVariousWeapon Weapon,const float ShootingDelay);

	virtual void Tick(float Delta) override;

	virtual void NotifyActorBeginOverlap(AActor* Actor) override;

	virtual const int32 GetWeaponLevel() const override;

	virtual const float GetWeaponLiflespan() const override;

	virtual const EVariousWeapon GetWeaponKind() const override;

	//Getter
	virtual const EFuselageKind GetKind() const override;

	virtual const float GetSpeed() const override;

	virtual const int32 GetAttackPower() const override;

	//Setter

	virtual void SetSpeed(const float Speed) override;

	virtual void SetAttackPower(const int32 Power) override;

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


private:
	UClass* TestSpawnActor;
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

	int32 m_attack_power;


	std::queue<EVariousAction> m_actions;

	//플레이어의 무기에 관한 변수들
	EVariousWeapon m_weapon_kind;

	float m_shooting_delay;

	bool mb_press;

	int32 m_weapon_level;

	float m_weapon_lifespan;

	int32 m_press_time;

	bool m_available_shooting;
};
