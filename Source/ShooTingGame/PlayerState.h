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
 * 플레이어가 살아있는 상태
 */
class PlayerLiving : public IFuselageState
{
public:

	PlayerLiving();
	virtual ~PlayerLiving() override;

private:

	//현재상태에 input을 받고 알맞는 다음행동을 리턴하는 함수
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//현재상태에 입력된 이벤트를 실행하고 상태에 맞는 특정 행동을 하는 함수
	virtual IFuselageState* Update(std::shared_ptr<FuselageCharacter> Character) final;

	//상태에 들어설때 호출하는 함수
	virtual void Enter(std::shared_ptr<FuselageCharacter> Character)final;
private:

	//움직임 관련 command
	Command& m_left_move_command;
	Command& m_right_move_command;
	Command& m_forward_move_command;
	Command& m_backward_move_command;

	//충돌 관련 command
	Command& m_collision_command;

	//무적을 해체하는 command
	Command& m_invincibility_off_command;
};

/**
 * 플레이어가 데미지를 받은 상태
 */
class PlayerInvincibility : public IFuselageState
{
public:

	PlayerInvincibility();
	virtual ~PlayerInvincibility() override;

private:

	//현재상태에 input을 받고 알맞는 다음행동을 리턴하는 함수
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//현재상태에 입력된 이벤트를 실행하고 상태에 맞는 특정 행동을 하는 함수
	virtual IFuselageState* Update(std::shared_ptr<FuselageCharacter> Character) final;

	//상태에 들어설때 호출하는 함수
	virtual void Enter(std::shared_ptr<FuselageCharacter> Character)final;

private:

	//움직임 관련 command
	Command& m_left_move_command;
	Command& m_right_move_command;
	Command& m_forward_move_command;
	Command& m_backward_move_command;

	//무적을 해체하는 command
	Command& m_invincibility_on_command;
	
	//무적시간을 카운트 한다
	int32 m_time_count;

	//무적시간의 한계
	int32 m_time_bounds;

};

/**
 * 플레이어가 죽은 상태
 */
class PlayerDied: public IFuselageState
{
public:

	PlayerDied();
	virtual ~PlayerDied() override;

private:

	//현재상태에 input을 받고 알맞는 다음행동을 리턴하는 함수
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//현재상태에 입력된 이벤트를 실행하고 상태에 맞는 특정 행동을 하는 함수
	virtual IFuselageState* Update(std::shared_ptr<FuselageCharacter> Character) final;

	//상태에 들어설때 호출하는 함수
	virtual void Enter(std::shared_ptr<FuselageCharacter> Character)final;
private:

	Command& m_death_command;

};

/**
 * 플레이어가 무기가 장전된 상태
 */
class PlayerLoaded : public IFuselageState
{
public:

	PlayerLoaded();
	virtual ~PlayerLoaded() override;

private:

	//현재상태에 input을 받고 알맞는 다음행동을 리턴하는 함수
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//현재상태에 입력된 이벤트를 실행하고 상태에 맞는 특정 행동을 하는 함수
	virtual IFuselageState* Update(std::shared_ptr<FuselageCharacter> Character) final;

	//상태에 들어설때 호출하는 함수
	virtual void Enter(std::shared_ptr<FuselageCharacter> Character)final;
private:

	Command& m_shooting_command;

};