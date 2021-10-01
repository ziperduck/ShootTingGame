// Fill out your copyright notice in the Description page of Project Settings.

#include "Movement.h"
#include "EnumPack.h"
#include "Airframe.h"
#include "EnemyDragon.h"
#include "Rifle.h"
#include "FireShoot.h"
#include "MeteoricStone.h"
#include "LaserBeam.h"
#include "PlayerCharacter.h"
#include "WeaponKit.h"
#include "HealPack.h"
#include "WeaponKit.h"

#include <set>
#include <Engine/Classes/Kismet/GameplayStatics.h>
#include "CoreMinimal.h"
#include <Engine/Classes/Components/SphereComponent.h>



const FVector& CalculationRatioSpeed(const FVector& Ratio) {
	return Ratio;
}

void EastMove::Execute(AActor* Target) {

	UE_LOG(LogTemp, Log, TEXT("EastMove Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	IFuselage* Fuselage = Cast<IFuselage>(Target);
	checkf(Fuselage != nullptr, TEXT("Fuselage is nullptr"));

	float Speed = Fuselage->GetSpeed();
	FVector EastVector = CalculationRatioSpeed({ 0.0f,Speed,  0.0f });
	Fuselage->MoveLocation(EastVector);
}

void WestMove::Execute(AActor* Target) {

	UE_LOG(LogTemp, Log, TEXT("WestMove Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	IFuselage* Fuselage = Cast<IFuselage>(Target);
	checkf(Fuselage != nullptr, TEXT("Fuselage is nullptr"));

	float Speed = Fuselage->GetSpeed();
	FVector WestVector = CalculationRatioSpeed({ 0.0f,-Speed,  0.0f });
	Fuselage->MoveLocation(WestVector);
}

void SouthMove::Execute(AActor* Target) {

	UE_LOG(LogTemp, Log, TEXT("SouthMove Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	IFuselage* Fuselage = Cast<IFuselage>(Target);
	checkf(Fuselage != nullptr, TEXT("Fuselage is nullptr"));

	float Speed = Fuselage->GetSpeed();
	FVector SouthVector = CalculationRatioSpeed({ -Speed,0.0f,  0.0f });
	Fuselage->MoveLocation(SouthVector);
}

void NorthMove::Execute(AActor* Target) {

	UE_LOG(LogTemp, Log, TEXT("NorthMove Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	IFuselage* Fuselage = Cast<IFuselage>(Target);
	checkf(Fuselage != nullptr, TEXT("Fuselage is nullptr"));

	float Speed = Fuselage->GetSpeed();
	FVector NortVector = CalculationRatioSpeed({ Speed,0.0f,  0.0f });
	Fuselage->MoveLocation(NortVector);
}


void Guidance::Execute(AActor* Target) {

	UE_LOG(LogTemp, Log, TEXT("NorthMove Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	FVector PlayerLocation = Target->GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	FVector TargetLocation = Target->GetActorLocation();

	IFuselage* Fuselage = Cast<IFuselage>(Target);
	checkf(Fuselage != nullptr, TEXT("Fuselage is nullptr"));

	float Speed = Fuselage->GetSpeed();

	float Adjacent = PlayerLocation.X - TargetLocation.X;
	float Opposite = PlayerLocation.Y - TargetLocation.Y ;
	float Hypotenuse = sqrt(pow(Adjacent, 2) + pow(Opposite, 2));

	FVector MoveLocation = { Adjacent / Hypotenuse, Opposite / Hypotenuse,0.0f };
	MoveLocation *= Speed;

	Fuselage->MoveLocation(MoveLocation);
}

void AttachPlayer::Execute(AActor* Target)
{
	UE_LOG(LogTemp, Log, TEXT("AttachPlayer Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	Target->K2_AttachRootComponentToActor(Target->GetWorld()->GetFirstPlayerController()->GetPawn());

}


void Shooting::Execute(AActor* Target) {
	UE_LOG(LogTemp, Log, TEXT("Shooting Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	UWorld* TargetWorld = Target->GetWorld();
	FVector TargetLocation = Target->GetActorLocation();

	IAirframe* Airframe = Cast<IAirframe>(Target);
	checkf(Airframe != nullptr, TEXT("Airframe is nullptr"));

	UClass* WeaponClass = nullptr;
	//GetWeapon으로 무기를 만들자.

	TArray<FTransform> WeaponTransform;
	int32 WeaponPower = 1;

	switch (Airframe->GetWeaponKind())
	{
	case EVariousWeapon::RIFLE_WEAPON:
	{
		switch (Airframe->GetWeaponLevel())
		{
		case 1:
			WeaponTransform.Add(FTransform{ FQuat{0.0f,0.0f,0.0f,0.0f}, TargetLocation, FVector::OneVector });
			break;
		case 2:
			WeaponTransform.Add(FTransform{ FQuat{0.0f,0.0f,0.0f,0.0f}, TargetLocation, FVector::OneVector });
			WeaponTransform.Add(FTransform{ FQuat{0.0f,0.0f,0.0f,0.0f}, TargetLocation - FVector{ 0.0f,40.0f,0.0f}, FVector::OneVector });
			WeaponTransform.Add(FTransform{ FQuat{0.0f,0.0f,0.0f,0.0f}, TargetLocation + FVector{ 0.0f,40.0f,0.0f }, FVector::OneVector });
			break;
		case 3:
			WeaponTransform.Add(FTransform{ FQuat{0.0f,0.0f,0.0f,0.0f}, TargetLocation, FVector::OneVector });
			WeaponTransform.Add(FTransform{ FQuat{0.0f,0.0f,0.0f,0.0f}, TargetLocation - FVector{ 0.0f,40.0f,0.0f}, FVector::OneVector });
			WeaponTransform.Add(FTransform{ FQuat{0.0f,0.0f,0.0f,0.0f}, TargetLocation + FVector{ 0.0f,40.0f,0.0f }, FVector::OneVector });
			WeaponTransform.Add(FTransform{ FQuat{0.0f,0.0f,0.0f,0.0f}, TargetLocation - FVector{ 0.0f,80.0f,0.0f}, FVector::OneVector });
			WeaponTransform.Add(FTransform{ FQuat{0.0f,0.0f,0.0f,0.0f}, TargetLocation + FVector{ 0.0f,80.0f,0.0f }, FVector::OneVector });
			WeaponPower = 2;
			break;
		default:
			break;
		}
		UE_LOG(LogTemp, Log, TEXT("RIFLE_WEAPON"));
		WeaponClass = Cast<UClass>(StaticLoadClass(UObject::StaticClass(), NULL,
			TEXT("Class'/Game/Blueprint/BP_Rifle.BP_Rifle_C'")));
		break;
	}
	case EVariousWeapon::LASERBEAM_WEAPON:
	{
		WeaponTransform.Add(FTransform{ FQuat{0.0f,0.0f,0.0f,0.0f},FVector::ZeroVector, FVector::OneVector });
		switch (Airframe->GetWeaponLevel())
		{
		case 1:
			WeaponTransform[0].SetScale3D(FVector::OneVector);
			WeaponTransform[0].SetScale3D(FVector{ 1.0f,5.0f,1.0f });
			break;
		case 2:
			WeaponTransform[0].SetScale3D(FVector{ 1.0f,15.0f,1.0f });
			WeaponPower = 2;
			break;
		case 3:
			WeaponTransform[0].SetScale3D(FVector{ 1.0f,25.0f,1.0f });
			WeaponPower = 3;
			break;
		default:
			break;
		}

		UE_LOG(LogTemp, Log, TEXT("RIFLE_WEAPON"));
		WeaponClass = Cast<UClass>(StaticLoadClass(UObject::StaticClass(), NULL,
			TEXT("Class'/Game/Blueprint/BP_LaserBeam.BP_LaserBeam_C'")));
		break;
	}

	case EVariousWeapon::FIRESHOOT_WEAPON:
	{
		WeaponTransform.Add(FTransform{ FQuat{0.0f,0.0f,0.0f,0.0f},TargetLocation, FVector::OneVector });
		WeaponClass = Cast<UClass>(StaticLoadClass(UObject::StaticClass(), NULL,
			TEXT("Class'/Game/Blueprint/BP_FireShoot.BP_FireShoot_C'")));
		break;
	}
	default:
		break;
	}


	if (WeaponClass == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Airframe GetWeapon nullptr"));
		return;
	}

	for (const auto i : WeaponTransform)
	{
		UE_LOG(LogTemp, Log, TEXT("Weapon Spawn"));
		AActor* LaserBeam = TargetWorld->SpawnActor<AActor>(WeaponClass, i);
		if (LaserBeam == nullptr)
		{
			UE_LOG(LogTemp, Log, TEXT("LaserBeam nullptr"));
			return;
		}
		LaserBeam->SetLifeSpan(Airframe->GetWeaponLiflespan());
		Cast<IFuselage>(LaserBeam)->SetAttackPower(WeaponPower);
	}

}

void Attack::Execute(AActor* Target) {
	UE_LOG(LogTemp, Log, TEXT("Attack Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	IFuselage* TargetFuselage = Cast<IFuselage>(Target);
	checkf(TargetFuselage != nullptr, TEXT("Fuselage is nullptr"));

	//타격이 가능한 대상을 선별한다.
	std::set<EFuselageKind> Wanted;
	switch (TargetFuselage->GetKind())
	{
	case EFuselageKind::PLAYER_FUSELAGE:
	{
		Wanted.insert(EFuselageKind::ENEMY_WEAPON);
	}
	case EFuselageKind::PLAYER_WEAPON:
	{
		Wanted.insert(EFuselageKind::ENEMY_FUSELAGE);
		break;
	}
	case EFuselageKind::ENEMY_FUSELAGE:
	{
		Wanted.insert(EFuselageKind::PLAYER_WEAPON);
	}
	case EFuselageKind::ENEMY_WEAPON:
	{
		Wanted.insert(EFuselageKind::PLAYER_FUSELAGE);
		break;
	}
	default:
		break;
	}


	TSet<AActor*> OverlapActors;
	Target->GetOverlappingActors(OverlapActors);

	UE_LOG(LogTemp, Log, TEXT("Healing Player Search Size %d"), OverlapActors.GetAllocatedSize());

	//그외
	for (auto& i : OverlapActors)
	{
		IFuselage* OverlapFuselage = Cast<IFuselage>(i);
		checkf(OverlapFuselage != nullptr, TEXT("OverlapFuselage is nullptr"));


		for (auto& k : Wanted)
		{
			if (OverlapFuselage->GetKind() == k)
			{
				OverlapFuselage->AttackFuselage(-TargetFuselage->GetAttackPower());
				break;
			}
		}

	}
}

void BoomAttack::Execute(AActor* Target) {
	UE_LOG(LogTemp, Log, TEXT("BoomAttack Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	const UWorld* TargetWorld = Target->GetWorld();

	IFuselage* TargetAirframe = Cast<IFuselage>(Target);
	checkf(TargetAirframe != nullptr, TEXT("Fuselage is nullptr"));

	TArray<AActor*> AllFuselageActor;
	UGameplayStatics::GetAllActorsOfClassWithTag(
		TargetWorld, AActor::StaticClass(), TEXT("Fuselage"), AllFuselageActor);

	//그외
	for (auto& i : AllFuselageActor)
	{
		IFuselage* OverlapFuselage = Cast<IFuselage>(i);
		checkf(OverlapFuselage != nullptr, TEXT("OverlapFuselage is nullptr"));
	
		if (Target != i && Target->GetDistanceTo(i) < 200.0f)
		{
			UE_LOG(LogTemp, Log, TEXT("i"));
			OverlapFuselage->AttackFuselage(-TargetAirframe->GetAttackPower());
		}
	}
}

void Healing::Execute(AActor* Target) {
	UE_LOG(LogTemp, Log, TEXT("Healing Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	IFuselage* Fuselage = Cast<IFuselage>(Target);
	checkf(Fuselage != nullptr, TEXT("Fuselage is nullptr"));


	TSet<AActor*> OverlapActors;
	Target->GetOverlappingActors(OverlapActors);

	UE_LOG(LogTemp, Log, TEXT("Healing Player Search Size %d"), OverlapActors.Num());
	
	//그외
	for (auto& i : OverlapActors)
	{
		APlayerCharacter* OverlapFuselage = Cast<APlayerCharacter>(i);
		if (OverlapFuselage != nullptr)
		{
			UE_LOG(LogTemp, Log, TEXT("Healing Heal"));
			OverlapFuselage->AttackFuselage(Fuselage->GetAttackPower());
			break;
		}
	}

}

void WeaponUpgrad::Execute(AActor* Target)
{
	UE_LOG(LogTemp, Log, TEXT("WeaponChange Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	AWeaponKit* WeaponKit = Cast<AWeaponKit>(Target);
	checkf(WeaponKit != nullptr, TEXT("Item is nullptr"));

	TSet<AActor*> OverlapActors;
	WeaponKit->GetOverlappingActors(OverlapActors);

	UE_LOG(LogTemp, Log, TEXT("Healing Player Search Size %d"), OverlapActors.Num());

	//그외
	for (auto& i : OverlapActors)
	{
		APlayerCharacter* OverlapFuselage = Cast<APlayerCharacter>(i);
		if (OverlapFuselage != nullptr)
		{
			UE_LOG(LogTemp, Log, TEXT("WeaponChange"));
			OverlapFuselage->UpgradeWeapon();
			break;
		}
	}
}

void Death::Execute(AActor* Target) {
	UE_LOG(LogTemp, Log, TEXT("Death Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	Target->SetActorEnableCollision(false);

	UWorld* TargetWorld = Target->GetWorld();

	IFuselage* Fuselage = Cast<IFuselage>(Target);
	checkf(Fuselage != nullptr, TEXT("Fuselage is nullptr"));

	TargetWorld->DestroyActor(Target);
}

void DropItem::Execute(AActor* Target)
{
	UE_LOG(LogTemp, Log, TEXT("Death Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	UWorld* TargetWorld = Target->GetWorld();
	FVector TargetLocation = Target->GetActorLocation();
	
	UClass* ItemClass = nullptr;

	//회복아이템인지 업그레이드 키트인지 결정하는 알고리즘
	if (FMath::RandBool())
	{
		ItemClass = Cast<UClass>(StaticLoadObject(UObject::StaticClass()
			,NULL,TEXT("Class'/Game/Blueprint/BP_HealPack.BP_HealPack_C'")));
	}
	else
	{
		ItemClass = Cast<UClass>(StaticLoadObject(UObject::StaticClass()
			, NULL, TEXT("Class'/Game/Blueprint/BP_WeaponKit.BP_WeaponKit_C'")));
	}
	if (ItemClass != nullptr)
	{
		AActor* DropItem = TargetWorld->SpawnActor<AActor>(ItemClass, TargetLocation,FRotator::ZeroRotator);
		DropItem->SetLifeSpan(10.0f);
	}
}

void FuselageDivide::Execute(AActor* Target)
{

	UE_LOG(LogTemp, Log, TEXT("FuselageDivide Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	UWorld* TargetWorld = Target->GetWorld();

	FVector TargetLocation = Target->GetActorLocation();
	FVector TargetScale = Target->GetActorScale3D();

	UClass* TargetClass = Target->GetClass();

	IFuselage* TargetAirframe = Cast<IFuselage>(Target);
	checkf(TargetAirframe != nullptr, TEXT("Airframe is nullptr"));

	UE_LOG(LogTemp, Log, TEXT("TargetScale Scale X = %f"), TargetScale.X);

	//분열
	if (TargetScale.X > 0.5f)
	{
		TargetScale *= 0.5f;

		TArray<FVector> SpawnLocation;
		SpawnLocation.Add(TargetLocation - FVector{ 0.0f,100.0f,0.0f });
		SpawnLocation.Add(TargetLocation + FVector{ 0.0f,100.0f,0.0f });

		for (const auto i : SpawnLocation)
		{
			AActor* DiVideACtor = TargetWorld->SpawnActor<AActor>(TargetClass, i, FRotator::ZeroRotator);
			checkf(DiVideACtor != nullptr, TEXT("DiVideACtor  is nullptr"));
			DiVideACtor->SetLifeSpan(10.0f);
			DiVideACtor->SetActorScale3D(TargetScale);

			//나눠지면 빠라지고 체력이 하나 달아있다.
			IFuselage* DiVideFuselage = Cast<IFuselage>(DiVideACtor);
			checkf(DiVideFuselage != nullptr, TEXT("Fuselage  is nullptr"));
			DiVideFuselage->SetSpeed(DiVideFuselage->GetSpeed() *2.0f);
			DiVideFuselage->AttackFuselage(-1);
		}

		
	}


}
