// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShooTingGameGameModeBase.generated.h"

/**
 * 
 */

class IObject;
class ObjectManager;

UCLASS()
class SHOOTINGGAME_API AShooTingGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AShooTingGameGameModeBase();

	virtual void StartPlay() override;

	virtual void Tick(float) override;

private:

	ObjectManager* m_object_manager;

};
