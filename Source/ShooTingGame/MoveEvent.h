// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageBehavior.h"

#include "FuselageData.h"


/**
 * 움직일 위치를 계산하는것과 움직일 위치 데이터를 따로 두려고 했으나 MoveEvent들을 싱글톤화 해야해서 그냥 합쳐버렸다. 
 */

namespace MoveEvent {

	//왼쪽이동 클래스
	class LeftMove : public FuselageBehavior 
	{
	public:
		LeftMove() {};
		virtual ~LeftMove() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};

	//오른쪽이동 클래스
	class RightMove : public FuselageBehavior
	{
	public:
		RightMove () {};
		virtual ~RightMove() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//직진이동 클래스
	class ForwardMove : public FuselageBehavior
	{
	public:
		ForwardMove() {};
		virtual ~ForwardMove() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;
	};

	//뒤로이동 클래스
	class BackwardMove : public FuselageBehavior
	{
	public:
		BackwardMove() {};
		virtual ~BackwardMove() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

	//플레이어를 찾아가는 클래스
	class PlayerTracking : public FuselageBehavior
	{
	public:
		PlayerTracking() {};
		virtual ~PlayerTracking() final {};

	private:

		virtual bool execute(std::shared_ptr<FuselageCharacter> Character) final;

	};

}