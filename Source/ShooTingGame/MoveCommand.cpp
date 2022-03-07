// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveCommand.h"
#include "ShooTingGameModeBase.h"

namespace MoveCommand
{

	bool LeftMove::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("LeftMove execute function in Parameter Character is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("LeftMove execute"));

		Character->MoveTo(FVector::LeftVector);
		return true;
	}

	bool RightMove::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("RightMove execute function in Parameter Character is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("RightMove execute"));

		Character->MoveTo(FVector::RightVector);
		return true;
	}

	bool ForwardMove::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("ForwardMove execute function in Parameter Character is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("ForwardMove execute"));
		
		Character->MoveTo(FVector::ForwardVector);
		return true;
	}

	bool BackwardMove::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("BackwardMove execute function in Parameter Character is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("BackwardMove execute"));

		Character->MoveTo(FVector::BackwardVector);
		return true;
	}

	bool PlayerTracking::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		checkf(Character.get() != nullptr, TEXT("PlayerTracking execute function in Parameter Character is nullptr"));
		UE_LOG(LogTemp, Log, TEXT("PlayerTracking execute"));

		//�÷��̾�� ������ ����� ��ġ�� ã�´�.
		FVector PlayerLocation 
			= Character->GetActor()->GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
		FVector MoveActorLocation = Character->GetActor()->GetActorLocation();

		float Speed = Character->GetSpeed();

		//�÷��̾�� ��ġ�� ����
		float Adjacent = PlayerLocation.X - MoveActorLocation.X;
		float Opposite = PlayerLocation.Y - MoveActorLocation.Y;
		
		//���̸� ��� ���� ��ŭ ������.
		float Hypotenuse = sqrt(pow(Adjacent, 2) + pow(Opposite, 2));

		FVector MoveLocation = { Adjacent / Hypotenuse, Opposite / Hypotenuse,0.0f };

		Character->MoveTo(MoveLocation);
		return true;
	}

	bool AttatchMove::execute(std::shared_ptr<FuselageCharacter> Character)
	{
		return true;
	}

}