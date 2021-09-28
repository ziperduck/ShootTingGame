// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionInstance.h"

IAction* ChangeAction(const EVariousAction& Action) 
{
	UE_LOG(LogTemp, Log, TEXT("ChageAction"));

	switch (Action)
	{
	case EVariousAction::EAST_MOVE:
	{
		static IAction* Event = new EastMove();
		return Event;
	}
	case EVariousAction::WEST_MOVE:
	{
		static IAction* Event = new WestMove();
		return Event;
	}
	case EVariousAction::SOUTH_MOVE:
	{
		static IAction* Event = new SouthMove();
		return Event;
	}
	case EVariousAction::NORTH_MOVE:
	{
		static IAction* Event = new NorthMove();
		return Event;
	}
	case EVariousAction::SHOOTING:
	{
		static IAction* Event = new Shooting();
		return Event;
	}
	case EVariousAction::GUIDANCE_MOVE:
	{
		static IAction* Event = new Guidance();
		return Event;
	}
	case EVariousAction::ATTACK:
	{
		static IAction* Event = new Attack();
		return Event;
	}
	case EVariousAction::DEATH:
	{
		static IAction* Event = new Death();
		return Event;
	}
	default:
		checkNoEntry();
		return nullptr;
	}
}
