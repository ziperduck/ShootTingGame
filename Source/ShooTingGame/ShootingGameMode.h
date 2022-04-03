// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShootingGameMode.generated.h"

/**
 * 를 이용해 만들고 있는 게임모드
 */
UCLASS()
class SHOOTINGGAME_API AShootingGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	//위젯을 바꾼다.
	UFUNCTION(BlueprintCallable,Category ="UMG_Game")
	void ChangeWidget(TSubclassOf<UUserWidget> NewWidgetClass);

	//스폰 타이머를 생성한다.
	UFUNCTION(BlueprintCallable, Category = "ShootingGameMode")
		void EnemySpawnStart(TArray<TSubclassOf<AActor>> Enemys, float Delay, FVector SpawnPointMin, FVector SpawnPointMax);

	//적 스폰을 멈춘다
	UFUNCTION(BlueprintCallable, Category = "ShootingGameMode")
		void EnemySpawnStop();

	static const FVector2D GetMapSize();

	static const FVector2D GetHalfMapSize();

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason)override;
protected:

	virtual void BeginPlay()final;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG_Game")
	TSubclassOf<UUserWidget> m_starte_widget_class;

	UPROPERTY() 
	UUserWidget*m_current_widget;

	FTimerHandle m_spawn_timer;

};
