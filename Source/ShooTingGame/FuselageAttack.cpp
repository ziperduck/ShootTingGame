// Fill out your copyright notice in the Description page of Project Settings.


#include "FuselageAttack.h"
#include "FuselageBaseData.h"

FuselageAttack::FuselageAttack(std::shared_ptr<FuselageData> Fuselage)
	:m_fuselage(Fuselage){}

FuselageAttack::FuselageAttack(const FuselageAttack& Temporary)
	: m_fuselage(Temporary.m_fuselage){}


FuselageAttack::~FuselageAttack()
{
}

bool FuselageAttack::execute(AActor* Actor)
{
	if (Actor == nullptr)
	{
		return false;
	}

	//출돌을 했는지 확인한다.
	if (!Actor->GetActorEnableCollision())
	{
		return false;
	}

	UE_LOG(LogTemp, Log, TEXT("In FuselageAttack"));

	TSet<AActor*> OverlapActors;
	Actor->GetOverlappingActors(OverlapActors);

	for (auto Actor : OverlapActors)
	{
		//충돌한 객체가 Fuselage인지 확인한다.
		IFuselageBaseData* executeActor = Cast<IFuselageBaseData>(Actor);
		if (!executeActor)
		{
			UE_LOG(LogTemp, Log, TEXT("executeActor cast fail"));
			continue;
		}

		std::shared_ptr<FuselageData> executeFuselage = executeActor->GetBaseData();

		//충돌한 Fuselage가 데미지를 줘야하는지 확인한다.
		if (executeFuselage->GetUnion().MatchUnion(m_fuselage->GetUnion()))
		{
			UE_LOG(LogTemp, Log, TEXT("other fuselage Attack"));
			executeFuselage->AddHP(-m_fuselage->GetStatus().GetAttackPower());
		}
	}
	return true;
}
