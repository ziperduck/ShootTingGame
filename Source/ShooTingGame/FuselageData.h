// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageStatus.h"
#include "FuselageUnion.h"

/**
 * 하나의 커다란 데이터 덩어리를 만들고
 * 언리얼의 추상클래스를 사용해서 그 데이터를 전달하게 만들고 그것을 통해서 attack을 한다.
 * 
 * 필요한 데이터
 * 
 * 무기
 * 본체 공격력, 체력, 스피드
 * 충돌할 물체, 자신 소속
 * 이동 이벤트, 유도 이벤트, 바로이동 이벤트 
 * 접촉 이벤트, 데미지 입히기, 체력회복하기, 무기 (바꾸기, 업그레이드)
 * Actor를 받고 이벤트로 캐스팅이 가능한가?
 * player로 캐스팅을 해서 사용해보자
 * 
 * 공격 이벤트, 기 모으기, 그냥 쏘기
 * 죽은후 이벤트, 아이템 떨어트리기, 폭발, 
 * 
 * 상태 패턴을 사용해서 공격중인 상테를 만들어서 공격을 못하게 만들거나 하자
 * 
 * 
 * 플레이어한정
 * 폭탄갯수, 스코어
 * 
 * 상태패턴을 사용한다면 키보드를 어떻게 받아서 레이저와 슈팅을 어떻게 구분할것인가?
 * 
 * 행동들을 얻은후 실행하면 없애는 식으로 하자 set que를 이용해서
 * 
 * 충돌시 행동을 추가하면 되지만 이동시 이벤트 추가를 어떻게 할지도 생각해보자
 * 
 * 업데이트패턴을 사용해서 내가 죽었는지 살았는지 확인한다.
 * 
 * 상태, 기본상태, 죽은상태, 부딪힌 상태
 * 
 * 플레이어의 상태및 행동들을 할수있게 하는 클래스 하나를 만들어놓고 
 * 
 * 
 */



class WeaponStruct;
/*
* 동체들의 능력치와 출돌 처리 정보를 가지고있는 데이터
*/
class FuselageData
{
public:

	FuselageData(WeaponStruct* Weapon,FuselageStatus& Status, const FuselageUnion* Union);
	~FuselageData() {};
		
	//최대체력을 넘지 않을만큼만 체력을 회복한다.
	void AddHP(float Num);

	//무기를 교체한다
	void ChangeWeapon(WeaponStruct* Weapon);

	//소속과 충돌체를 교체한다.
	void ChangeUnion(const FuselageUnion* Union);

	//동체의 공격력을 조절한다.
	void SetAttackPower(const float Power);


	//현재 체력을 받는다.
	const float GetCurrentHP() const;

	//현재 무기를 받는다.
	WeaponStruct* GetWeapon() const;

	//현재 능력치를 받는다.
	const FuselageStatus& GetStatus() const;

	//현재 (충돌관련)소속을 받는다.
	const FuselageUnion* GetUnion()const;


private:

	FuselageData() = delete;

private:

	float m_current_hp;

	WeaponStruct* m_weapon;

	FuselageStatus& m_fix_status;

	const FuselageUnion* m_union;

};

