// Fill out your copyright notice in the Description page of Project Settings.


#include "FuselageCharacter.h"

FuselageCharacter::FuselageCharacter(const FuselageCharacter& Reference)
	:m_actor(Reference.m_actor),m_base_data(Reference.m_base_data){}

void FuselageCharacter::MoveTo(FVector Direction)
{
	//Z값이 이동하거나 움직이지 않을경우 false를 리턴한다.
	checkf(Direction.Z == 0.0f && Direction != FVector::ZeroVector, TEXT("MoveTo is Direction ZeroVector or Z is zero"));

	//이동할 방향
	Direction = Direction.BoundToCube(1.0f);

	//캐릭터 속도
	float Speed = m_base_data->GetStatus().GetSpeed();

	//이동 함수
	m_actor->SetActorLocation(m_actor->GetActorLocation() + Direction * Speed);
	
}

void FuselageCharacter::AddHP(int32 HP)
{
	//체력을 더한다.
	m_base_data->AddHP(HP);
}

void FuselageCharacter::Shooting()
{

}

void FuselageCharacter::Death()
{
}

void FuselageCharacter::SetWeapon(std::shared_ptr<WeaponStruct> ChangeWeapon)
{
}

const AActor* FuselageCharacter::GetActor() const
{
	return m_actor;
}

const int32 FuselageCharacter::GetCurrentHP() const
{
	return m_base_data->GetCurrentHP();
}

const float FuselageCharacter::GetSpeed() const
{
	return m_base_data->GetStatus().GetSpeed();
}

const int32 FuselageCharacter::GetAttackPower() const
{
	return m_base_data->GetStatus().GetAttackPower();
}

const int8 FuselageCharacter::GetUnion() const
{
	return m_base_data->GetUnion().GetUnion();
}

const int8 FuselageCharacter::GetCollision() const
{
	return m_base_data->GetUnion().GetCollision();
}

FuselageCharacter::FuselageCharacter(AActor* Actor, std::shared_ptr<FuselageData> BaseData)
:m_actor(Actor),m_base_data(BaseData){
}
