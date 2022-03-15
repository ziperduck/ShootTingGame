// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "EnumPack.h"

#include "Command.h"

#include <memory>

/*���¸� �Է��ϴ� enum
*/
enum class EInputBehavior {
	IDLE = 0,
	LEFT_MOVE,
	RIGHT_MOVE,
	FORWARD_MOVE,
	BACKWARD_MOVE,
	TRACKING_MOVE,
	COLLISION,
	SHOOTING
};

/*��ü�� ���¸� ��üȭ�� Ŭ���� 
*/
class SHOOTINGGAME_API IFuselageState
{
public:
	IFuselageState() {};
	virtual ~IFuselageState() = 0{};

	//������¿� input�� �ް� �˸´� �����ൿ�� �����ϴ� �Լ�
	virtual void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input) = 0;

	//������¿� �Էµ� �̺�Ʈ�� �����ϰ� ���¿� �´� Ư�� �ൿ�� �ϴ� �Լ�
	virtual IFuselageState* Update(std::shared_ptr<FuselageCharacter> Character) = 0;
	
	//���¿� ���� ȣ���ϴ� �Լ�
	virtual void Enter(std::shared_ptr<FuselageCharacter> Character) = 0;

protected:

	//�Էµ� ��� command�� �����Ű�� ���� ��
	void m_knot_command(std::shared_ptr<FuselageCharacter> Character);

protected:

	std::queue<Command*> m_all_command;

	IFuselageState* m_update_state;
};
