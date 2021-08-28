// Fill out your copyright notice in the Description page of Project Settings.


#include "Object.h"

IObject::IObject(const char* Name, const float Speed, AActor* Actor)
	: m_name(Name), m_speed(Speed), m_actor(Actor) {

}

void IObject::SetLocation(const FVector& MoveLocation) {

	m_actor->SetActorLocation(MoveLocation);

}

const FVector IObject::GetLocation() {
	return m_actor->GetActorLocation();
}

const char* IObject::GetName() const {
	return m_name;
}

float IObject::GetSpeed()const
{
	return m_speed;
}


