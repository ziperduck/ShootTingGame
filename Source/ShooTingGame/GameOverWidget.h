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

	//������ �ٽ� �����ϴ�
	UFUNCTION(BlueprintCallable, Category = "GameOverWidget")
	void ReStarte();

	//���θ޴��� ���ư���.
	UFUNCTION(BlueprintCallable, Category = "GameOverWidget")
	void BackMainMenu(FString LevelName);

	//���� �����͸� �����Ѵ�.
	UFUNCTION(BlueprintCallable, Category = "GameOverWidget")
	void SaveCurrentNameScore();


	//���� �̸��� �����Ѵ�.
	UFUNCTION(BlueprintCallable, Category = "GameOverWidget")
	void SetCurrentName(const FString CurrentName);


	//���� �̸��� �޾ƿ´�.
	UFUNCTION(BlueprintCallable, Category = "GameOverWidget")
	const FString GetCurrentName() const;

	//���� �̸��� �޾ƿ´�.
	UFUNCTION(BlueprintCallable, Category = "GameOverWidget")
	const int32 GetCurrentScore() const;

	//����� �����͸� �����Ѵ�.
	UFUNCTION(BlueprintGetter, Category = "GameOverWidget")
	TMap<FString, int32> GetSavePlayerNameScore() const;


public:

	virtual void NativeConstruct() final;

private:

	//���̺� �̸��� �ε���
	const FString m_solt_name = TEXT("SaveGame");

	const int32 m_solt_index = 0;


	//���� �̸��� ������
	FString m_current_name;

	int32 m_current_score;


	//���̺� ������
	USavePlayerScore* m_save_game;

	//����� ������
	UPROPERTY(BlueprintGetter = GetSavePlayerNameScore, Category = "GameOverWidget")
	TMap<FString, int32> m_save_namescore;
};
