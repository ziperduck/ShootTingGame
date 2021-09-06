// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

enum class ObjectKind
{
	PlayerObject
	,EnemyObject
	,RifleObject
};

class IAction;

//움직이는 물체들의 가장 기본이 되는 IObject 모든 움직이는 물체는 IObject에 의해 파생된다.
class IObject
{
public:
	IObject() {}
	virtual ~IObject() = 0 {}

public:

	//Getter
	virtual const uint16  GetIdentityNumber()  const = 0;

	virtual const ObjectKind GetKind() const = 0;

	virtual const float GetSpeed() const = 0;

	virtual const FVector GetLocation() const = 0;

	virtual UWorld* GetWorld() const = 0;

	//망할 언리얼은 RTTI를 지원안하네? 꼴받네
	virtual std::shared_ptr<IObject> GetWeapon() = 0;


	//Setter
	virtual void SetLocation(const FVector&) = 0;


	//Event
	virtual void AddAction(std::shared_ptr<IAction>) = 0;

	virtual void AddAnimation(std::queue<std::queue<std::shared_ptr<IAction>>>) = 0;

	virtual void Update() = 0;
};

const uint16  GetIdentity();
