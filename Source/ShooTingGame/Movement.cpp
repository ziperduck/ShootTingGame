// Fill out your copyright notice in the Description page of Project Settings.

#include "Movement.h"
#include "EnemyDragon.h"
#include "CoreMinimal.h"


const FVector& CalculationRatioSpeed(const FVector& Ratio) {
	return Ratio;
}

void EastMove::Execute_Implementation(TSubclassOf<UFuselage>  Target) {
	bool BIsIemented = Target.GetDefaultObject()->GetClass()->ImplementsInterface(UFuselage::StaticClass());

	checkf(BIsIemented, TEXT("not Iemented"));

	IFuselage* TargetObject = Cast<IFuselage>(Target);
	float Speed = TargetObject->GetSpeed_Implementation();
	FVector EastVector = CalculationRatioSpeed({ 0.0f,-Speed,  0.0f });
	TargetObject->SetLocation_Implementation(EastVector);
}

void WestMove::Execute_Implementation(TSubclassOf<UFuselage>  Target) {
	IFuselage* TargetObject = Cast<IFuselage>(Target.GetDefaultObject()->StaticClass());
	float Speed = TargetObject->GetSpeed_Implementation();
	FVector WestVector = CalculationRatioSpeed({ 0.0f, Speed, 0.0f });
	TargetObject->SetLocation_Implementation(WestVector);
}

void SouthMove::Execute_Implementation(TSubclassOf<UFuselage>  Target) {
	IFuselage* TargetObject = Cast<IFuselage>(Target.GetDefaultObject()->StaticClass());
	float Speed = TargetObject->GetSpeed_Implementation();
	FVector SouthVector = CalculationRatioSpeed({ Speed,0.0f,  0.0f });
	TargetObject->SetLocation_Implementation(SouthVector);
}

void NorthMove::Execute_Implementation(TSubclassOf<UFuselage>  Target) {
	IFuselage* TargetObject = Cast<IFuselage>(Target.GetDefaultObject()->StaticClass());
	float Speed = TargetObject->GetSpeed_Implementation();
	FVector NortVector = CalculationRatioSpeed({ -Speed,0.0f,  0.0f });
	TargetObject->SetLocation_Implementation(NortVector);
}

void Shooting::Execute_Implementation(TSubclassOf<UFuselage>  Target) {

	if (Target != nullptr)
	{
	}

}
