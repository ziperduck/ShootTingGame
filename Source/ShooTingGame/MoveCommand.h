// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command.h"


/**
 * ������ ��ġ�� ����ϴ°Ͱ� ������ ��ġ �����͸� ���� �η��� ������ MoveCommand���� �̱���ȭ �ؾ��ؼ� �׳� ���Ĺ��ȴ�. 
 */

 /*
 * �����̴� ��Ȳ�� �̺�Ʈ��
 */
namespace MoveCommand {

	//�����̵� �̺�Ʈ
	class LeftMove : public Command 
	{
	public:
		LeftMove() {};
		virtual ~LeftMove() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};

	//�������̵� �̺�Ʈ
	class RightMove : public Command
	{
	public:
		RightMove () {};
		virtual ~RightMove() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//�����̵� �̺�Ʈ
	class ForwardMove : public Command
	{
	public:
		ForwardMove() {};
		virtual ~ForwardMove() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};

	//�ڷ��̵� �̺�Ʈ
	class BackwardMove : public Command
	{
	public:
		BackwardMove() {};
		virtual ~BackwardMove() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//�÷��̾ ã�ư��� �̺�Ʈ
	class PlayerTracking : public Command
	{
	public:
		PlayerTracking() {};
		virtual ~PlayerTracking() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

}