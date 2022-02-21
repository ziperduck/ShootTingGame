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

	//�÷��̾ ã�´�.
	IPlayerBaseData* Player
		= Cast<IPlayerBaseData>(Character->GetActor()->GetWorld()->GetFirstPlayerController()->GetPawn());

	//�÷��̾�� ������ �ش�.
	Player->GetPlayerData()->AddScore(m_score);

}

RangeBoom::RangeBoom(const float Radius, const int32 Damage,const float Timer)
 : m_radius(Radius),m_damage(Damage), m_timer(Timer){
}

void RangeBoom::EventPlay(FuselageCharacter* Character)
{
	checkf(Character != nullptr, TEXT("RangeBoom Character is nullptr"));

	const AActor* Actor = Character->GetActor();
	//���� �׸���.
	DrawDebugCircle(Actor->GetWorld(), Actor->GetActorLocation(), m_radius, 40, FColor::Red
		, false, m_timer, 10, 10.0f, FVector::ForwardVector, FVector::RightVector, false);
	//����ȭ Ÿ�̸Ӹ� ����ؼ� �ð��� ������ �������� �ְ� �����ϴ� ����� ����

}
