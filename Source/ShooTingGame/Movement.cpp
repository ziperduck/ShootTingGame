// Fill out your copyright notice in the Description page of Project Settings.

#include "Movement.h"
#include "EnumPack.h"
#include "Airframe.h"
#include "EnemyDragon.h"
#include "Rifle.h"
#include "FireShoot.h"
#include "MeteoricStone.h"
#include <set>
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

void Shooting::Execute(AActor* Target) {
	UE_LOG(LogTemp, Log, TEXT("Shooting Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	UWorld* TargetWorld = Target->GetWorld();
	FVector TargetLocation = Target->GetActorLocation();

	IAirframe* Airframe = Cast<IAirframe>(Target);
	checkf(Airframe != nullptr, TEXT("Airframe is nullptr"));

	//GetWeapon으로 무기를 만들자.
	
	switch (Airframe->GetWeapon())
	{
	case EFuselageKind::RIFLE_WEAPON:
		TargetWorld->SpawnActor<ARifle>(TargetLocation, FRotator::ZeroRotator);
		break;
	case EFuselageKind::FIRESHOOT_WEAPON:
		TargetWorld->SpawnActor<AFireShoot>(TargetLocation, FRotator::ZeroRotator);
		break;
	case EFuselageKind::METEORICSTONE_FUSELAGE: 
	{
		AMeteoricStone* MeteoricStone = Cast<AMeteoricStone>(Airframe);
		checkf(MeteoricStone != nullptr, TEXT("MeteoricStone is not casting"));
		if (MeteoricStone->GetMaxHP() > 1)
		{
			TargetWorld->SpawnActor<AMeteoricStone>(TargetLocation, FRotator::ZeroRotator)
				->Initialize_Implementation(MeteoricStone->GetSpeed(), MeteoricStone->GetMaxHP() - 1
					, EFuselageKind::METEORICSTONE_FUSELAGE, 1.0f);
		}
	}
		break;
	default:
		break;
	}
	
}

void Attack::Execute(AActor* Target) {
	UE_LOG(LogTemp, Log, TEXT("Attack Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	IFuselage* TargetFuselage = Cast<IFuselage>(Target);
	checkf(TargetFuselage != nullptr, TEXT("Fuselage is nullptr"));

	std::set<EFuselageKind> Wanted;
	switch (TargetFuselage->GetKind())
	{
	case EFuselageKind::PLAYER_FUSELAGE:
	{
		Wanted.insert(EFuselageKind::FIRESHOOT_WEAPON);
	}
	case EFuselageKind::RIFLE_WEAPON:
	case EFuselageKind::LASERBEAM_WEAPON:
	{
		Wanted.insert(EFuselageKind::ENEMY_FUSELAGE);
		Wanted.insert(EFuselageKind::METEORICSTONE_FUSELAGE);
		Wanted.insert(EFuselageKind::MISSILEDRAGON_FUSELAGE);
	}
		break;
	case EFuselageKind::ENEMY_FUSELAGE:
	case EFuselageKind::METEORICSTONE_FUSELAGE:
	case EFuselageKind::MISSILEDRAGON_FUSELAGE:
	{
		Wanted.insert(EFuselageKind::RIFLE_WEAPON);
		Wanted.insert(EFuselageKind::LASERBEAM_WEAPON);
	}
	case EFuselageKind::FIRESHOOT_WEAPON:
	{
		Wanted.insert(EFuselageKind::PLAYER_FUSELAGE);
	}
		break;
	default:
		break;
	}

	TSet<AActor*> OverlapActors;
	Target->GetOverlappingActors(OverlapActors);


	//레이저 빔같은경우 관통데미지를 주기때문에 overlap된 모든 적들을 찾는다.
	for (auto i : OverlapActors)
	{
		IFuselage* OverlapFuselage = Cast<IFuselage>(i);
		checkf(OverlapFuselage != nullptr, TEXT("OverlapFuselage is nullptr"));

		for (auto k : Wanted)
		{
			if (OverlapFuselage->GetKind() == k)
			{
				OverlapFuselage->AddCurrentHP(-TargetFuselage->GetAttackPower());
				break;
			}
		}

	}
}

void Death::Execute(AActor* Target) {
	UE_LOG(LogTemp, Log, TEXT("Death Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	UWorld* TargetWorld = Target->GetWorld();
	Target->SetActorEnableCollision(false);

	IFuselage* Fuselage = Cast<IFuselage>(Target);
	checkf(Fuselage != nullptr, TEXT("Fuselage is nullptr"));

	if (Fuselage->GetKind() == EFuselageKind::PLAYER_FUSELAGE)
	{
		return;
	}
	
	TargetWorld->DestroyActor(Target);

}