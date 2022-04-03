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

	//�浹�� ȣ��Ǵ� �Լ�
	virtual void NotifyActorBeginOverlap(AActor* other) final;

	void m_left_right(float Direction);
	void m_up_dawn(float Direction);

	//���� ��⸦ ������ �Լ�
	void PressedAttackKey();

	//���� ��⸦ ���� �Լ�
	void ReleasedAttackKey();

	//��ź�� ��� �Լ�
	void FinishiMoveKey();

private:

	//�̵� ���� �ൿ
	Command& m_leftmove_command = MoveCommand::BoundsLeftMove::getinstance();
	Command& m_rightmove_command = MoveCommand::BoundsRightMove::getinstance();
	Command& m_forwardmove_command = MoveCommand::BoundsForwardMove::getinstance();
	Command& m_backwardmove_command = MoveCommand::BoundsBackwardMove::getinstance();

	//���� ���� �ൿ
	Command& m_pressedshoot_command = ShootingCommand::PressedShoot::getinstance();

	Command& m_releaseshoot_command = ShootingCommand::ReleaseShoot::getinstance();

	//�浹 ���� �ൿ
	Command& m_collision_command = CollisionCommand::CollisionAttack::getinstance();

	//�浹�� ���� ó��
	Command& m_invincibility_on_command = CollisionCommand::CollisionInvincibilityOn::getinstance();

	//�浹�� ���� ��ü
	Command& m_invincibility_off_command = CollisionCommand::CollisionInvincibilityOff::getinstance();

	//���� ���� �ൿ
	Command& m_death_command = DeathCommand::PlayerDie::getinstance();

	//������ ��� �ൿ
	std::queue<Command*> m_all_command;


	//�ʻ�� ���� �÷��̾� �ൿ
	PlayerCommand& m_finishmove_command = PlayerFinishiMoveCommand::SpecialBoom::getinstance();

	//�÷��̾��� ��� �ൿ
	std::queue<PlayerCommand*> m_all_player_command;


	//�ѽ�� Ű�� ���ȴ��� Ȯ���Ѵ�.
	bool m_pressed_attack_key;

	//�浹 ���� HP
	float m_overlap_befor_hp;

	//�����ð� ����
	const int32 m_invincibility_time = 180;

	//���� �����ð� 
	int32 m_invincibility_count = 0;
};
