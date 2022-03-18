// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "WeaponState.h"

/**
* 무기의 데이터
 */
class WeaponStruct {
public:

	WeaponStruct(UClass* WeaponClass, IWeaponState* WeaponState
		,const int32 WeaponLevel, const float Power, const float LifeSpan, const FVector Scale);
	virtual ~WeaponStruct() =0 {};
	
	//무기의 데이터를 토대로 Actor를 생성한다.
	virtual void CreateWeapon(AActor* Gunner) = 0;

	//생명주기를 설정한다.
	void SetLifeSpan(const float LifeSpan);

	//현재 무기의 강화된 무기를 반환합니다. 없을경우 자기 자신을 리턴합니다.
	virtual WeaponStruct* GetUpgradeWeapon() = 0;


	//현재상태에 input을 받고 알맞는 다음행동을 리턴하는 함수
	void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input);

	//현재상태에 입력된 이벤트를 실행하고 상태에 맞는 특정 행동을 하는 함수
	void Update(std::shared_ptr<FuselageCharacter> Character);

	//크기를 받는다.
	const int32 GetWeaponLevel()const;

	//공격력을 받는다.
	const float GetPower()const;

	//생명주기를 받는다.
	const float GetLifeSpan()const;

	//크기를 받는다.
	const FVector GetScale()const;

	//무기의 UClass를 받는다.
	const UClass* GetUClass() const;

private:

	WeaponStruct() = delete;

protected:

	UClass* m_weapon_class;

	const int32 m_level;

	const float m_power;

	float m_lifespan;

	const FVector m_scale;

	IWeaponState* m_weapon_state;
};


//생성하는 주체가 존재하는지 클래스는 맞게 생성됐는지 확인한다.
AActor* CheckCreateActor(UClass* ActorClass, AActor* CheckActor);