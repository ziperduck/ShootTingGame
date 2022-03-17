// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponState.h"

#include "ShootingCommand.h"

void WeaponState::m_knot_command(std::shared_ptr<FuselageCharacter> Character)
{
	checkf(Character.get() != nullptr, TEXT("IPlayerState::m_knot_command Character is nullptr"));

	while (!m_all_command.empty())
	{
		checkf(m_all_command.front() != nullptr, TEXT("IPlayerState::m_knot_command m_all_command is nullptr"));

		m_all_command.front()->execute(Character);
		m_all_command.pop();

	}

}

WeaponLodedState::WeaponLodedState() :m_shooting_comaand(ShootingCommand::ShotAttack::getinstance())
{
	m_update_state = this;
}

WeaponLodedState::~WeaponLodedState(){}

void WeaponLodedState::HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input)
{
	checkf(Character.get() != nullptr, TEXT("WeaponLodedState::HandleInput Character is nullptr"));

	switch (Input)
	{
	case EInputBehavior::SHOOT_PRESSED:
		m_all_command.push(&m_shooting_comaand);
		m_update_state = new WeaponLodingState;
		break;
	default:
		break;
	}

}

WeaponState* WeaponLodedState::Update(std::shared_ptr<FuselageCharacter> Character)
{
	m_knot_command(Character);

	return m_update_state;
}

void WeaponLodedState::Enter(std::shared_ptr<FuselageCharacter> Character)
{

}


WeaponLodingState::WeaponLodingState():m_loding_count(0){}

WeaponLodingState::~WeaponLodingState(){}

void WeaponLodingState::HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input){}

WeaponState* WeaponLodingState::Update(std::shared_ptr<FuselageCharacter> Character)
{
	m_knot_command(Character);

	if (m_loding_time > ++m_loding_count)
	{
		m_update_state = new WeaponLodedState;
	}

	return m_update_state;
}

void WeaponLodingState::Enter(std::shared_ptr<FuselageCharacter> Character)
{
}


WeaponChargingState::WeaponChargingState()
{
}

WeaponChargingState::~WeaponChargingState()
{
}

void WeaponChargingState::HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input)
{
}

WeaponState* WeaponChargingState::Update(std::shared_ptr<FuselageCharacter> Character)
{
	return nullptr;
}

void WeaponChargingState::Enter(std::shared_ptr<FuselageCharacter> Character)
{
}

WeaponChargingShootState::WeaponChargingShootState()
{
}

WeaponChargingShootState::~WeaponChargingShootState()
{
}

void WeaponChargingShootState::HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input)
{
}

WeaponState* WeaponChargingShootState::Update(std::shared_ptr<FuselageCharacter> Character)
{
	return nullptr;
}

void WeaponChargingShootState::Enter(std::shared_ptr<FuselageCharacter> Character)
{
}
