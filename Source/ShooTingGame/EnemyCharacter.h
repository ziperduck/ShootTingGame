// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyCharacter.generated.h"


class IObject;

UCLASS()
class SHOOTINGGAME_API AEnemyCharacter : public AActor
{
	GENERATED_BODY()


public:	
	// Sets default values for this actor's properties
	AEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:

	UStaticMeshComponent* CharacterMesh;

};
