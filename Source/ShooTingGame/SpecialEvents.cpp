// Fill out your copyright notice in the Description page of Project Settings.


#include "SpecialEvents.h"

#include "PlayerCharacterData.h"
#include "PlayerBaseData.h"

#include "FuselageCharacter.h"

#include "DrawDebugHelpers.h"


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

RangeBoom::RangeBoom(const float Radius, const int32 Damage,const float Timer)
 : m_radius(Radius),m_damage(Damage), m_timer(Timer){
}

void RangeBoom::EventPlay(FuselageCharacter* Character)
{
	checkf(Character != nullptr, TEXT("RangeBoom Character is nullptr"));

	const AActor* Actor = Character->GetActor();
	//원을 그린다.
	DrawDebugCircle(Actor->GetWorld(), Actor->GetActorLocation(), m_radius, 40, FColor::Red
		, false, m_timer, 10, 10.0f, FVector::ForwardVector, FVector::RightVector, false);
	//동기화 타이머를 사용해서 시간이 지나면 데미지를 주고 종료하는 방식을 쓰자

}
