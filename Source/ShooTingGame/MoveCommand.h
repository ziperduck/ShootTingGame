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
		virtual ~LeftMove() final {};

		static Command& getinstance();

	private:
		LeftMove() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};

	//�������̵� �̺�Ʈ
	class RightMove : public Command
	{
	public:
		virtual ~RightMove() final {};

		static Command& getinstance();

	private:
		RightMove() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//�����̵� �̺�Ʈ
	class ForwardMove : public Command
	{
	public:
		virtual ~ForwardMove() final {};

		static Command& getinstance();

	private:
		ForwardMove() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};

	//�ڷ��̵� �̺�Ʈ
	class BackwardMove : public Command
	{
	public:
		virtual ~BackwardMove() final {};

		static Command& getinstance();

	private:
		BackwardMove() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//�����̵� �̺�Ʈ
	class BoundsLeftMove : public Command
	{
	public:
		virtual ~BoundsLeftMove() final {};

		static Command& getinstance();

	private:
		BoundsLeftMove() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};

	//�������̵� �̺�Ʈ
	class BoundsRightMove : public Command
	{
	public:
		virtual ~BoundsRightMove() final {};

		static Command& getinstance();

	private:
		BoundsRightMove() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//�����̵� �̺�Ʈ
	class BoundsForwardMove : public Command
	{
	public:
		virtual ~BoundsForwardMove() final {};

		static Command& getinstance();

	private:
		BoundsForwardMove() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};

	//�ڷ��̵� �̺�Ʈ
	class BoundsBackwardMove : public Command
	{
	public:
		virtual ~BoundsBackwardMove() final {};

		static Command& getinstance();

	private:
		BoundsBackwardMove() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//�÷��̾ ã�ư��� �̺�Ʈ
	class PlayerTracking : public Command
	{
	public:
		virtual ~PlayerTracking() final {};

		static Command& getinstance();

	private:
		PlayerTracking() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	class AttatchMove : public Command
	{
	public:
		virtual ~AttatchMove() final {};

		static Command& getinstance();

	private:
		AttatchMove() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};
}