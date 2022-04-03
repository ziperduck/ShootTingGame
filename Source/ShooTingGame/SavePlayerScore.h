// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Containers/Map.h>

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SavePlayerScore.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Category = "SavePlayerScore")
class SHOOTINGGAME_API USavePlayerScore : public USaveGame
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "SavePlayerScore")
	void AddScore(const FString PlayerName, const int32 PlayerScore);

	UFUNCTION(BlueprintCallable, Category = "SavePlayerScore")
	const TMap<FString, int32> GetScoreName() const;

protected:

	UPROPERTY(VisibleAnywhere, Category = Basic)
	TMap<FString, int32> m_player_name_score;

	const int32 m_max_name_score = 5;
};
