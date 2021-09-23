// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Fuselage.h"
#include "Action.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rifle.generated.h"

UCLASS(Blueprintable, BlueprintType, ClassGroup = "Fuselage")
class SHOOTINGGAME_API ARifle : public AActor, public IFuselage
{
	GENERATED_BODY()
	
public:	
	ARifle();

	virtual void Tick(float Delta) override;

	//Getter
	virtual const EFuselageKind GetKind() const override;

	virtual const float GetSpeed() const override;

	virtual const FVector GetLocation() const override;

	virtual const FRotator GetRotation() const override;

	virtual UWorld* GetFuselageWorld() const override;

	virtual UClass* GetComponentClass() const override;

	//Setter
	void MoveLocation(const FVector& MoveLocation) ;

	//Event
	virtual void EventUpdate() override;


private:

	USceneComponent* m_characterScene;

private:
	EFuselageKind m_kind;

	uint16 m_damage;

	float m_speed;

	int8 m_max_HP;

	int8 m_current_HP;
};
