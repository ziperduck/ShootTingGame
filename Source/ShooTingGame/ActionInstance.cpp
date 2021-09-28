// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionInstance.h"

IAction* ChangeAction(const EVariousAction& Action) 
{
	UE_LOG(LogTemp, Log, TEXT("ChageAction"));

	switch (Action)
	{
	case EVariousAction::EastMove:
	{
		static IAction* Event = new EastMove();
		return Event;
	}
	case EVariousAction::WestMove:
	{
		static IAction* Event = new WestMove();
		return Event;
	}
	case EVariousAction::SouthMove:
	{
		static IAction* Event = new SouthMove();
		return Event;
	}
	case EVariousAction::NorthMove:
	{
		static IAction* Event = new NorthMove();
		return Event;
	}
	case EVariousAction::Shooting:
	{
		static IAction* Event = new Shooting();
		return Event;
	}
	case EVariousAction::Struck:
	{
		static IAction* Event = new Struck();
		return Event;
	}
	case EVariousAction::Death:
	{
		static IAction* Event = new Death();
		return Event;
	}
	default:
		checkNoEntry();
		return nullptr;
	}
}
