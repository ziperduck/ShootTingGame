// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShootingGameMode.generated.h"

/**
 * �� �̿��� ����� �ִ� ���Ӹ��
 */
UCLASS()
class SHOOTINGGAME_API AShootingGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	//������ �ٲ۴�.
	UFUNCTION(BlueprintCallable,Category ="UMG_Game")
	void ChangeWidget(TSubclassOf<UUserWidget> NewWidgetClass);

	//���� Ÿ�̸Ӹ� �����Ѵ�.
	UFUNCTION(BlueprintCallable, Category = "ShootingGameMode")
		void EnemySpawnStart(TArray<TSubclassOf<AActor>> Enemys, float Delay, FVector SpawnPointMin, FVector SpawnPointMax);

	//�� ������ �����
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
