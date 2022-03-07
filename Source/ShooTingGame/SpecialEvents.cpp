// Fill out your copyright notice in the Description page of Project Settings.


#include "SpecialEvents.h"

#include "FuselageBaseData.h"

#include "PlayerBaseData.h"
#include "PlayerCharacterData.h"

#include "FuselageCharacter.h"

#include <DrawDebugHelpers.h>
#include <HAL/Event.h>
#include <Engine/Classes/Kismet/GameplayStatics.h>

#include <random>

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

	checkf(Character != nullptr, TEXT("RandomItemDrop Parameter Character is nullptr"));
	UE_LOG(LogTemp, Log, TEXT("RandomItemDrop EventPlay"));

	//랜덤 난수 생성
	std::random_device Device;
	std::mt19937 Gen(Device());

	std::uniform_int_distribution<int32> Dis{ 0,2 };

	int32 RandomNum = Dis(Gen);

	//int32 RandomNum = FMath::RandRange(0, 2);
	// 
	//생성할 월드
	UWorld* SpawnWorld = Character->GetActor()->GetWorld();

	UE_LOG(LogTemp, Log, TEXT("RandomNum %d"), RandomNum);

	switch (RandomNum)
	{
	case 1:
		SpawnWorld->SpawnActor<AActor>(StaticLoadClass(UObject::StaticClass(), NULL,
			TEXT("Class'/Game/Blueprint/BP_TestHealKit.BP_TestHealKit_C'"))
			, Character->GetActor()->GetActorLocation(), FRotator::ZeroRotator);
		break;
	case 2:
		SpawnWorld->SpawnActor<AActor>(StaticLoadClass(UObject::StaticClass(), NULL,
			TEXT("Class'/Game/Blueprint/BP_TestHealKit.BP_TestHealKit_C'"))
			, Character->GetActor()->GetActorLocation(), FRotator::ZeroRotator);
		break;
	default:
		break;
	}
}

void PairDivide::EventPlay(FuselageCharacter* Character)
{
	checkf(Character != nullptr, TEXT("PairDivide Parameter Character is nullptr"));
	UE_LOG(LogTemp, Log, TEXT("PairDivide EventPlay"));

	//받은 엑트를 표본으로 만들고 크기를 조절한다.
	const AActor* ModelActor = Character->GetActor();
	UWorld* SpawnWorld = ModelActor->GetWorld();

	//엑터의 ActorScale 3D값을 가지고 분열을 했는지 확인한다(scale값이 1이 아닌지 확인한다.
	if (ModelActor->GetActorScale() == FVector::OneVector) {

		UE_LOG(LogTemp, Log, TEXT("PairDivide"));

		AActor* DivideActor = SpawnWorld->SpawnActor<AActor>(ModelActor->GetClass()
			, ModelActor->GetActorLocation() + FVector(0.0f, 32.0f, 0.0f), FRotator::ZeroRotator);

		DivideActor->SetActorScale3D(DivideActor->GetActorScale() * 0.5f);

		DivideActor = SpawnWorld->SpawnActor<AActor>(ModelActor->GetClass()
			, ModelActor->GetActorLocation() - FVector(0.0f, 32.0f, 0.0f), FRotator::ZeroRotator);

		DivideActor->SetActorScale3D(DivideActor->GetActorScale() * 0.5f);

	}


}
