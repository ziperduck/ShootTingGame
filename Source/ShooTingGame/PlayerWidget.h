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
	
	//�����ڸ� �����.
	virtual void NativeConstruct() final;

protected:

	//�÷��̾��� ĳ������ ���ھ �޴´�.
	UFUNCTION(BlueprintCallable,Category = "PlayerWidget")
	FString GetPlayerScore();

	//�÷��̾��� ĳ������ ��ź�� �޴´�.
	UFUNCTION(BlueprintCallable, Category = "PlayerWidget")
	FString GetPlayerFinishMove();

	//�÷��̾��� ĳ����ü���� �޴´�.
	UFUNCTION(BlueprintCallable, Category = "PlayerWidget")
	FString GetPlayerHP();

private:

	//�÷��̾��� ��ü �����͸� �޴´�.
	IFuselageBaseData* m_fuselage_data;

	//�÷��̾� �����͸� �޴´�.
	IPlayerBaseData* m_player_data;
};
