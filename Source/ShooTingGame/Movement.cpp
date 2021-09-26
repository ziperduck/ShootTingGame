// Fill out your copyright notice in the Description page of Project Settings.

#include "Movement.h"
#include "Airframe.h"
#include "EnemyDragon.h"
#include "Rifle.h"
#include "CoreMinimal.h"
#include <Engine/Classes/Components/SphereComponent.h>

IAction* ChangeAction(EVariousAction Action)
{
	UE_LOG(LogTemp, Log, TEXT("ChageAction"));

	switch (Action)
	{
	case EVariousAction::EastMove:
	{
		static IAction* Event = new EastMove();
		return Event;
	}
	case EVariousAction::WestMove:
	{
		static IAction* Event = new WestMove();
		return Event;
	}
	case EVariousAction::SouthMove:
	{
		static IAction* Event = new SouthMove();
		return Event;
	}
	case EVariousAction::NorthMove:
	{
		static IAction* Event = new NorthMove();
		return Event;
	}
	case EVariousAction::Shooting:
	{
		static IAction* Event = new Shooting();
		return Event;
	}
	case EVariousAction::Struck:
	{
		static IAction* Event = new Struck();
		return Event;
	}
	case EVariousAction::Death:
	{
		static IAction* Event = new Death();
		return Event;
	}
	default:
		checkNoEntry();
		return nullptr;
	}
}


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
	
	IAirframe* Airframe = Cast<IAirframe>(Target);
	if (Airframe == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("shooting Airframe is nullptr"));
		return;
	}
	checkf(Airframe != nullptr, TEXT("Airframe is nullptr"));
	Airframe->ShootingGun();

}

void Struck::Execute(AActor* Target) {
	UE_LOG(LogTemp, Log, TEXT("Struck Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	IFuselage* Fuselage = Cast<IFuselage>(Target);
	checkf(Fuselage != nullptr, TEXT("Fuselage is nullptr"));

	const int8 StruckDamage = -(Fuselage->GetStruckDamage());
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