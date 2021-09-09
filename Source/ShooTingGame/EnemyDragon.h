// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageFoundation.h"
#include "Fuselage.h"
#include "Components/SceneComponent.h"
#include "EnemyDragon.generated.h"


UCLASS()
class SHOOTINGGAME_API UEnemyDragon : public USceneComponent, public IFuselage
{
	GENERATED_BODY()


public:
	UEnemyDragon();

	//Getter
	virtual const FuselageKind GetKind() const override;

	virtual const float GetSpeed() const override;

	virtual const FVector GetLocation() const override;

	virtual const FRotator GetRotation() const override;

	virtual UWorld* GetFuselageWorld() const override;

	TSharedPtr<IFuselage> GetWeapon() const;

	virtual UClass* GetComponentClass() const override;

	//Setter
	virtual void SetLocation(const FVector& MoveLocation) override;


	//Event
	void AddNextAction(std::queue<std::shared_ptr<IAction>>);

	virtual void AddAction(std::shared_ptr<IAction>) override;

	virtual void Update() override;

private:
	UStaticMeshComponent* CharacterMesh;

private:
	FuselageKind m_kind;

	float m_speed;

	int8 m_max_HP;

	int8 m_current_HP;

	TSharedPtr<IFuselage> m_weapon;

	std::queue<std::shared_ptr<IAction>> m_actions;

	std::queue<std::shared_ptr<IAction>> m_animation;
};
