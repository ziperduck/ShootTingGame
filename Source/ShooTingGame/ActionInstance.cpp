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
	case EVariousAction::ATTACHPLAYER_MOVE:
	{
		static IAction* Event = new AttachPlayer();
		return Event;
	}
	case EVariousAction::ATTACK:
	{
		static IAction* Event = new Attack();
		return Event;
	}
	case EVariousAction::BOOM_ATTACK:
	{
		static IAction* Event = new BoomAttack();
		return Event;
	}
	case EVariousAction::SPECIAL_BOOM:
	{
		static IAction* Event = new SpecialBoom();
		return Event;
	}
	case EVariousAction::HEALING:
	{
		static IAction* Event = new Healing();
		return Event;
	}
	case EVariousAction::WEAPON_UPGRADE:
	{
		static IAction* Event = new WeaponUpgrad();
		return Event;
	}
	case EVariousAction::DROP_ITEM:
	{
		static IAction* Event = new DropItem();
		return Event;
	}
	case EVariousAction::FUSELAGE_DIVIDE:
	{
		static IAction* Event = new FuselageDivide();
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
