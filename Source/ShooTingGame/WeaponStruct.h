// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
* 무기의 데이터
 */
class WeaponStruct {
public:

	WeaponStruct(UClass* WeaponClass,const int32 WeaponLevel, const float Power, const float LifeSpan, const FVector Scale);
	virtual ~WeaponStruct() =0 {};
	
	//무기의 데이터를 토대로 Actor를 생성한다.
	virtual void CreateWeapon(AActor* Gunner) = 0;

	//생명주기를 설정한다.
	void SetLifeSpan(const float LifeSpan);

	//현재 무기의 강화된 무기를 반환합니다. 없을경우 자기 자신을 리턴합니다.
	virtual WeaponStruct* GetUpgradeWeapon() = 0;


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
};


//생성하는 주체가 존재하는지 클래스는 맞게 생성됐는지 확인한다.
AActor* CheckCreateActor(UClass* ActorClass, AActor* CheckActor);