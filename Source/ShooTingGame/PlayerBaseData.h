// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "PlayerCharacterData.h"

#include "UObject/Interface.h"
#include "PlayerBaseData.generated.h"


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPlayerBaseData : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SHOOTINGGAME_API IPlayerBaseData
{
	GENERATED_BODY()

		// Add interface functions to this class. This is the class that will be inherited to implement this interface.

public:
	
	std::shared_ptr< PlayerCharacterData> GetPlayerData() const { return m_player_data; };

protected:

	std::shared_ptr< PlayerCharacterData> m_player_data;

};
