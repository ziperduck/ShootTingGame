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
		virtual ~LeftMove() final {};

		static Command& getinstance();

	private:
		LeftMove() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};

	//오른쪽이동 이벤트
	class RightMove : public Command
	{
	public:
		virtual ~RightMove() final {};

		static Command& getinstance();

	private:
		RightMove() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//직진이동 이벤트
	class ForwardMove : public Command
	{
	public:
		virtual ~ForwardMove() final {};

		static Command& getinstance();

	private:
		ForwardMove() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};

	//뒤로이동 이벤트
	class BackwardMove : public Command
	{
	public:
		virtual ~BackwardMove() final {};

		static Command& getinstance();

	private:
		BackwardMove() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//왼쪽이동 이벤트
	class BoundsLeftMove : public Command
	{
	public:
		virtual ~BoundsLeftMove() final {};

		static Command& getinstance();

	private:
		BoundsLeftMove() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};

	//오른쪽이동 이벤트
	class BoundsRightMove : public Command
	{
	public:
		virtual ~BoundsRightMove() final {};

		static Command& getinstance();

	private:
		BoundsRightMove() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//직진이동 이벤트
	class BoundsForwardMove : public Command
	{
	public:
		virtual ~BoundsForwardMove() final {};

		static Command& getinstance();

	private:
		BoundsForwardMove() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};

	//뒤로이동 이벤트
	class BoundsBackwardMove : public Command
	{
	public:
		virtual ~BoundsBackwardMove() final {};

		static Command& getinstance();

	private:
		BoundsBackwardMove() {};

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//플레이어를 찾아가는 이벤트
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