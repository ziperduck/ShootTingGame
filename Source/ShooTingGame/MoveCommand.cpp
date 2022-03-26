// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveCommand.h"
#include "ShooTingGameModeBase.h"

#include "ShootingGameMode.h"

namespace MoveCommand
{

	//직접적으로 이동하는 행동

	Command& LeftMove::getinstance()
	{
		static Command* instance = new LeftMove;
		return *instance;
	}

	bool LeftMove::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("LeftMove execute function in Parameter Character is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("LeftMove execute"));

		Character->MoveTo(FVector::LeftVector);
		return true;
	}

	Command& RightMove::getinstance()
	{
		static Command* instance = new RightMove;
		return *instance;
	}

	bool RightMove::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("RightMove execute function in Parameter Character is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("RightMove execute"));

		Character->MoveTo(FVector::RightVector);
		return true;
	}

	Command& ForwardMove::getinstance()
	{
		static Command* instance = new ForwardMove;
		return *instance;
	}

	bool ForwardMove::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("ForwardMove execute function in Parameter Character is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("ForwardMove execute"));
		
		Character->MoveTo(FVector::ForwardVector);
		return true;
	}

	Command& BackwardMove::getinstance()
	{
		static Command* instance = new BackwardMove;
		return *instance;
	}

	bool BackwardMove::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("BackwardMove execute function in Parameter Character is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("BackwardMove execute"));

		Character->MoveTo(FVector::BackwardVector);
		return true;
	}


	Command& BoundsLeftMove::getinstance()
	{
		static Command* instance = new BoundsLeftMove;
		return *instance;
	}

	bool BoundsLeftMove::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("BoundsLeftMove::execute function in Parameter Character is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("BoundsLeftMove::execute"));

		FVector2D MapSize = AShootingGameMode::GetHalfMapSize();

		float CharacterMove_Y = Character->GetActor()->GetActorLocation().Y -Character->GetSpeed();

		if (CharacterMove_Y > -MapSize.Y)
		{
			Character->MoveTo(FVector::LeftVector);
		}

		return true;
	}

	Command& BoundsRightMove::getinstance()
	{
		static Command* instance = new BoundsRightMove;
		return *instance;
	}

	bool BoundsRightMove::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("BoundsRightMove::execute function in Parameter Character is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("BoundsRightMove::execute"));

		FVector2D MapSize = AShootingGameMode::GetHalfMapSize();

		float CharacterMove_Y = Character->GetActor()->GetActorLocation().Y + Character->GetSpeed();

		if (CharacterMove_Y < MapSize.Y)
		{
			Character->MoveTo(FVector::RightVector);
		}

		return true;
	}

	Command& BoundsForwardMove::getinstance()
	{
		static Command* instance = new BoundsForwardMove;
		return *instance;
	}

	bool BoundsForwardMove::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("BoundsForwardMove::execute function in Parameter Character is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("BoundsForwardMove::execute"));

		FVector2D MapSize = AShootingGameMode::GetHalfMapSize();

		float CharacterMove_X = Character->GetActor()->GetActorLocation().X + Character->GetSpeed();

		if (CharacterMove_X < MapSize.X)
		{
			Character->MoveTo(FVector::ForwardVector);
		}

		return true;
	}

	Command& BoundsBackwardMove::getinstance()
	{
		static Command* instance = new BoundsBackwardMove;
		return *instance;
	}

	bool BoundsBackwardMove::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("BoundsBackwardMove::execute function in Parameter Character is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("BoundsBackwardMove::execute"));

		FVector2D MapSize = AShootingGameMode::GetHalfMapSize();

		float CharacterMove_X = Character->GetActor()->GetActorLocation().X - Character->GetSpeed();

		if (CharacterMove_X > -MapSize.X)
		{
			Character->MoveTo(FVector::BackwardVector);
		}

		return true;
	}

	//플레이어에게 가는 이동방식

	Command& PlayerTracking::getinstance()
	{
		static Command* instance = new PlayerTracking;
		return *instance;
	}


	bool PlayerTracking::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("PlayerTracking execute function in Parameter Character is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("PlayerTracking execute"));

		//플레이어및 움직일 대상의 위치를 찾는다.
		FVector PlayerLocation 
			= Character->GetActor()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
		FVector MoveActorLocation = Character->GetActor()->GetActorLocation();

		float Speed = Character->GetSpeed();

		//플레이어와 위치를 빼고
		float Adjacent = PlayerLocation.X - MoveActorLocation.X;
		float Opposite = PlayerLocation.Y - MoveActorLocation.Y;
		
		//길이를 재고 길이 만큼 나눈다.
		float Hypotenuse = sqrt(pow(Adjacent, 2) + pow(Opposite, 2));

		FVector MoveLocation = { Adjacent / Hypotenuse, Opposite / Hypotenuse,0.0f };

		Character->MoveTo(MoveLocation);
		return true;
	}

	//플레이어를 붙어있는 이동방식

	Command& AttatchMove::getinstance()
	{
		static Command* instance = new AttatchMove;
		return *instance;
	}

	bool AttatchMove::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("AttatchMove::execute function in Parameter Character is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("AttatchMove::execute"));

		Character->MoveTo(FVector::BackwardVector);
		return true;
	}

}