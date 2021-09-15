// Fill out your copyright notice in the Description page of Project Settings.

#include "Movement.h"
#include "EnemyDragon.h"
#include "CoreMinimal.h"


const FVector& CalculationRatioSpeed(const FVector& Ratio) {
	return Ratio;
}

void EastMove::Execute_Implementation(TSubclassOf<UFuselage>  Target) {
	IFuselage* TargetObject = Cast<IFuselage>(Target.GetDefaultObject()->StaticClass());
	float Speed = TargetObject->GetSpeed();
	FVector EastVector = CalculationRatioSpeed({ 0.0f,-Speed,  0.0f });
	TargetObject->SetLocation(EastVector);
}

void WestMove::Execute_Implementation(TSubclassOf<UFuselage>  Target) {
	IFuselage* TargetObject = Cast<IFuselage>(Target.GetDefaultObject()->StaticClass());
	float Speed = TargetObject->GetSpeed();
	FVector WestVector = CalculationRatioSpeed({ 0.0f, Speed, 0.0f });
	TargetObject->SetLocation(WestVector);
}

void SouthMove::Execute_Implementation(TSubclassOf<UFuselage>  Target) {
	IFuselage* TargetObject = Cast<IFuselage>(Target.GetDefaultObject()->StaticClass());
	float Speed = TargetObject->GetSpeed();
	FVector SouthVector = CalculationRatioSpeed({ Speed,0.0f,  0.0f });
	TargetObject->SetLocation(SouthVector);
}

void NorthMove::Execute_Implementation(TSubclassOf<UFuselage>  Target) {
	IFuselage* TargetObject = Cast<IFuselage>(Target.GetDefaultObject()->StaticClass());
	float Speed = TargetObject->GetSpeed();
	FVector NortVector = CalculationRatioSpeed({ -Speed,0.0f,  0.0f });
	TargetObject->SetLocation(NortVector);
}

void Shooting::Execute_Implementation(TSubclassOf<UFuselage>  Target) {

	if (Target != nullptr)
	{
	}

}
