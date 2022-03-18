// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "FuselageCharacter.h"

#include "Command.h"

#include "EnumPack.h"

/*
* 구분짓기 위해 무기의 상태만을 만드는 무기 상태 클래스
*/
class IWeaponState
{
public:

	IWeaponState() :m_loding_time(100){ };
	virtual ~IWeaponState() = 0 { m_update_state = nullptr; };

	//현재상태에 input을 받고 알맞는 다음행동을 리턴하는 함수
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) = 0;

	//현재상태에 입력된 이벤트를 실행하고 상태에 맞는 특정 행동을 하는 함수
	virtual IWeaponState* Update(std::shared_ptr<FuselageCharacter> Character) = 0;

protected:

	void m_knot_command(std::shared_ptr<FuselageCharacter> Character);

protected:

	IWeaponState* m_update_state;

	std::queue<Command*> m_all_command;

	const int32 m_loding_time;
};

class WeaponLodedState : public IWeaponState
{
public:
	WeaponLodedState();
	virtual ~WeaponLodedState() final;

private:

	//현재상태에 input을 받고 알맞는 다음행동을 리턴하는 함수
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//현재상태에 입력된 이벤트를 실행하고 상태에 맞는 특정 행동을 하는 함수
	virtual IWeaponState* Update(std::shared_ptr<FuselageCharacter> Character) final;

private:

	Command& m_shooting_comaand;

};

class WeaponLodingState : public IWeaponState
{
public:
	WeaponLodingState();
	virtual ~WeaponLodingState() final;

private:

	//현재상태에 input을 받고 알맞는 다음행동을 리턴하는 함수
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//현재상태에 입력된 이벤트를 실행하고 상태에 맞는 특정 행동을 하는 함수
	virtual IWeaponState* Update(std::shared_ptr<FuselageCharacter> Character) final;

private:

	int32 m_loding_count;

};


class WeaponChargingState : public IWeaponState
{
public:
	WeaponChargingState() ;
	virtual ~WeaponChargingState() final ;

private:

	//현재상태에 input을 받고 알맞는 다음행동을 리턴하는 함수
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//현재상태에 입력된 이벤트를 실행하고 상태에 맞는 특정 행동을 하는 함수
	virtual IWeaponState* Update(std::shared_ptr<FuselageCharacter> Character) final;

private:

	int32 m_charging_count;

};

class WeaponChargingShootState : public IWeaponState
{
public:
	WeaponChargingShootState();
	virtual ~WeaponChargingShootState() final ;

private:

	//현재상태에 input을 받고 알맞는 다음행동을 리턴하는 함수
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//현재상태에 입력된 이벤트를 실행하고 상태에 맞는 특정 행동을 하는 함수
	virtual IWeaponState* Update(std::shared_ptr<FuselageCharacter> Character) final;

};
