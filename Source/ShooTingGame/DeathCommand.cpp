// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathCommand.h"

#include "ShootingGameMode.h"

#include "GameOverWidget.h"

#include <random>

#include <Kismet/GameplayStatics.h>

namespace DeathCommand {
	Command& FuselageRemove::getinstance()
	{
		static Command* instance = new FuselageRemove;
		return *instance;
	}
	bool FuselageRemove::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("FuselageRemove execute function in Parameter Character is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("FuselageRemove execute"));

		Character->Death();
		return true;
	}

	Command& EnemyDie::getinstance()
	{
		static Command* instance = new EnemyDie;
		return *instance;
	}

	bool EnemyDie::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("EnemyDie execute function in Parameter Character is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("EnemyDie execute"));

		Character->Death();
		return true;
	}
	Command& PlayerDie::getinstance()
	{
		static Command* instance = new PlayerDie;
		return *instance;
	}
	bool PlayerDie::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("PlayerDie execute function in Parameter Character is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("PlayerDie execute"));
		
		UWorld* CharacterWorld = Character->GetActor()->GetWorld();

		checkf(CharacterWorld != nullptr, TEXT("CharacterWorld is nullptr"));
		

		UGameplayStatics::GetPlayerController(CharacterWorld, 0)->bShowMouseCursor = true;

		AShootingGameMode* GameMode = Cast<AShootingGameMode>(UGameplayStatics::GetGameMode(CharacterWorld));
		GameMode->ChangeWidget(StaticLoadClass(UGameOverWidget::StaticClass(),NULL
				, TEXT("Class'/Game/Blueprint/Widget/BP_GameOverWidget.BP_GameOverWidget_C'")));

		//모든 엑터를 제거한다.
		TArray<AActor*> AllActor;
		UGameplayStatics::GetAllActorsOfClass(CharacterWorld, AActor::StaticClass(), AllActor);


		for (auto Actor : AllActor)
		{
			if (Character->GetActor() != Actor)
			{
				Actor->Destroy();
			}
		}
		//그리고 스폰도 없앤다.
		GameMode->EnemySpawnStop();

		Character->Death();

		return true;
	}
}