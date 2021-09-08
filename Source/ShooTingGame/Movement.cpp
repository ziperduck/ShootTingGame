// Fill out your copyright notice in the Description page of Project Settings.

#include "Fuselage.h"
#include "FuselageManager.h"
#include "EnemyDragon.h"
#include "Movement.h"
#include "CoreMinimal.h"

const FVector& CalculationRatioSpeed(const FVector& Ratio) {
	return Ratio;
}

void EastMove::execute(IFuselage* Target) {
	float Speed = Target->GetSpeed();
	FVector EastVector = CalculationRatioSpeed({ 0.0f,-Speed,  0.0f });
	Target->SetLocation(EastVector);
}

void WestMove::execute(IFuselage* Target) {
	float Speed = Target->GetSpeed();
	FVector WestVector = CalculationRatioSpeed({ 0.0f, Speed, 0.0f });
	Target->SetLocation(WestVector);
}

void SouthMove::execute(IFuselage* Target) {
	float Speed = Target->GetSpeed();
	FVector SouthVector = CalculationRatioSpeed({ Speed,0.0f,  0.0f });
	Target->SetLocation(SouthVector);
}

void NorthMove::execute(IFuselage* Target) {
	float Speed = Target->GetSpeed();
	FVector NortVector = CalculationRatioSpeed({ -Speed,0.0f,  0.0f });
	Target->SetLocation(NortVector);
}


void Shooting::execute(IFuselage* Target) {

	if (Target != nullptr)
	{
		AEnemyDragon* Character = Cast<AEnemyDragon>(Target);
		FuselageManager::GetInstance()
			->AddFuselage(Character->GetWeapon(), Character->GetLocation() + FVector{50.0f,0.0f,0.0f});
	}

}
