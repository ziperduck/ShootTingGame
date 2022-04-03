// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FuselageMaker.h"

#include "FuselageBaseData.h"
#include "PlayerBaseData.h"

#include "ShootingCommand.h"
#include "MoveCommand.h"
#include "CollisionCommand.h"
#include "DeathCommand.h"

#include "PlayerFinishiMoveCommand.h"

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerCharacter.generated.h"


UCLASS()
class SHOOTINGGAME_API APlayerCharacter : public APawn, public IFuselageBaseData, public IPlayerBaseData
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//충돌시 호출되는 함수
	virtual void NotifyActorBeginOverlap(AActor* other) final;

	void m_left_right(float Direction);
	void m_up_dawn(float Direction);

	//총을 쏘기를 누르는 함수
	void PressedAttackKey();

	//총을 쏘기를 때는 함수
	void ReleasedAttackKey();

	//폭탄을 쏘는 함수
	void FinishiMoveKey();

private:

	//이동 관련 행동
	Command& m_leftmove_command = MoveCommand::BoundsLeftMove::getinstance();
	Command& m_rightmove_command = MoveCommand::BoundsRightMove::getinstance();
	Command& m_forwardmove_command = MoveCommand::BoundsForwardMove::getinstance();
	Command& m_backwardmove_command = MoveCommand::BoundsBackwardMove::getinstance();

	//공격 관련 행동
	Command& m_pressedshoot_command = ShootingCommand::PressedShoot::getinstance();

	Command& m_releaseshoot_command = ShootingCommand::ReleaseShoot::getinstance();

	//충돌 관련 행동
	Command& m_collision_command = CollisionCommand::CollisionAttack::getinstance();

	//충돌후 무적 처리
	Command& m_invincibility_on_command = CollisionCommand::CollisionInvincibilityOn::getinstance();

	//충돌후 무적 해체
	Command& m_invincibility_off_command = CollisionCommand::CollisionInvincibilityOff::getinstance();

	//죽음 관련 행동
	Command& m_death_command = DeathCommand::PlayerDie::getinstance();

	//지금한 모든 행동
	std::queue<Command*> m_all_command;


	//필살기 관련 플레이어 행동
	PlayerCommand& m_finishmove_command = PlayerFinishiMoveCommand::SpecialBoom::getinstance();

	//플레이어의 모든 행동
	std::queue<PlayerCommand*> m_all_player_command;


	//총쏘는 키를 눌렸는지 확인한다.
	bool m_pressed_attack_key;

	//충돌 이전 HP
	float m_overlap_befor_hp;

	//무적시간 제한
	const int32 m_invincibility_time = 180;

	//남은 무적시간 
	int32 m_invincibility_count = 0;
};
