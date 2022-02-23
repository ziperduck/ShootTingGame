// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageData.h"
#include "WeaponStruct.h"

#include "specialEvent.h"

#include <memory>

/**
* character별로 나누지 말고 한 클래스안에서든 상속을 하던 생성을 따로 하게 만들자
 * stauts와 union과 weaponstatus등 여러가지 들을 놓자
 */
class FuselageCharacter
{
public:
	FuselageCharacter(AActor* Actor, std::shared_ptr<FuselageData> BaseData);
	FuselageCharacter(const FuselageCharacter& Reference);
	~FuselageCharacter(){};

	//이동할 방향을 받는다. Z값이 이동하거나 움직이지 않을경우 false를 리턴한다.
	void MoveTo(FVector Direction);

	//최대체력을 넘지 않게 인자값 만큼 체력을 회복한다.
	void AddHP(float HP);

	//총을 쏘는 함수
	void Shooting();

	//죽는 함수
	void Death();

	//무기를 교체한다.
	void SetWeapon(std::shared_ptr<WeaponStruct> ChangeWeapon);


	void SetDeathEvent(std::vector<std::shared_ptr<SpecialEvent>> DeathEvents);

	void AddDeathEvent(std::shared_ptr<SpecialEvent> DeathEvent);

	const AActor* GetActor() const;

	const int32 GetCurrentHP() const;

	const float GetSpeed() const;

	const int32 GetAttackPower() const;

	const int8 GetUnion() const;

	const int8 GetCollision() const;

private:

	FuselageCharacter() = delete;


protected:

	AActor* m_actor;

	//동체의 기본 데이터
	std::shared_ptr<FuselageData> m_base_data;

	//죽을경우 호출되는 이벤트
	std::vector<std::shared_ptr<SpecialEvent>> m_death_events;
};
