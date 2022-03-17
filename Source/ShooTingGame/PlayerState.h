// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "FuselageCharacter.h"

#include "Command.h"

#include "EnumPack.h"

/*
* �������� ���� �÷��̾��� ���¸��� ����� �÷��̾� ���� Ŭ����
*/
class IPlayerState
{
public:

	IPlayerState() {};
	virtual ~IPlayerState() = 0 { m_update_state = nullptr; };

	//������¿� input�� �ް� �˸´� �����ൿ�� �����ϴ� �Լ�
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) =0;

	//������¿� �Էµ� �̺�Ʈ�� �����ϰ� ���¿� �´� Ư�� �ൿ�� �ϴ� �Լ�
	virtual IPlayerState* Update(std::shared_ptr<FuselageCharacter> Character) = 0;

	//���¿� ���� ȣ���ϴ� �Լ�
	virtual void Enter(std::shared_ptr<FuselageCharacter> Character) = 0;

protected:

	void m_knot_command(std::shared_ptr<FuselageCharacter> Character);

protected:

	IPlayerState* m_update_state;

	std::queue<Command*> m_all_command;
};

/**
 * �÷��̾ ����ִ� ����
 */
class PlayerLiving : public IPlayerState
{
public:

	PlayerLiving();
	virtual ~PlayerLiving() final;

	//������¿� input�� �ް� �˸´� �����ൿ�� �����ϴ� �Լ�
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//������¿� �Էµ� �̺�Ʈ�� �����ϰ� ���¿� �´� Ư�� �ൿ�� �ϴ� �Լ�
	virtual IPlayerState* Update(std::shared_ptr<FuselageCharacter> Character) final;

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
class PlayerInvincibility : public IPlayerState
{
public:

	PlayerInvincibility();
	virtual ~PlayerInvincibility() override;

	//������¿� input�� �ް� �˸´� �����ൿ�� �����ϴ� �Լ�
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//������¿� �Էµ� �̺�Ʈ�� �����ϰ� ���¿� �´� Ư�� �ൿ�� �ϴ� �Լ�
	virtual IPlayerState* Update(std::shared_ptr<FuselageCharacter> Character) final;

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
	Command& m_invincibility_on_command;


	//�����ð��� ī��Ʈ �Ѵ�
	int32 m_time_count;

	//�����ð��� �Ѱ�
	int32 m_time_bounds;

};

/**
 * �÷��̾ ���� ����
 */
class PlayerDied: public IPlayerState
{
public:

	PlayerDied();
	virtual ~PlayerDied() override;

	//������¿� input�� �ް� �˸´� �����ൿ�� �����ϴ� �Լ�
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//������¿� �Էµ� �̺�Ʈ�� �����ϰ� ���¿� �´� Ư�� �ൿ�� �ϴ� �Լ�
	virtual IPlayerState* Update(std::shared_ptr<FuselageCharacter> Character) final;

	//���¿� ���� ȣ���ϴ� �Լ�
	virtual void Enter(std::shared_ptr<FuselageCharacter> Character)final;

private:

	Command& m_death_command;

};