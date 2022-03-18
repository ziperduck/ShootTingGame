// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "FuselageCharacter.h"

#include "Command.h"

#include "EnumPack.h"

/*
* �������� ���� ������ ���¸��� ����� ���� ���� Ŭ����
*/
class IWeaponState
{
public:

	IWeaponState() :m_loding_time(100){ };
	virtual ~IWeaponState() = 0 { m_update_state = nullptr; };

	//������¿� input�� �ް� �˸´� �����ൿ�� �����ϴ� �Լ�
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) = 0;

	//������¿� �Էµ� �̺�Ʈ�� �����ϰ� ���¿� �´� Ư�� �ൿ�� �ϴ� �Լ�
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

	//������¿� input�� �ް� �˸´� �����ൿ�� �����ϴ� �Լ�
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//������¿� �Էµ� �̺�Ʈ�� �����ϰ� ���¿� �´� Ư�� �ൿ�� �ϴ� �Լ�
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

	//������¿� input�� �ް� �˸´� �����ൿ�� �����ϴ� �Լ�
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//������¿� �Էµ� �̺�Ʈ�� �����ϰ� ���¿� �´� Ư�� �ൿ�� �ϴ� �Լ�
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

	//������¿� input�� �ް� �˸´� �����ൿ�� �����ϴ� �Լ�
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//������¿� �Էµ� �̺�Ʈ�� �����ϰ� ���¿� �´� Ư�� �ൿ�� �ϴ� �Լ�
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

	//������¿� input�� �ް� �˸´� �����ൿ�� �����ϴ� �Լ�
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//������¿� �Էµ� �̺�Ʈ�� �����ϰ� ���¿� �´� Ư�� �ൿ�� �ϴ� �Լ�
	virtual IWeaponState* Update(std::shared_ptr<FuselageCharacter> Character) final;

};
