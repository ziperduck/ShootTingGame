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
	
	UFUNCTION(BlueprintCallable)
	void MoveX(float Direction);

	UFUNCTION(BlueprintCallable)
	void MoveY(float Direction);

	UFUNCTION(BlueprintCallable)
		void PressAttack(float Direction);

	UFUNCTION(BlueprintCallable)
		void ReleaseAttack(float Direction);

	virtual void ShootingGun() override;

private:

	//외형 및 언리얼에서 제공해주는 기능들

	USceneComponent* m_characterScene;

	FTimerHandle m_shooting_timer;

private:

	//캐릭터에 관한 필요한 정보들

	EFuselageKind m_kind;

	float m_speed;

	int8 m_max_HP;

	int8 m_current_HP;

	std::queue<EVariousAction> m_actions;

	//플레어가 받는 데미지 1로 고정해놨다
	const int32 m_struck_damage = 1;

	//플레이어가 주는 데미지 무기데미지가 아니라 직접 충돌시 주는 데미지
	const int32 m_attack_power = 1;


	//플레이어의 무기에 관한 변수들

	EFuselageKind m_weapon;

	bool mb_press;

	bool m_can_shooting;

	float m_shooting_delay;
};
