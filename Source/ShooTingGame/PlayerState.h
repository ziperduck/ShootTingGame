// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageState.h"
#include "Command.h"

class PlayerTakeDamage;

/**
 * �÷��̾ ����ִ� ����
 */
class PlayerLiving : public IFuselageState
{
public:

	PlayerLiving();
	virtual ~PlayerLiving() override;

private:

	virtual IFuselageState* HandleInput(FuselageCharacter& Fuselage, EInputBehavior Input) override;
	virtual void Update(FuselageCharacter& Fuselage) override;

private:

	std::queue<Command*> m_all_command;

	Command* m_left_move_command;
	Command* m_right_move_command;
	Command* m_forward_move_command;
	Command* m_backward_move_command;

	Command* m_collision_command;


};

/**
 * �÷��̾ �������� ���� ����
 */
class PlayerCollide : public IFuselageState
{
public:

	PlayerCollide();
	virtual ~PlayerCollide() override;

private:

	virtual IFuselageState* HandleInput(FuselageCharacter& Fuselage, EInputBehavior Input) override;
	virtual void Update(FuselageCharacter& Fuselage) override;

private:

	std::queue<Command*> m_all_command;

	Command* m_left_move_command;
	Command* m_right_move_command;
	Command* m_forward_move_command;
	Command* m_backward_move_command;

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

	virtual IFuselageState* HandleInput(FuselageCharacter& Fuselage, EInputBehavior Input) override;
	virtual void Update(FuselageCharacter& Fuselage) override;

private:

	std::queue<Command*> m_all_command;

	Command* m_death_command;

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

	virtual IFuselageState* HandleInput(FuselageCharacter& Fuselage, EInputBehavior Input) override;
	virtual void Update(FuselageCharacter& Fuselage) override;

private:

	std::queue<Command*> m_all_command;

	Command* m_shooting_command;

};