// Fill out your copyright notice in the Description page of Project Settings.


#include "Object.h"

IObject::IObject(const char* Name, const float Speed, USceneComponent* Componenet)
	: m_name(Name), m_speed(Speed), m_componenet(Componenet) {

}


const FVector IObject::GetLocation() {
	return m_componenet->GetComponentLocation();
}

const char* IObject::GetName() const {
	return m_name;
}

float IObject::GetSpeed()const
{
	return m_speed;
}


