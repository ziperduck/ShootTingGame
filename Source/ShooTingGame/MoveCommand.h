// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command.h"


/**
 * 움직일 위치를 계산하는것과 움직일 위치 데이터를 따로 두려고 했으나 MoveCommand들을 싱글톤화 해야해서 그냥 합쳐버렸다. 
 */

 /*
 * 움직이는 상황의 이벤트들
 */
namespace MoveCommand {

	//왼쪽이동 이벤트
	class LeftMove : public Command 
	{
	public:
		LeftMove() {};
		virtual ~LeftMove() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};

	//오른쪽이동 이벤트
	class RightMove : public Command
	{
	public:
		RightMove () {};
		virtual ~RightMove() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//직진이동 이벤트
	class ForwardMove : public Command
	{
	public:
		ForwardMove() {};
		virtual ~ForwardMove() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};

	//뒤로이동 이벤트
	class BackwardMove : public Command
	{
	public:
		BackwardMove() {};
		virtual ~BackwardMove() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//플레이어를 찾아가는 이벤트
	class PlayerTracking : public Command
	{
	public:
		PlayerTracking() {};
		virtual ~PlayerTracking() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

}