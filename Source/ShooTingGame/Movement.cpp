// Fill out your copyright notice in the Description page of Project Settings.

#include "Movement.h"
#include "EnumPack.h"
#include "Airframe.h"
#include "EnemyDragon.h"
#include "Rifle.h"
#include "FireShoot.h"
#include "MeteoricStone.h"
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
	case EFuselageKind::Rifle:
		TargetWorld->SpawnActor<ARifle>(TargetLocation, FRotator::ZeroRotator);
		break;
	case EFuselageKind::FireShoot:
		TargetWorld->SpawnActor<AFireShoot>(TargetLocation, FRotator::ZeroRotator);
		break;
	case EFuselageKind::MeteoricStone: 
	{
		AMeteoricStone* MeteoricStone = Cast<AMeteoricStone>(Airframe);
		checkf(MeteoricStone != nullptr, TEXT("MeteoricStone is not casting"));
		if (MeteoricStone->GetMaxHP() > 1)
		{
			TargetWorld->SpawnActor<AMeteoricStone>(TargetLocation, FRotator::ZeroRotator)
				->Initialize_Implementation(MeteoricStone->GetSpeed(), MeteoricStone->GetMaxHP() - 1
					, EFuselageKind::MeteoricStone, 1.0f);
		}
	}
		break;
	default:
		break;
	}
	
}

void Struck::Execute(AActor* Target) {
	UE_LOG(LogTemp, Log, TEXT("Struck Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	IFuselage* Fuselage = Cast<IFuselage>(Target);
	checkf(Fuselage != nullptr, TEXT("Fuselage is nullptr"));

	const int32 StruckDamage = -(Fuselage->GetStruckDamage());
	Fuselage->AddCurrentHP(StruckDamage);

}

void Death::Execute(AActor* Target) {
	UE_LOG(LogTemp, Log, TEXT("Death Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	UWorld* TargetWorld = Target->GetWorld();
	Target->SetActorEnableCollision(false);

	IFuselage* Fuselage = Cast<IFuselage>(Target);
	checkf(Fuselage != nullptr, TEXT("Fuselage is nullptr"));

	if (Fuselage->GetKind() == EFuselageKind::PlayerFuselage)
	{
		return;
	}
	
	TargetWorld->DestroyActor(Target);

}