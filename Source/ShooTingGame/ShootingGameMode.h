// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShootingGameMode.generated.h"

/**
 * Test�� �̿��� ����� �ִ� ���Ӹ��
 */
UCLASS()
class SHOOTINGGAME_API AShootingGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	//������ �ٲ۴�.
	void ChangeWidget(TSubclassOf<UUserWidget> NewWidgetClass);

	static const FVector2D GetMapSize();

	static const FVector2D GetHalfMapSize();

protected:

	virtual void BeginPlay()final;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG_Game")
	TSubclassOf<UUserWidget> m_starte_widget_class;

	UPROPERTY() 
	UUserWidget*m_current_widget;



};
