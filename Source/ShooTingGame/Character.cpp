// Fill out your copyright notice in the Description page of Project Settings.

#include "Movement.h"
#include "Character.h"

PlayerCharacter::PlayerCharacter
(const char* Name, const int8 Max_HP, const float Speed, AActor* Actor)
	: IObject(Name, Speed, Actor), m_max_HP(Max_HP)
{}
//PlayerCharacter::PlayerCharacter
//(const char* Name, const int8 Max_HP, const float Speed,const UStaticMesh* Mesh,const FColor& Color, const CharaterWeapon * Weapon)
//	: Object(Name, Max_HP, Speed, new CharaterAppearance(Mesh, Color)), m_weapon(Weapon)
//{}


PlayerCharacter::~PlayerCharacter()
{
}

const int8 PlayerCharacter::GetMaxHP()const
{
	return m_max_HP;
}

const int8 PlayerCharacter::GetCurrentHP()const
{
	return m_current_HP;
}


const CharaterWeapon* PlayerCharacter::GetWeapon()const
{
	return m_weapon;
}

bool PlayerCharacter::Is_Collision() {
	return true;
}

void PlayerCharacter::Update() {

}
void PlayerCharacter::AddAction(std::shared_ptr<Actions> Action) {

	m_actions.push(Action);

}

