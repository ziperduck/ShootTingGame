// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerState.h"

#include "MoveCommand.h"
#include "CollisionCommand.h"
#include "DeathCommand.h"
#include "ShootingCommand.h"


void IPlayerState::m_knot_command(std::shared_ptr<FuselageCharacter> Character)
{
	checkf(Character.get() != nullptr, TEXT("IPlayerState::m_knot_command Character is nullptr"));

	while (!m_all_command.empty())
	{
		checkf(m_all_command.front() != nullptr, TEXT("IPlayerState::m_knot_command m_all_command is nullptr"));
		
		m_all_command.front()->execute(Character);
		m_all_command.pop();

	}

}


PlayerLiving::PlayerLiving()
: IPlayerState(),
	m_left_move_command(MoveCommand::LeftMove::getinstance()), m_right_move_command(MoveCommand::RightMove::getinstance()),
m_forward_move_command(MoveCommand::ForwardMove::getinstance()), m_backward_move_command(MoveCommand::BackwardMove::getinstance()),
m_invincibility_off_command(CollisionCommand::CollisionInvincibilityOff::getinstance()),
m_collision_command(CollisionCommand::CollisionAttack::getinstance())
{
	m_update_state = this;
}

PlayerLiving::~PlayerLiving()
{

}

void PlayerLiving::HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input)
{
	checkf(Character.get() != nullptr, TEXT("PlayerLiving::HandleInput Character is nullptr"));

	switch (Input)
	{
	case EInputBehavior::LEFT_MOVE:
		m_all_command.push(&m_left_move_command);
		break;
	case EInputBehavior::RIGHT_MOVE:
		m_all_command.push(&m_right_move_command);
		break;
	case EInputBehavior::FORWARD_MOVE:
		m_all_command.push(&m_forward_move_command);
		break;
	case EInputBehavior::BACKWARD_MOVE:
		m_all_command.push(&m_backward_move_command);
		break;
	case EInputBehavior::COLLISION:
		UE_LOG(LogTemp, Log, TEXT("Player Collision"));
		m_all_command.push(&m_collision_command);
		if (Character->GetCurrentHP() <= 0.0f)
		{
			m_update_state = new PlayerDied;
		}
		else
		{
			m_update_state = new PlayerInvincibility;
		}

		break;
	default:
		break;
	}

}

IPlayerState* PlayerLiving::Update(std::shared_ptr<FuselageCharacter> Character)
{
	//모든 커맨드를 푼다.
	m_knot_command(Character);

	return m_update_state;
}

void PlayerLiving::Enter(std::shared_ptr<FuselageCharacter> Character)
{
	m_all_command.push(&m_invincibility_off_command);
}

PlayerInvincibility::PlayerInvincibility()
	: m_left_move_command(MoveCommand::LeftMove::getinstance()), m_right_move_command(MoveCommand::RightMove::getinstance()),
	m_forward_move_command(MoveCommand::ForwardMove::getinstance()), m_backward_move_command(MoveCommand::BackwardMove::getinstance()),
	m_invincibility_on_command(CollisionCommand::CollisionInvincibilityOn::getinstance()),
	m_collision_command(CollisionCommand::CollisionAttack::getinstance()),
	m_time_bounds(200), m_time_count(0)
{
	m_update_state = this;
}

PlayerInvincibility::~PlayerInvincibility()
{

}
void PlayerInvincibility::HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input)
{
	checkf(Character.get() != nullptr, TEXT("PlayerInvincibility::HandleInput Character is nullptr"));

	switch (Input)
	{
	case EInputBehavior::LEFT_MOVE:
		m_all_command.push(&m_left_move_command);
		break;
	case EInputBehavior::RIGHT_MOVE:
		m_all_command.push(&m_right_move_command);
		break;
	case EInputBehavior::FORWARD_MOVE:
		m_all_command.push(&m_forward_move_command);
		break;
	case EInputBehavior::BACKWARD_MOVE:
		m_all_command.push(&m_backward_move_command);
		break;
	case EInputBehavior::COLLISION:
		UE_LOG(LogTemp, Log, TEXT("Player Collision"));
		m_all_command.push(&m_collision_command);
		break;
	default:
		break;
	}

}

IPlayerState* PlayerInvincibility::Update(std::shared_ptr<FuselageCharacter> Character)
{

	if (m_time_bounds < ++m_time_count)
	{
		m_update_state = new PlayerLiving;
	}

	//모든 커맨드를 푼다.
	m_knot_command(Character);

	return m_update_state;
}

void PlayerInvincibility::Enter(std::shared_ptr<FuselageCharacter> Character)
{
	m_all_command.push(&m_invincibility_on_command);
}

PlayerDied::PlayerDied() : m_death_command(DeathCommand::PlayerDie::getinstance())
{
	m_update_state = this;
}

PlayerDied::~PlayerDied()
{

}

void PlayerDied::HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input)
{
}

IPlayerState* PlayerDied::Update(std::shared_ptr<FuselageCharacter> Character)
{
	m_knot_command(Character);
	return m_update_state;
}

void PlayerDied::Enter(std::shared_ptr<FuselageCharacter> Character)
{
	m_all_command.push(&m_death_command);
}