// Fill out your copyright notice in the Description page of Project Settings.

#include "Movement.h"
#include "Fuselage.h"
#include "EnemyDragon.h"
#include "CoreMinimal.h"

const FVector& CalculationRatioSpeed(const FVector& Ratio) {
	return Ratio;
}

void EastMove::execute_Implementation(IFuselage* Target) {
	float Speed = Target->GetSpeed();
	FVector EastVector = CalculationRatioSpeed({ 0.0f,-Speed,  0.0f });
	Target->SetLocation(EastVector);
}

void WestMove::execute_Implementation(IFuselage* Target) {
	float Speed = Target->GetSpeed();
	FVector WestVector = CalculationRatioSpeed({ 0.0f, Speed, 0.0f });
	Target->SetLocation(WestVector);
}

void SouthMove::execute_Implementation(IFuselage* Target) {
	float Speed = Target->GetSpeed();
	FVector SouthVector = CalculationRatioSpeed({ Speed,0.0f,  0.0f });
	Target->SetLocation(SouthVector);
}

void NorthMove::execute_Implementation(IFuselage* Target) {
	float Speed = Target->GetSpeed();
	FVector NortVector = CalculationRatioSpeed({ -Speed,0.0f,  0.0f });
	Target->SetLocation(NortVector);
}


void Shooting::execute_Implementation(IFuselage* Target) {

	if (Target != nullptr)
	{
	}

}
