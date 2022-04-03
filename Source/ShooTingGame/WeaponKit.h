// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"

#include "FuselageBaseData.h"

#include "MoveCommand.h"
#include "CollisionCommand.h"
#include "DeathCommand.h"

#include "SpecialEvent.h"

#include "GameFramework/Actor.h"
#include "WeaponKit.generated.h"


/*
* 무기교체를 어떻게 할것인지 고민해봐야한다.
*/
UCLASS()
class SHOOTINGGAME_API AWeaponKit : public AActor, public IFuselageBaseData
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponKit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* Actor) final;

	//현재 무기키트의 무기종류를 바꾼다.
	UFUNCTION(BlueprintCallable, Category = "WeaponKit")
		FString ChangeWeapon();

private:

	//모든 이동 관련 명령어. 
	std::vector<Command*> m_all_directs_command;

	//충돌전까지 움직임. 
	int32 m_directs_number[2];

	//충돌 관련 명령어
	Command& m_collision_weaponchange_command = CollisionCommand::CollisionChangeWeapon::getinstance();

	//죽음 관련 명령어
	Command& m_death_command = DeathCommand::FuselageRemove::getinstance();

	//모든 행동들을 실행시키는 함수
	std::queue<Command*> m_behavior;

	//움직이기 전 플레이어의 위치
	FVector m_actor_befor_location;

	//계속 바꿔주는 플레이어의 무기들
	std::vector<std::shared_ptr<WeaponStruct>>  m_player_weapon;

	//무기의 앞글자만 딴다.
	std::vector<FString>  m_weapon_first_letter;

	//무기의 사이클을 계속 체크한다.
	int32 m_weapon_cycle_count;
};
