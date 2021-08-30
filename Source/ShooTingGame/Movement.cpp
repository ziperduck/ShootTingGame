// Fill out your copyright notice in the Description page of Project Settings.

#include "Object.h"
#include "Movement.h"

EastMove::EastMove() {

}
EastMove::~EastMove() {

}
void EastMove::execute(IObject* Target) {
	float Speed = Target->GetSpeed();
	FVector EastVector = CalculationRatioSpeed({ 0.0f,-Speed,  0.0f });
	EastVector += Target->GetLocation();
	Target->SetLocation(EastVector);
}

WestMove::WestMove()

{

}
WestMove::~WestMove() {

}
void WestMove::execute(IObject* Target) {
	float Speed = Target->GetSpeed();
	FVector WestVector = CalculationRatioSpeed({ 0.0f, Speed, 0.0f });
	WestVector += Target->GetLocation();
	Target->SetLocation(WestVector);
}

SouthMove::SouthMove()

{

}
SouthMove::~SouthMove() {

}
void SouthMove::execute(IObject* Target) {
	float Speed = Target->GetSpeed();
	FVector SouthVector = CalculationRatioSpeed({ Speed,0.0f,  0.0f });
	SouthVector += Target->GetLocation();
	Target->SetLocation(SouthVector);
}

NorthMove::NorthMove()

{

}
NorthMove::~NorthMove() {

}
void NorthMove::execute(IObject* Target) {
	float Speed = Target->GetSpeed();
	FVector NortVector = CalculationRatioSpeed({ -Speed,0.0f,  0.0f });
	NortVector += Target->GetLocation();
	Target->SetLocation(NortVector);
}
