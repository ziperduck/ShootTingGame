// Fill out your copyright notice in the Description page of Project Settings.

#include "Action.h"
#include "Character.h"

ActorCharacter::ActorCharacter
(const char* Name, const int8 Max_HP, const float Speed, AActor* Actor)
	: IObject(Name, Speed, Actor), m_max_HP(Max_HP),m_current_HP(Max_HP)
{}
//ActorCharacter::ActorCharacter
//(const char* Name, const int8 Max_HP, const float Speed,const UStaticMesh* Mesh,const FColor& Color, const CharaterWeapon * Weapon)
//	: Object(Name, Max_HP, Speed, new CharaterAppearance(Mesh, Color)), m_weapon(Weapon)
//{}


ActorCharacter::~ActorCharacter()
{
}

const int8 ActorCharacter::GetMaxHP()const
{
	return m_max_HP;
}

const int8 ActorCharacter::GetCurrentHP()const
{
	return m_current_HP;
}


const CharaterWeapon* ActorCharacter::GetWeapon()const
{
	return m_weapon;
}

bool ActorCharacter::Is_Collision() {
	return true;
}

void ActorCharacter::Update() {
	UE_LOG(LogTemp, Log, TEXT("m_actions size %d"), m_actions.size());
	while (!m_actions.empty())
	{
		m_actions.front()->execute(this);
		m_actions.pop();
	}
}
void ActorCharacter::AddAction(std::shared_ptr<IAction> Action) {

	m_actions.push(Action);

}

