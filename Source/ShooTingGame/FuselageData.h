// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageStatus.h"

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
 */


 /*
 * 어떤 물체와 충돌할지 자신은 어디 소속인지를 나타내는 Struct
 */
struct FuselageUnion
{
public:

	FuselageUnion(const int8 Union, const int8 Collision);

	~FuselageUnion();

	//전달된 Union이 충돌해야하는 객체인지 확인한다.
	const bool MatchUnion(const FuselageUnion& Union) const;

private:

	FuselageUnion() = delete;

private:

	const int8 m_union;

	const int8 m_collision;

};

/*
* 동체들의 능력치와 출돌 처리 정보를 가지고있는 데이터
*/
class FuselageData
{
public:

	FuselageData(const FuselageStatus& Status, const FuselageUnion& Union);
	~FuselageData() {};

	void AddHP(int32 Num);

	const FuselageStatus& GetStatus() const;

	const FuselageUnion& GetUnion()const;


private:

	FuselageData() = delete;

private:

	int32 m_current_hp;

	const FuselageStatus& m_fix_status;

	const FuselageUnion& m_union;

};

