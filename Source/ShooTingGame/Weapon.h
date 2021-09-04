// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
class IWeapon
{
public:
	IWeapon() {};

	virtual ~IWeapon() = 0 {};

	virtual void Update() = 0;

	virtual void AddAction() = 0;

	virtual void SetLocation() = 0;
};
