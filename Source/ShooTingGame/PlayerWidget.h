// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FuselageBaseData.h"
#include "PlayerBaseData.h"

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerWidget.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTINGGAME_API UPlayerWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	
	//생성자를 만든다.
	virtual void NativeConstruct() final;

protected:

	//플레이어의 캐릭터의 스코어를 받는다.
	UFUNCTION(BlueprintCallable,Category = "PlayerWidget")
	FString GetPlayerScore();

	//플레이어의 캐릭터의 폭탄을 받는다.
	UFUNCTION(BlueprintCallable, Category = "PlayerWidget")
	FString GetPlayerFinishMove();

	//플레이어의 캐릭터체력을 받는다.
	UFUNCTION(BlueprintCallable, Category = "PlayerWidget")
	FString GetPlayerHP();

private:

	//플레이어의 동체 데이터를 받는다.
	IFuselageBaseData* m_fuselage_data;

	//플레이어 데이터를 받는다.
	IPlayerBaseData* m_player_data;
};
