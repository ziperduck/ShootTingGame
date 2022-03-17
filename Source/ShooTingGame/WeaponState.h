// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "FuselageCharacter.h"

#include "Command.h"

#include "EnumPack.h"

/*
* �������� ���� ������ ���¸��� ����� ���� ���� Ŭ����
*/
class WeaponState
{
public:

	WeaponState() :m_loding_time(100){ };
	virtual ~WeaponState() = 0 { m_update_state = nullptr; };

	//������¿� input�� �ް� �˸´� �����ൿ�� �����ϴ� �Լ�
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) = 0;

	//������¿� �Էµ� �̺�Ʈ�� �����ϰ� ���¿� �´� Ư�� �ൿ�� �ϴ� �Լ�
	virtual WeaponState* Update(std::shared_ptr<FuselageCharacter> Character) = 0;

	//���¿� ���� ȣ���ϴ� �Լ�
	virtual void Enter(std::shared_ptr<FuselageCharacter> Character) = 0;

protected:

	void m_knot_command(std::shared_ptr<FuselageCharacter> Character);

protected:

	WeaponState* m_update_state;

	std::queue<Command*> m_all_command;

	const int32 m_loding_time;
};

class WeaponLodedState : public WeaponState
{
public:
	WeaponLodedState();
	virtual ~WeaponLodedState() final;

private:

	//������¿� input�� �ް� �˸´� �����ൿ�� �����ϴ� �Լ�
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//������¿� �Էµ� �̺�Ʈ�� �����ϰ� ���¿� �´� Ư�� �ൿ�� �ϴ� �Լ�
	virtual WeaponState* Update(std::shared_ptr<FuselageCharacter> Character) final;

	//���¿� ���� ȣ���ϴ� �Լ�
	virtual void Enter(std::shared_ptr<FuselageCharacter> Character) final;

private:

	Command& m_shooting_comaand;

};

class WeaponLodingState : public WeaponState
{
public:
	WeaponLodingState();
	virtual ~WeaponLodingState() final;

private:

	//������¿� input�� �ް� �˸´� �����ൿ�� �����ϴ� �Լ�
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//������¿� �Էµ� �̺�Ʈ�� �����ϰ� ���¿� �´� Ư�� �ൿ�� �ϴ� �Լ�
	virtual WeaponState* Update(std::shared_ptr<FuselageCharacter> Character) final;

	//���¿� ���� ȣ���ϴ� �Լ�
	virtual void Enter(std::shared_ptr<FuselageCharacter> Character) final;

private:

	int32 m_loding_count;

};


class WeaponChargingState : public WeaponState
{
public:
	WeaponChargingState() ;
	virtual ~WeaponChargingState() final ;

private:

	//������¿� input�� �ް� �˸´� �����ൿ�� �����ϴ� �Լ�
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//������¿� �Էµ� �̺�Ʈ�� �����ϰ� ���¿� �´� Ư�� �ൿ�� �ϴ� �Լ�
	virtual WeaponState* Update(std::shared_ptr<FuselageCharacter> Character) final;

	//���¿� ���� ȣ���ϴ� �Լ�
	virtual void Enter(std::shared_ptr<FuselageCharacter> Character) final;

private:

	int32 m_charging_count;

};

class WeaponChargingShootState : public WeaponState
{
public:
	WeaponChargingShootState();
	virtual ~WeaponChargingShootState() final ;

private:

	//������¿� input�� �ް� �˸´� �����ൿ�� �����ϴ� �Լ�
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//������¿� �Էµ� �̺�Ʈ�� �����ϰ� ���¿� �´� Ư�� �ൿ�� �ϴ� �Լ�
	virtual WeaponState* Update(std::shared_ptr<FuselageCharacter> Character) final;

	//���¿� ���� ȣ���ϴ� �Լ�
	virtual void Enter(std::shared_ptr<FuselageCharacter> Character) final;

};
