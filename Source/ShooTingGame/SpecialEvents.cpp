// Fill out your copyright notice in the Description page of Project Settings.


#include "SpecialEvents.h"

#include "PlayerCharacterData.h"
#include "PlayerBaseData.h"

#include "FuselageCharacter.h"

#include "DrawDebugHelpers.h"
#include "HAL/Event.h"
#include <Engine/Classes/Kismet/GameplayStatics.h>

#include "FuselageBaseData.h"

PlayerRaiseScore::PlayerRaiseScore(const uint32 Score)
	:m_score(Score){}

void PlayerRaiseScore::EventPlay(FuselageCharacter* Character)
{
	checkf(Character != nullptr, TEXT("PlayerRaiseScore Character is nullptr"));

	//플레이어를 찾는다.
	IPlayerBaseData* Player
		= Cast<IPlayerBaseData>(Character->GetActor()->GetWorld()->GetFirstPlayerController()->GetPawn());

	//플레이어에게 점수를 준다.
	Player->GetPlayerData()->AddScore(m_score);

}

RangeBoom::RangeBoom(const float Radius, const float Damage,const float Delay)
 : m_radius(Radius),m_damage(Damage), m_delay(Delay){
}

void RangeBoom::EventPlay(FuselageCharacter* Character)
{
	checkf(Character != nullptr, TEXT("RangeBoom Character is nullptr"));

	const AActor* Actor = Character->GetActor();
	const UWorld* World = Actor->GetWorld();
	FVector ActorLocation = Actor->GetActorLocation();
	//원을 그린다.
	DrawDebugCircle(World, ActorLocation, m_radius, 40, FColor::Red, false, m_delay
		, 10, 10.0f, FVector::ForwardVector, FVector::RightVector, false);
	//동기화 타이머를 사용해서 시간이 지나면 데미지를 주고 종료하는 방식을 쓰자


	//bounds
	FVector Radius = FVector(m_radius, m_radius, 0.0f);
	const float Damage = m_damage;

	FTimerHandle m_boom_timer_handle;
	Actor->GetWorldTimerManager().SetTimer(m_boom_timer_handle,
		[&ActorLocation, &Radius,&Damage] {	TArray<AActor*> BoundsActors;
	UGameplayStatics::GetActorArrayBounds(BoundsActors, true, ActorLocation, Radius);
	for (auto Actor : BoundsActors)
	{
		UE_LOG(LogTemp, Log, TEXT("RangeBoom EventPlay"));

		if (Actor == nullptr)
		{
			continue;
		}
		//충돌한 객체가 Fuselage인지 확인한다.
		IFuselageBaseData* FuselageData = Cast<IFuselageBaseData>(Actor);
		if (!FuselageData)
		{
			continue;
		}

		std::shared_ptr<FuselageCharacter> FuselageCharacter = FuselageData->GetBaseData();

		if (!FuselageCharacter.get())
		{
			continue;
		}

		//충돌한 Fuselage가 데미지를 줘야하는지 확인한다.
		UE_LOG(LogTemp, Log, TEXT("other fuselage Attack"));
		FuselageCharacter->AddHP(-Damage);
	}
	}, m_delay, false);
}

void RandomItemDrop::EventPlay(FuselageCharacter* Character)
{

}
