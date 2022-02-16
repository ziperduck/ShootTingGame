// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageBehavior.h"

#include "FuselageData.h"


/**
 * ������ ��ġ�� ����ϴ°Ͱ� ������ ��ġ �����͸� ���� �η��� ������ MoveEvent���� �̱���ȭ �ؾ��ؼ� �׳� ���Ĺ��ȴ�. 
 */

namespace MoveEvent {

	//�����̵� Ŭ����
	class LeftMove : public FuselageBehavior 
	{
	public:
		LeftMove() {};
		virtual ~LeftMove() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};

	//�������̵� Ŭ����
	class RightMove : public FuselageBehavior
	{
	public:
		RightMove () {};
		virtual ~RightMove() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//�����̵� Ŭ����
	class ForwardMove : public FuselageBehavior
	{
	public:
		ForwardMove() {};
		virtual ~ForwardMove() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};

	//�ڷ��̵� Ŭ����
	class BackwardMove : public FuselageBehavior
	{
	public:
		BackwardMove() {};
		virtual ~BackwardMove() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//�÷��̾ ã�ư��� Ŭ����
	class PlayerTracking : public FuselageBehavior
	{
	public:
		PlayerTracking() {};
		virtual ~PlayerTracking() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

}