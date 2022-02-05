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

	UFUNCTION(BlueprintCallable, Category = "PlayerFuselage")
		void FuselageInitialize(
			const float Speed, const int32 MaxHP,const EVariousWeapon Weapon,const float ShootingDelay);

	virtual void Tick(float Delta) override;

	virtual void NotifyActorBeginOverlap(AActor* Actor) override;

	virtual const int32 GetWeaponLevel() const override;

	virtual const float GetWeaponLifespan() const override;

	virtual const EVariousWeapon GetWeaponKind() const override;

	virtual const TArray<EVariousAction> GetNextActions() override;

	void SetScore(const int32 Score);

	//Getter

	virtual void SetNextActions_Implementation(const TArray<EVariousAction>& NextActions)  override{ };

	virtual const EFuselageKind GetKind() const override;

	virtual const float GetSpeed() const override;

	virtual const int32 GetAttackPower() const override;

	UFUNCTION(BlueprintCallable, Category = "PlayerFuselage")
	const int32 GetCurrentHP() const;

	UFUNCTION(BlueprintCallable, Category = "PlayerFuselage")
	const int32 GetSpecialBoomNumber() const;

	UFUNCTION(BlueprintCallable, Category = "PlayerFuselage")
		const int32 GetScore() const;

	//Setter

	virtual void SetSpeed(const float Speed) override;

	virtual void SetAttackPower(const int32 Power) override;

	void UpgradeWeapon();

	//Event
	virtual void EventUpdate() override;
	
	UFUNCTION(BlueprintCallable, Category = "PlayerFuselage")
	void EastWest(float Direction);

	UFUNCTION(BlueprintCallable, Category = "PlayerFuselage")
	void NorthSouth(float Direction);

	UFUNCTION(BlueprintCallable, Category = "PlayerFuselage")
		void PressAttack();

	UFUNCTION(BlueprintCallable, Category = "PlayerFuselage")
		void ReleaseAttack();

	UFUNCTION(BlueprintCallable, Category = "PlayerFuselage")
		void PressSpecialBoom();

	virtual void AttackFuselage(const int32 HP) override;

	virtual void MoveLocation(const FVector& MoveLocation) override;


private:
	UClass* TestSpawnActor;
	//외형 및 언리얼에서 제공해주는 기능들

	//USceneComponent* m_characterScene;

	UAudioComponent* m_weapon_shoot_audio;
	
	USoundBase* RifleSound;
	
	USoundBase* LaserGatherSound;

	FTimerHandle m_shooting_timer;

	FTimerHandle m_invincibility_timer;
private:

	//캐릭터에 관한 필요한 정보들

	const EFuselageKind m_kind = EFuselageKind::PLAYER_FUSELAGE;

	float m_speed;

	int32 m_max_HP;

	int32 m_current_HP;

	bool mb_initialize;

	int32 m_attack_power;

	std::queue<EVariousAction> m_actions;

	int32 m_score;

	//플레이어의 무기에 관한 변수들
	EVariousWeapon m_weapon_kind;

	float m_shooting_delay;

	bool mb_press;

	int32 m_weapon_level;

	float m_weapon_lifespan;

	int32 m_press_time;

	bool m_available_shooting;

	//폭탄 갯수
	int32 m_special_boom_number;

};
