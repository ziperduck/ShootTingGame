// Fill out your copyright notice in the Description page of Project Settings.


#include "Object.h"

const uint16  GetIdentity()
{
	static uint16  Identity = 1000;
	return ++Identity;
}

IObject::IObject(const char* Name, const float Speed, USceneComponent* Componenet)
	: m_name(Name), m_speed(Speed), m_componenet(Componenet), m_identity_num(GetIdentity()) {
}


const uint16  IObject::GetIdentityNumber() const 
{
	return m_identity_num;
}

const FVector IObject::GetLocation()
{
	return m_componenet->GetComponentLocation();
}

const char* IObject::GetName() const {
	return m_name;
}

float IObject::GetSpeed()const
{
	return m_speed;
}


