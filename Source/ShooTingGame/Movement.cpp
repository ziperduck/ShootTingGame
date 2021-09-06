// Fill out your copyright notice in the Description page of Project Settings.

#include "Object.h"
#include "ObjectManager.h"
#include "Character.h"
#include "Movement.h"
#include "CoreMinimal.h"

const FVector& CalculationRatioSpeed(const FVector& Ratio) {
	return Ratio;
}

void EastMove::execute(IObject* Target) {
	float Speed = Target->GetSpeed();
	FVector EastVector = CalculationRatioSpeed({ 0.0f,-Speed,  0.0f });
	Target->SetLocation(EastVector);
}

void WestMove::execute(IObject* Target) {
	float Speed = Target->GetSpeed();
	FVector WestVector = CalculationRatioSpeed({ 0.0f, Speed, 0.0f });
	Target->SetLocation(WestVector);
}

void SouthMove::execute(IObject* Target) {
	float Speed = Target->GetSpeed();
	FVector SouthVector = CalculationRatioSpeed({ Speed,0.0f,  0.0f });
	Target->SetLocation(SouthVector);
}

void NorthMove::execute(IObject* Target) {
	float Speed = Target->GetSpeed();
	FVector NortVector = CalculationRatioSpeed({ -Speed,0.0f,  0.0f });
	Target->SetLocation(NortVector);
}


void Shooting::execute(IObject* Target) {

	if (Target->GetWeapon() != nullptr)
	{
		ObjectManager::GetInstance()->
			CreateObject(Target->GetWeapon()->GetKind(), Target->GetWorld()
				, Target->GetLocation() + FVector(50.0f, 0.0f, 0.0f));
	}

}
