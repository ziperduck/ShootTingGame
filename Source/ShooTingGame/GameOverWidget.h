// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Containers/Map.h>

#include "SavePlayerScore.h"

#include "PlayerBaseData.h"


#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverWidget.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTINGGAME_API UGameOverWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	//게임을 다시 시작하다
	UFUNCTION(BlueprintCallable, Category = "GameOverWidget")
	void ReStarte();

	//메인메뉴로 돌아간다.
	UFUNCTION(BlueprintCallable, Category = "GameOverWidget")
	void BackMainMenu(FString LevelName);

	//현재 데이터를 저장한다.
	UFUNCTION(BlueprintCallable, Category = "GameOverWidget")
	void SaveCurrentNameScore();


	//현재 이름을 설정한다.
	UFUNCTION(BlueprintCallable, Category = "GameOverWidget")
	void SetCurrentName(const FString CurrentName);


	//현재 이름을 받아온다.
	UFUNCTION(BlueprintCallable, Category = "GameOverWidget")
	const FString GetCurrentName() const;

	//현재 이름을 받아온다.
	UFUNCTION(BlueprintCallable, Category = "GameOverWidget")
	const int32 GetCurrentScore() const;

	//저장된 데이터를 저장한다.
	UFUNCTION(BlueprintGetter, Category = "GameOverWidget")
	TMap<FString, int32> GetSavePlayerNameScore() const;


public:

	virtual void NativeConstruct() final;

private:

	//세이브 이름과 인덱스
	const FString m_solt_name = TEXT("SaveGame");

	const int32 m_solt_index = 0;


	//현재 이름과 데이터
	FString m_current_name;

	int32 m_current_score;


	//세이브 데이터
	USavePlayerScore* m_save_game;

	//저장된 데이터
	UPROPERTY(BlueprintGetter = GetSavePlayerNameScore, Category = "GameOverWidget")
	TMap<FString, int32> m_save_namescore;
};
