// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class IAction;

//움직이는 물체들의 가장 기본이 되는 IObject 모든 움직이는 물체는 IObject에 의해 파생된다.
class IObject
{
public:
	IObject() = delete;
	explicit IObject(const char* , const float , AActor*);
	virtual ~IObject() = 0{}

public:

	void SetLocation(const FVector&);

	const FVector GetLocation();

	const char* GetName() const ;

	float GetSpeed() const;

	virtual bool Is_Collision() = 0;

	virtual void Update() = 0;

	virtual void AddAction(std::shared_ptr<IAction>) = 0;

protected :

	const char* m_name;

	const float m_speed;

	AActor* m_actor;
};
