// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerState.h"

#include "MoveCommand.h"
#include "CollisionCommand.h"
#include "DeathCommand.h"

PlayerLiving::PlayerLiving()
: m_left_move_command(new MoveCommand::LeftMove), m_right_move_command(new MoveCommand::RightMove),
m_forward_move_command(new MoveCommand::ForwardMove), m_backward_move_command(new MoveCommand::BackwardMove),
m_collision_command(new MoveCommand::AttatchMove){}

PlayerLiving::~PlayerLiving()
{
}

IFuselageState* PlayerLiving::HandleInput(FuselageCharacter& Fuselage, EInputBehavior Input)
{


	return nullptr;
}

void PlayerLiving::Update(FuselageCharacter& Fuselage)
{
	while (!m_all_command.empty())
	{
	}

}

PlayerCollide::PlayerCollide()
	: m_left_move_command(new MoveCommand::LeftMove), m_right_move_command(new MoveCommand::RightMove),
	m_forward_move_command(new MoveCommand::ForwardMove), m_backward_move_command(new MoveCommand::BackwardMove){}

PlayerCollide::~PlayerCollide()
{
}

IFuselageState* PlayerCollide::HandleInput(FuselageCharacter& Fuselage, EInputBehavior Input)
{
	return nullptr;
}

void PlayerCollide::Update(FuselageCharacter& Fuselage)
{
}

PlayerDied::PlayerDied() : m_death_command(new DeathCommand::PlayerDie)
{
}

PlayerDied::~PlayerDied()
{
}

IFuselageState* PlayerDied::HandleInput(FuselageCharacter& Fuselage, EInputBehavior Input)
{
	return nullptr;
}

void PlayerDied::Update(FuselageCharacter& Fuselage)
{
}

PlayerLoaded::PlayerLoaded()
{
}

PlayerLoaded::~PlayerLoaded()
{
}

IFuselageState* PlayerLoaded::HandleInput(FuselageCharacter& Fuselage, EInputBehavior Input)
{
	return nullptr;
}

void PlayerLoaded::Update(FuselageCharacter& Fuselage)
{
}
