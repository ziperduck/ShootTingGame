// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "FuselageState.h"

#include "FuselageCharacter.h"

#include "Command.h"

class PlayerInvincibility;
class PlayerDied;

class PlayerLoaded;


/**
 * �÷��̾ ����ִ� ����
 */
class PlayerLiving : public IFuselageState
{
public:

	PlayerLiving();
	virtual ~PlayerLiving() override;

private:

	//������¿� input�� �ް� �˸´� �����ൿ�� �����ϴ� �Լ�
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//������¿� �Էµ� �̺�Ʈ�� �����ϰ� ���¿� �´� Ư�� �ൿ�� �ϴ� �Լ�
	virtual IFuselageState* Update(std::shared_ptr<FuselageCharacter> Character) final;

	//���¿� ���� ȣ���ϴ� �Լ�
	virtual void Enter(std::shared_ptr<FuselageCharacter> Character)final;
private:

	//������ ���� command
	Command& m_left_move_command;
	Command& m_right_move_command;
	Command& m_forward_move_command;
	Command& m_backward_move_command;

	//�浹 ���� command
	Command& m_collision_command;

	//������ ��ü�ϴ� command
	Command& m_invincibility_off_command;
};

/**
 * �÷��̾ �������� ���� ����
 */
class PlayerInvincibility : public IFuselageState
{
public:

	PlayerInvincibility();
	virtual ~PlayerInvincibility() override;

private:

	//������¿� input�� �ް� �˸´� �����ൿ�� �����ϴ� �Լ�
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//������¿� �Էµ� �̺�Ʈ�� �����ϰ� ���¿� �´� Ư�� �ൿ�� �ϴ� �Լ�
	virtual IFuselageState* Update(std::shared_ptr<FuselageCharacter> Character) final;

	//���¿� ���� ȣ���ϴ� �Լ�
	virtual void Enter(std::shared_ptr<FuselageCharacter> Character)final;

private:

	//������ ���� command
	Command& m_left_move_command;
	Command& m_right_move_command;
	Command& m_forward_move_command;
	Command& m_backward_move_command;

	//������ ��ü�ϴ� command
	Command& m_invincibility_on_command;
	
	//�����ð��� ī��Ʈ �Ѵ�
	int32 m_time_count;

	//�����ð��� �Ѱ�
	int32 m_time_bounds;

};

/**
 * �÷��̾ ���� ����
 */
class PlayerDied: public IFuselageState
{
public:

	PlayerDied();
	virtual ~PlayerDied() override;

private:

	//������¿� input�� �ް� �˸´� �����ൿ�� �����ϴ� �Լ�
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//������¿� �Էµ� �̺�Ʈ�� �����ϰ� ���¿� �´� Ư�� �ൿ�� �ϴ� �Լ�
	virtual IFuselageState* Update(std::shared_ptr<FuselageCharacter> Character) final;

	//���¿� ���� ȣ���ϴ� �Լ�
	virtual void Enter(std::shared_ptr<FuselageCharacter> Character)final;
private:

	Command& m_death_command;

};

/**
 * �÷��̾ ���Ⱑ ������ ����
 */
class PlayerLoaded : public IFuselageState
{
public:

	PlayerLoaded();
	virtual ~PlayerLoaded() override;

private:

	//������¿� input�� �ް� �˸´� �����ൿ�� �����ϴ� �Լ�
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//������¿� �Էµ� �̺�Ʈ�� �����ϰ� ���¿� �´� Ư�� �ൿ�� �ϴ� �Լ�
	virtual IFuselageState* Update(std::shared_ptr<FuselageCharacter> Character) final;

	//���¿� ���� ȣ���ϴ� �Լ�
	virtual void Enter(std::shared_ptr<FuselageCharacter> Character)final;
private:

	Command& m_shooting_command;

};