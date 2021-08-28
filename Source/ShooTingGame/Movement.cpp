// Fill out your copyright notice in the Description page of Project Settings.

#include "Character.h"
#include "Movement.h"

EastMove::EastMove() {

}
EastMove::~EastMove() {

}
void EastMove::execute(std::shared_ptr<IObject> Target) {
	float Speed = Target->GetSpeed();
	FVector EastVector = CalculationRatioSpeed({ -Speed, 0.0f, 0.0f });
	EastVector += Target->GetLocation();
	Target->SetLocation(EastVector);
}

WestMove::WestMove()

{

}
WestMove::~WestMove() {

}
void WestMove::execute(std::shared_ptr<IObject> Target) {
	float Speed = Target->GetSpeed();
	FVector WestVector = CalculationRatioSpeed({ Speed, 0.0f, 0.0f });
	WestVector += Target->GetLocation();
	Target->SetLocation(WestVector);
}

SouthMove::SouthMove()

{

}
SouthMove::~SouthMove() {

}
void SouthMove::execute(std::shared_ptr<IObject> Target) {
	float Speed = Target->GetSpeed();
	FVector SouthVector = CalculationRatioSpeed({ 0.0f, -Speed, 0.0f });
	SouthVector += Target->GetLocation();
	Target->SetLocation(SouthVector);
}

NorthMove::NorthMove()

{

}
NorthMove::~NorthMove() {

}
void NorthMove::execute(std::shared_ptr<IObject> Target) {
	float Speed = Target->GetSpeed();
	FVector NortVector = CalculationRatioSpeed({ 0.0f, Speed, 0.0f });
	NortVector += Target->GetLocation();
	Target->SetLocation(NortVector);
}
