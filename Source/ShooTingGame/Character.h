// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "CoreMinimal.h"

/**
 * 
 */
class CharaterWeapon;

//플레이어 캐릭터다.
class PlayerCharacter : public IObject
{
public:
	explicit PlayerCharacter(const char*, const int8, const float, AActor*);
	//explicit PlayerCharacter(const char*, const int8, const float, const UStaticMesh* Mesh, const FColor& Color, const CharaterWeapon*);
	virtual ~PlayerCharacter() override;

private:
	PlayerCharacter();

public:
	const int8 GetMaxHP() const;

	const int8 GetCurrentHP() const;

	const CharaterWeapon* GetWeapon() const;

	virtual bool Is_Collision() override;

	virtual void Update() override;

	virtual void AddAction(std::shared_ptr<Actions>) override;
private:

	const int8 m_max_HP;

	int8 m_current_HP;

	const CharaterWeapon* m_weapon;

	std::queue<std::shared_ptr<Actions>> m_actions;

};