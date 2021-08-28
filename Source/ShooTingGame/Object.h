// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class Actions;
//가장 기본이 되는 오브젝트 모든 오브젝트가 이것에 의해 파생된다.
class IObject
{
public:
	explicit IObject(const char* , const float , AActor*);
	virtual ~IObject() = 0{}

private:
	IObject();

public:

	void SetLocation(const FVector&);

	const FVector GetLocation();

	const char* GetName() const ;

	float GetSpeed() const;

	virtual bool Is_Collision() = 0;

	virtual void Update() = 0;

	virtual void AddAction(std::shared_ptr<Actions>) = 0;

protected :

	const char* m_name;

	const float m_speed;

	AActor* m_actor;
};
