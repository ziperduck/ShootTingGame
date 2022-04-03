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
* ���ⱳü�� ��� �Ұ����� ����غ����Ѵ�.
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

	//���� ����ŰƮ�� ���������� �ٲ۴�.
	UFUNCTION(BlueprintCallable, Category = "WeaponKit")
		FString ChangeWeapon();

private:

	//��� �̵� ���� ��ɾ�. 
	std::vector<Command*> m_all_directs_command;

	//�浹������ ������. 
	int32 m_directs_number[2];

	//�浹 ���� ��ɾ�
	Command& m_collision_weaponchange_command = CollisionCommand::CollisionChangeWeapon::getinstance();

	//���� ���� ��ɾ�
	Command& m_death_command = DeathCommand::FuselageRemove::getinstance();

	//��� �ൿ���� �����Ű�� �Լ�
	std::queue<Command*> m_behavior;

	//�����̱� �� �÷��̾��� ��ġ
	FVector m_actor_befor_location;

	//��� �ٲ��ִ� �÷��̾��� �����
	std::vector<std::shared_ptr<WeaponStruct>>  m_player_weapon;

	//������ �ձ��ڸ� ����.
	std::vector<FString>  m_weapon_first_letter;

	//������ ����Ŭ�� ��� üũ�Ѵ�.
	int32 m_weapon_cycle_count;
};
