// Fill out your copyright notice in the Description page of Project Settings.


#include "Action.h"
#include "Weapon.h"

RifleGun::RifleGun
(const ObjectKind Kind, const int8 Max_HP, const float Speed, const int16 Damage,USceneComponent* Component)
	:m_kind(Kind), m_identity_num(GetIdentity()), m_speed(Speed), m_damage(Damage)
	, m_max_HP(Max_HP), m_current_HP(Max_HP), m_componenet(Component)
{}
//RifleGun::RifleGun
//(const char* Name, const int8 Max_HP, const float Speed,const UStaticMesh* Mesh,const FColor& Color, const CharaterWeapon * Weapon)
//	: Object(Name, Max_HP, Speed, new CharaterAppearance(Mesh, Color)), m_weapon(Weapon)
//{}


RifleGun::~RifleGun()
{
}

const uint16 RifleGun::GetIdentityNumber() const
{
	return m_identity_num;
}

const ObjectKind RifleGun::GetKind() const
{
	return m_kind;
}

const float RifleGun::GetSpeed() const
{
	return m_speed;
}

const FVector RifleGun::GetLocation() const
{
	return m_componenet->GetComponentLocation();
}

const int8 RifleGun::GetMaxHP()const
{
	return m_max_HP;
}

const int8 RifleGun::GetCurrentHP()const
{
	return m_current_HP;
}

UWorld* RifleGun::GetWorld() const
{
	return m_componenet->GetWorld();
}
std::shared_ptr<IObject> RifleGun::GetWeapon()
{
	return nullptr;
}


void RifleGun::SetLocation(const FVector& MoveLocation) {
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


void RifleGun::AddAction(std::shared_ptr<IAction> Action) 
{
	m_actions.push(Action);
}

void RifleGun::AddAnimation(std::queue<std::queue<std::shared_ptr<IAction>>> Animation)
{
	m_animation = Animation;
}

void RifleGun::Update() {

	UE_LOG(LogTemp, Log, TEXT("m_actions size %d"), m_actions.size());
	while (!m_actions.empty())
	{
		m_actions.front()->execute(this);
		m_actions.pop();
	}
	m_actions.push(m_animation.front().front());
	m_animation.front().pop();
}


