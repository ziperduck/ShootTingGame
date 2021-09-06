// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "CoreMinimal.h"

/**
 * 
 */
class IAction;

//플레이어의 캐릭터다.
class ActorCharacter : public IObject
{
public:
	ActorCharacter() = delete;
	explicit ActorCharacter(const ObjectKind, const int8, const float, USceneComponent*,IObject*);
	//explicit ActorCharacter(const char*, const int8, const float, const UStaticMesh* Mesh, const FColor& Color, const CharaterWeapon*);
	virtual ~ActorCharacter() override;

public:

	//Getter
	virtual const uint16  GetIdentityNumber()  const override;

	virtual const ObjectKind GetKind() const override;

	virtual const float GetSpeed() const override;

	virtual const FVector GetLocation() const override;

	virtual UWorld* GetWorld() const override;

	const int8 GetMaxHP() const;

	const int8 GetCurrentHP() const;

	virtual std::shared_ptr<IObject> GetWeapon() override;


	//Setter
	virtual void SetLocation(const FVector& MoveLocation) override;


	//Event
	virtual void AddAction(std::shared_ptr<IAction>) override;

	virtual void AddAnimation(std::queue<std::queue<std::shared_ptr<IAction>>>) override;

	virtual void Update() override;
private:

	const ObjectKind m_kind;

	const uint16 m_identity_num;

	const float m_speed;

	const int8 m_max_HP;

	int8 m_current_HP;

	USceneComponent* m_componenet;

	std::shared_ptr<IObject> m_weapon;

	std::queue<std::shared_ptr<IAction>> m_actions;

	std::queue<std::queue<std::shared_ptr<IAction>>> m_animation;

};