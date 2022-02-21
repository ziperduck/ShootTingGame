// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageCharacter.h"

#include "UObject/Interface.h"
#include "FuselageBaseData.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UFuselageBaseData : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SHOOTINGGAME_API IFuselageBaseData
{
	GENERATED_BODY()

public:
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.

	std::shared_ptr<FuselageCharacter> GetBaseData() const { return m_base_data; };

protected:

	std::shared_ptr<FuselageCharacter> m_base_data;

};
