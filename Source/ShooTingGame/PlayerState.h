// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "FuselageCharacter.h"

#include "Command.h"

#include "EnumPack.h"

/*
* 구분짓기 위해 플레이어의 상태만을 만드는 플레이어 상태 클래스
*/
class IPlayerState
{
public:

	IPlayerState() {};
	virtual ~IPlayerState() = 0 { m_update_state = nullptr; };

	//현재상태에 input을 받고 알맞는 다음행동을 리턴하는 함수
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) =0;

	//현재상태에 입력된 이벤트를 실행하고 상태에 맞는 특정 행동을 하는 함수
	virtual IPlayerState* Update(std::shared_ptr<FuselageCharacter> Character) = 0;

	//상태에 들어설때 호출하는 함수
	virtual void Enter(std::shared_ptr<FuselageCharacter> Character) = 0;

protected:

	void m_knot_command(std::shared_ptr<FuselageCharacter> Character);

protected:

	IPlayerState* m_update_state;

	std::queue<Command*> m_all_command;
};

/**
 * 플레이어가 살아있는 상태
 */
class PlayerLiving : public IPlayerState
{
public:

	PlayerLiving();
	virtual ~PlayerLiving() final;

	//현재상태에 input을 받고 알맞는 다음행동을 리턴하는 함수
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//현재상태에 입력된 이벤트를 실행하고 상태에 맞는 특정 행동을 하는 함수
	virtual IPlayerState* Update(std::shared_ptr<FuselageCharacter> Character) final;

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
class PlayerInvincibility : public IPlayerState
{
public:

	PlayerInvincibility();
	virtual ~PlayerInvincibility() override;

	//현재상태에 input을 받고 알맞는 다음행동을 리턴하는 함수
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//현재상태에 입력된 이벤트를 실행하고 상태에 맞는 특정 행동을 하는 함수
	virtual IPlayerState* Update(std::shared_ptr<FuselageCharacter> Character) final;

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
	Command& m_invincibility_on_command;


	//무적시간을 카운트 한다
	int32 m_time_count;

	//무적시간의 한계
	int32 m_time_bounds;

};

/**
 * 플레이어가 죽은 상태
 */
class PlayerDied: public IPlayerState
{
public:

	PlayerDied();
	virtual ~PlayerDied() override;

	//현재상태에 input을 받고 알맞는 다음행동을 리턴하는 함수
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) final;

	//현재상태에 입력된 이벤트를 실행하고 상태에 맞는 특정 행동을 하는 함수
	virtual IPlayerState* Update(std::shared_ptr<FuselageCharacter> Character) final;

	//상태에 들어설때 호출하는 함수
	virtual void Enter(std::shared_ptr<FuselageCharacter> Character)final;

private:

	Command& m_death_command;

};