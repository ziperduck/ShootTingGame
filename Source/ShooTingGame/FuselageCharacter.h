// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageData.h"

#include "specialEvent.h"

#include <memory>

/**
* character별로 나누지 말고 한 클래스안에서든 상속을 하던 생성을 따로 하게 만들자
 * stauts와 union과 weaponstatus등 여러가지 들을 놓자
 */
  
class WeaponStruct;

//동체들의 정보를 정보를 가진 클래스
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

	//공격키를 키보드누른다
	void PressedShoot();

	//공격키를 키보드땐다
	void ReleaseShoot();

	//죽는 함수
	void Death();

	//무기를 교체한다.
	void ChangeWeapon(WeaponStruct* ChangeWeapon);

	//소속과 충돌체를 교체한다.
	void ChangeUnion(const FuselageUnion* Union);

	//동체의 공격력을 조절한다.
	void SetAttackPower(const float Power);

	//죽을때 실행되는 이벤트를 설정한다.
	void SetDeathEvent(std::vector<std::shared_ptr<SpecialEvent>> DeathEvents);

	//죽을때 실행되는 이벤트를 추가한다.
	void AddDeathEvent(std::shared_ptr<SpecialEvent> DeathEvent);


	//동체의 Actor를 반환한다.
	const AActor* GetActor() const;

	//동체의 현재체력을 반환한다.
	const float GetCurrentHP() const;

	//동체의 이동속도를 반환한다.
	const float GetSpeed() const;

	//동체의 공격력을 반환한다.
	const float GetAttackPower() const;

	//동체의 소속을 반환한다.
	const int8 GetUnion() const;

	//동체의 충돌할수있는 객체를 반환한다.
	const int8 GetCollision() const;

	//동체의 무기를 반환한다.
	WeaponStruct* GetWeapon() const;

private:

	FuselageCharacter() = delete;


protected:

	AActor* m_actor;

	//동체의 기본 데이터
	std::shared_ptr<FuselageData> m_base_data;

	//죽을경우 호출되는 이벤트
	std::vector<std::shared_ptr<SpecialEvent>> m_death_events;
};
