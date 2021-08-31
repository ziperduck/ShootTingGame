// Fill out your copyright notice in the Description page of Project Settings.

#include "Action.h"
#include "Character.h"

ActorCharacter::ActorCharacter
(const char* Name, const int8 Max_HP, const float Speed, USceneComponent* Component)
	: IObject(Name, Speed, Component), m_max_HP(Max_HP),m_current_HP(Max_HP)
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
void ActorCharacter::SetLocation(const FVector& MoveLocation) {
	/*
	* setLocatino은 충돌처리를 못하고 랜더링 값을 가지고있기때문에
	* USceneComponenet를 이용해 충돌처리와 이동을 같이 처리하게 만들었다.
	*/
	
	FHitResult Hit(1.f);
	m_componenet->MoveComponent(MoveLocation, m_componenet->GetComponentRotation(), true, &Hit);
	if (Hit.IsValidBlockingHit())
	{
		UE_LOG(LogTemp, Log, TEXT("is Hit Actor"));
	}
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

