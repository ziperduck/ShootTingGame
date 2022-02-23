// Fill out your copyright notice in the Description page of Project Settings.


#include "FuselageCharacter.h"

FuselageCharacter::FuselageCharacter(const FuselageCharacter& Reference)
	:m_actor(Reference.m_actor),m_base_data(Reference.m_base_data){}

void FuselageCharacter::MoveTo(FVector Direction)
{
	checkf(m_actor != nullptr, TEXT("FuselageRemove Character is nullptr"));

	//Z값이 이동하거나 움직이지 않을경우 false를 리턴한다.
	if (Direction.Z == 0.0f && Direction != FVector::ZeroVector)
	{
		UE_LOG(LogTemp, Log, TEXT("MoveTo is Direction ZeroVector or Z is zero"));
	}

	//이동할 방향
	Direction = Direction.BoundToCube(1.0f);

	//캐릭터 속도
	float Speed = m_base_data->GetStatus().GetSpeed();

	//이동 함수
	m_actor->SetActorLocation(m_actor->GetActorLocation() + Direction * Speed);
	
}

void FuselageCharacter::AddHP(float HP)
{
	//체력을 더한다.
	m_base_data->AddHP(HP);
}

void FuselageCharacter::Shooting()
{

}

void FuselageCharacter::Death()
{
	UE_LOG(LogTemp, Log, TEXT("FuselageCharacter Death"));
	checkf(m_actor != nullptr, TEXT("FuselageRemove Character is nullptr"));

	//이벤트를 실행시킨다.
	for(auto Evnt : m_death_events)
	{
		checkf(Evnt.get() != nullptr, TEXT("FuselageCharacter Death Event is nullptr"));
		Evnt->EventPlay(this);
	}

	UE_LOG(LogTemp, Log, TEXT("befor Character->Destroy()"));
	m_actor->Destroy();
	UE_LOG(LogTemp, Log, TEXT("after Character->Destroy()"));
	
}

void FuselageCharacter::SetWeapon(std::shared_ptr<WeaponStruct> ChangeWeapon)
{
}

void FuselageCharacter::SetDeathEvent(std::vector<std::shared_ptr<SpecialEvent>> DeathEvents)
{
	m_death_events = DeathEvents;
}

void FuselageCharacter::AddDeathEvent(std::shared_ptr<SpecialEvent> DeathEvent)
{
	m_death_events.push_back(DeathEvent);
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
