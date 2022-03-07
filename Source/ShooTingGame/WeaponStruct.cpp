// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponStruct.h"

#include "FuselageBaseData.h"

#include "FuselageCharacter.h"

WeaponStruct::WeaponStruct(UClass* WeaponClass,const int32 WeaponLevel, const float Power, const float LifeSpan, const FVector Scale)
:m_weapon_class(WeaponClass), m_level(WeaponLevel),m_power(Power), m_lifespan(LifeSpan), m_scale(Scale){}


void WeaponStruct::SetLifeSpan(const float LifeSpan)
{
	m_lifespan = LifeSpan;
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


AActor* CheckCreateActor(UClass* ActorClass, AActor* CheckActor)
{
	checkf(CheckActor != nullptr, TEXT("CheckCreateActor Gunner is nullptr "));
	UWorld* CreateWorld = CheckActor->GetWorld();

	checkf(CreateWorld != nullptr, TEXT("CheckCreateActor World is nullptr "));
	AActor* Weapon = CreateWorld->SpawnActor<AActor>(ActorClass, CheckActor->GetActorLocation(), FRotator::ZeroRotator);

	checkf(Weapon != nullptr, TEXT("CreateWeapon SpawnActor is nullptr "));

	return Weapon;
}