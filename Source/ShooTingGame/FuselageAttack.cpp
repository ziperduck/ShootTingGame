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

	//�⵹�� �ߴ��� Ȯ���Ѵ�.
	if (!Actor->GetActorEnableCollision())
	{
		return false;
	}

	UE_LOG(LogTemp, Log, TEXT("In FuselageAttack"));

	TSet<AActor*> OverlapActors;
	Actor->GetOverlappingActors(OverlapActors);

	for (auto Actor : OverlapActors)
	{
		//�浹�� ��ü�� Fuselage���� Ȯ���Ѵ�.
		IFuselageBaseData* executeActor = Cast<IFuselageBaseData>(Actor);
		if (!executeActor)
		{
			UE_LOG(LogTemp, Log, TEXT("executeActor cast fail"));
			continue;
		}

		std::shared_ptr<FuselageData> executeFuselage = executeActor->GetBaseData();

		//�浹�� Fuselage�� �������� ����ϴ��� Ȯ���Ѵ�.
		if (executeFuselage->GetUnion().MatchUnion(m_fuselage->GetUnion()))
		{
			UE_LOG(LogTemp, Log, TEXT("other fuselage Attack"));
			executeFuselage->AddHP(-m_fuselage->GetStatus().GetAttackPower());
		}
	}
	return true;
}
