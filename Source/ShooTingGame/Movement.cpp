// Fill out your copyright notice in the Description page of Project Settings.

#include "Movement.h"
#include "EnemyDragon.h"
#include "CoreMinimal.h"

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
	default:
		return nullptr;
	}
}


const FVector& CalculationRatioSpeed(const FVector& Ratio) {
	return Ratio;
}

void EastMove::Execute(const UObject* Target) {
	
	UE_LOG(LogTemp, Log, TEXT("Execute Event"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));
	bool BIsIemented = Target->GetClass()->ImplementsInterface(UFuselage::StaticClass());
	
	checkf(BIsIemented, TEXT("not Iemented"));
	
	IFuselage* Fuselage = Cast<IFuselage>(Target->GetClass());
	float Speed = Fuselage->GetSpeed_Implementation();
	FVector EastVector = CalculationRatioSpeed({ 0.0f,-Speed,  0.0f });
	Fuselage->SetLocation_Implementation(EastVector);
}

void WestMove::Execute(const UObject* Target) {

	UE_LOG(LogTemp, Log, TEXT("Execute Event"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));
	bool BIsIemented = Target->GetClass()->ImplementsInterface(UFuselage::StaticClass());

	checkf(BIsIemented, TEXT("not Iemented"));

	IFuselage* Fuselage = Cast<IFuselage>(Target->GetClass());
	float Speed = Fuselage->GetSpeed_Implementation();
	FVector WestVector = CalculationRatioSpeed({ 0.0f,-Speed,  0.0f });
	Fuselage->SetLocation_Implementation(WestVector);
}

void SouthMove::Execute(const UObject* Target) {

	UE_LOG(LogTemp, Log, TEXT("Execute Event"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));
	bool BIsIemented = Target->GetClass()->ImplementsInterface(UFuselage::StaticClass());

	checkf(BIsIemented, TEXT("not Iemented"));

	IFuselage* Fuselage = Cast<IFuselage>(Target->StaticClass());
	float Speed = Fuselage->GetSpeed_Implementation();
	FVector SouthVector = CalculationRatioSpeed({ Speed,0.0f,  0.0f });
	Fuselage->SetLocation_Implementation(SouthVector);
}

void NorthMove::Execute(const UObject* Target) {

	UE_LOG(LogTemp, Log, TEXT("Execute Event"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));
	bool BIsIemented = Target->GetClass()->ImplementsInterface(UFuselage::StaticClass());

	checkf(BIsIemented, TEXT("not Iemented"));
	IFuselage* Fuselage = Cast<IFuselage>(Target->StaticClass());
	float Speed = Fuselage->GetSpeed_Implementation();
	FVector NortVector = CalculationRatioSpeed({ -Speed,0.0f,  0.0f });
	Fuselage->SetLocation_Implementation(NortVector);
}

void Shooting::Execute(const UObject* Target) {
	UE_LOG(LogTemp, Log, TEXT("Shooting Interface"));
	IFuselage* Fuselage = Cast<IFuselage>(Target->StaticClass());
	if (Target != nullptr)
	{
	}

}
