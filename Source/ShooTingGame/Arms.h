// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Weapon.h"
#include "Object.h"
#include "CoreMinimal.h"

/**
 * 
 */
class Rifle : IWeapon
{
public:
	Rifle();
	~Rifle();

	virtual void Update() override;

	virtual void AddAction() override;

	virtual void SetLocation() override;
private:

	std::unique_ptr<IObject> m_bullet;


};
