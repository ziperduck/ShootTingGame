// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponStruct.h"

#include "FuselageBaseData.h"

#include "FuselageCharacter.h"

WeaponStruct::WeaponStruct(UClass* WeaponClass, IWeaponState* WeaponState
	,const int32 WeaponLevel, const float Power, const float LifeSpan, const FVector Scale)
:m_weapon_class(WeaponClass), m_weapon_state(WeaponState)
, m_level(WeaponLevel),m_power(Power), m_lifespan(LifeSpan), m_scale(Scale){}


void WeaponStruct::SetLifeSpan(const float LifeSpan)
{
	m_lifespan = LifeSpan;
}

void WeaponStruct::HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input)
{
	m_weapon_state->HandleInput(Character, Input);
}

void WeaponStruct::Update(std::shared_ptr<FuselageCharacter> Character)
{

	IWeaponState* UpdateState = m_weapon_state->Update(Character);

	if (m_weapon_state != UpdateState)
	{
		UE_LOG(LogTemp, Log, TEXT("UpdateState"));
		std::swap(m_weapon_state, UpdateState);
		delete(UpdateState);

	}
}

const int32 WeaponStruct::GetWeaponLevel() const
{
	return m_level;
}

const float WeaponStruct::GetPower()const
{
	return m_power;
}

const float WeaponStruct::GetLifeSpan() const
{
	return m_lifespan;
}

const FVector WeaponStruct::GetScale() const
{
	return m_scale;
}

const UClass* WeaponStruct::GetUClass() const
{
	return m_weapon_class;
}


AActor* CheckCreateActor(UClass* ActorClass, AActor* CheckActor)
{
	checkf(CheckActor != nullptr, TEXT("CheckCreateActor Gunner is nullptr "));
	UWorld* CreateWorld = CheckActor->GetWorld();

	checkf(CreateWorld != nullptr, TEXT("CheckCreateActor World is nullptr "));
	AActor* Weapon = CreateWorld->SpawnActor<AActor>(ActorClass, CheckActor->GetActorLocation(), FRotator::ZeroRotator);

	checkf(Weapon != nullptr, TEXT("CreateWeapon SpawnActor is nullptr "));

	return Weapon;
}