// Fill out your copyright notice in the Description page of Project Settings.


#include "FuselageState.h"

void IFuselageState::m_knot_command(std::shared_ptr<FuselageCharacter> Character)
{

	UE_LOG(LogTemp, Log, TEXT("Player m_knot_command"));
	checkf(Character.get() != nullptr, TEXT("m_knot_command Character is nullptr"));

	while (!m_all_command.empty())
	{
		checkf(m_all_command.front() != nullptr, TEXT("m_knot_command m_all_command is nullptr"));

		m_all_command.front()->execute(Character);
		m_all_command.pop();
	}

}
