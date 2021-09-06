// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "TestSceneComponenet.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTINGGAME_API UTestSceneComponenet : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTestSceneComponenet();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
