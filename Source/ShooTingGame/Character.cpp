// Fill out your copyright notice in the Description page of Project Settings.

#include "Action.h"
#include "Character.h"

const uint16  GetIdentity()
{
	static uint16  Identity = 1000;
	return ++Identity;
}

ActorCharacter::ActorCharacter
(const ObjectKind Kind, const int8 Max_HP, const float Speed, USceneComponent* Component, IObject* Object)
	:m_kind(Kind), m_identity_num(GetIdentity()), m_speed(Speed), m_max_HP(Max_HP), m_current_HP(Max_HP)
	,m_componenet(Component), m_weapon(Object)
{}
//ActorCharacter::ActorCharacter
//(const char* Name, const int8 Max_HP, const float Speed,const UStaticMesh* Mesh,const FColor& Color, const CharaterWeapon * Weapon)
//	: Object(Name, Max_HP, Speed, new CharaterAppearance(Mesh, Color)), m_weapon(Weapon)
//{}


ActorCharacter::~ActorCharacter()
{
}

const uint16 ActorCharacter::GetIdentityNumber() const
{
	return m_identity_num;
}

const ObjectKind ActorCharacter::GetKind() const
{
	return m_kind;
}

const float ActorCharacter::GetSpeed() const
{
	return m_speed;
}

const FVector ActorCharacter::GetLocation() const
{
	return m_componenet->GetComponentLocation();
}

const int8 ActorCharacter::GetMaxHP()const
{
	return m_max_HP;
}

const int8 ActorCharacter::GetCurrentHP()const
{
	return m_current_HP;
}

std::shared_ptr<IObject> ActorCharacter::GetWeapon()
{
	return m_weapon;
}

UWorld* ActorCharacter::GetWorld() const
{
	return m_componenet->GetWorld();
}


void ActorCharacter::SetLocation(const FVector& MoveLocation) {
	/*
	* setLocatino은 충돌처리를 못하고 랜더링 값을 가지고있기때문에
	* USceneComponenet를 이용해 충돌처리와 이동을 같이 처리하게 만들었다.
	*/

	FHitResult Hit(1.f);
	if (m_componenet == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("componenet is nullptr"));
		return;
	}
	m_componenet->MoveComponent(MoveLocation, m_componenet->GetComponentRotation(), true, &Hit);
	if (Hit.IsValidBlockingHit())
	{
		UE_LOG(LogTemp, Log, TEXT("is Hit Actor"));
	}
}


void ActorCharacter::AddAction(std::shared_ptr<IAction> Action) 
{
	m_actions.push(Action);
}

void ActorCharacter::AddAnimation(std::queue<std::queue<std::shared_ptr<IAction>>> Animation)
{
	m_animation = Animation;
}

void ActorCharacter::Update() {

	UE_LOG(LogTemp, Log, TEXT("m_actions size %d"), m_actions.size());
	while (!m_actions.empty())
	{
		m_actions.front()->execute(this);
		m_actions.pop();
	}
	m_actions.push(m_animation.front().front());
	m_animation.front().pop();
}




