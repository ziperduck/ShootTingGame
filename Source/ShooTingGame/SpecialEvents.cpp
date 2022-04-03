// Fill out your copyright notice in the Description page of Project Settings.


#include "SpecialEvents.h"

#include "FuselageBaseData.h"

#include "PlayerBaseData.h"
#include "PlayerCharacterData.h"

#include "FuselageCharacter.h"

#include "ShootingGameMode.h"

#include <DrawDebugHelpers.h>
#include <HAL/Event.h>
#include <Engine/Classes/Kismet/GameplayStatics.h>

#include <random>

PlayerRaiseScore::PlayerRaiseScore(const uint32 Score)
	:m_score(Score){}

void PlayerRaiseScore::EventPlay(FuselageCharacter* Character)
{
	checkf(Character != nullptr, TEXT("PlayerRaiseScore Character is nullptr"));

	//�÷��̾ ã�´�.
	IPlayerBaseData* Player
		= Cast<IPlayerBaseData>(Character->GetActor()->GetWorld()->GetFirstPlayerController()->GetPawn());
	if (Player == nullptr)
	{
		return;
	}
	//�÷��̾�� ������ �ش�.
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
	//���� �׸���.
	DrawDebugCircle(World, ActorLocation, m_radius, 40, FColor::Red, false, m_delay
		, 10, 10.0f, FVector::RightVector,FVector::ForwardVector, false);
	//����ȭ Ÿ�̸Ӹ� ����ؼ� �ð��� ������ �������� �ְ� �����ϴ� ����� ����


	//bounds
	const float Radius = m_radius;
	const float Damage = m_damage;

	UE_LOG(LogTemp, Log, TEXT("radius %f damage %f delay %f vector %s "), m_radius, m_damage, m_delay,*ActorLocation.ToString());

	FTimerHandle m_boom_timer_handle;
	Actor->GetWorldTimerManager().SetTimer(m_boom_timer_handle,
		[World,ActorLocation, Radius,Damage] {	
		TArray<AActor*> AllActors;
	UGameplayStatics::GetAllActorsOfClass(World,AActor::StaticClass(), AllActors);
	UE_LOG(LogTemp, Log, TEXT("RangeBoom Timer %d"), AllActors.GetAllocatedSize());
	for (auto Actor : AllActors)
	{
		UE_LOG(LogTemp, Log, TEXT("RangeBoom EventPlay"));

		//�浹�� ��ü�� Fuselage���� Ȯ���Ѵ�.
		IFuselageBaseData* FuselageData = Cast<IFuselageBaseData>(Actor);
		if (FuselageData == nullptr)
		{
			UE_LOG(LogTemp, Log, TEXT("Range FuselageData == nullptr"));
			continue;
		}

		std::shared_ptr<FuselageCharacter> FuselageCharacter = FuselageData->GetBaseData();
		if (FuselageCharacter.get() == nullptr)
		{
			UE_LOG(LogTemp, Log, TEXT("Range FuselageCharacter.get() == nullptr"));
			continue;
		}
		FVector between = ActorLocation -	Actor->GetActorLocation();

		UE_LOG(LogTemp, Log, TEXT("Range between %f, %f"), between.Size2D(), Radius);

		if(between.Size2D() < Radius)
		{
			if (FuselageCharacter->GetUnion() != static_cast<int8>(EUnionBinary::PLAYER_INVINCIBILITY_BINARY))
			{
				//�浹�� Fuselage�� �������� ����ϴ��� Ȯ���Ѵ�.
				UE_LOG(LogTemp, Log, TEXT("other Range Attack"));
				FuselageCharacter->AddHP(-Damage);
			}
		}

	}
	}, m_delay, false);
}

void RandomItemDrop::EventPlay(FuselageCharacter* Character)
{

	checkf(Character != nullptr, TEXT("RandomItemDrop Parameter Character is nullptr"));
	UE_LOG(LogTemp, Log, TEXT("RandomItemDrop EventPlay"));

	FVector CharacterLocation = Character->GetActor()->GetActorLocation();

	FVector2D MapHalfSize = AShootingGameMode::GetHalfMapSize();

	//���� �ɾȿ��� �״°� �ƴҰ�� ��ȯ�� ���� �ʴ´�.
	if (CharacterLocation.X > MapHalfSize.X || CharacterLocation.X < -MapHalfSize.X
		|| CharacterLocation.Y > MapHalfSize.Y || CharacterLocation.Y < -MapHalfSize.Y)
	{
		return;
	}

	//���� ���� ����
	std::random_device Device;
	std::mt19937 Gen(Device());

	std::uniform_int_distribution<int32> Dis{ 0,5 };

	int32 RandomNum = Dis(Gen);

	//������ ����
	UWorld* SpawnWorld = Character->GetActor()->GetWorld();

	UE_LOG(LogTemp, Log, TEXT("RandomNum %d"), RandomNum);

	switch (RandomNum)
	{
	case 1:
		SpawnWorld->SpawnActor<AActor>(StaticLoadClass(UObject::StaticClass(), NULL,
			TEXT("Class'/Game/Blueprint/BP_HealKit.BP_HealKit_C'"))
			, CharacterLocation, FRotator::ZeroRotator);
		break;
	case 2:
		SpawnWorld->SpawnActor<AActor>(StaticLoadClass(UObject::StaticClass(), NULL,
			TEXT("Class'/Game/Blueprint/BP_WeaponKit.BP_WeaponKit_C'"))
			, CharacterLocation, FRotator::ZeroRotator);
		break;
	default:
		break;
	}
}

void PairDivide::EventPlay(FuselageCharacter* Character)
{
	checkf(Character != nullptr, TEXT("PairDivide Parameter Character is nullptr"));
	UE_LOG(LogTemp, Log, TEXT("PairDivide EventPlay"));

	//���� ��Ʈ�� ǥ������ ����� ũ�⸦ �����Ѵ�.
	const AActor* ModelActor = Character->GetActor();
	UWorld* SpawnWorld = ModelActor->GetWorld();

	//������ ActorScale 3D���� ������ �п��� �ߴ��� Ȯ���Ѵ�(scale���� 1�� �ƴ��� Ȯ���Ѵ�.
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
