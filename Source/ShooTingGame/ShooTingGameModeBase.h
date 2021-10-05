// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShooTingGameModeBase.generated.h"


/*
* mode base에서 모든 오브젝트의 생성과 액션을 제어한다.
*
*/

class FuselageManager;

UCLASS()
class SHOOTINGGAME_API AShooTingGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AShooTingGameModeBase();


	UFUNCTION(BlueprintCallable, Category = "ShootingGame_UMG")
		void ChangeWidget(TSubclassOf<UUserWidget> NewWidget);

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ShootingGame_UMG")
		TSubclassOf<UUserWidget> m_start_widget;

	UPROPERTY()
		UUserWidget* m_current_widget;

};
