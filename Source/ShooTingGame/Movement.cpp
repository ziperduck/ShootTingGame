// Fill out your copyright notice in the Description page of Project Settings.

#include "Movement.h"
#include "EnumPack.h"
#include "Airframe.h"
#include "EnemyDragon.h"
#include "Rifle.h"
#include "FireShoot.h"
#include "MeteoricStone.h"
#include "LaserBeam.h"
#include "PlayerCharacter.h"
#include "WeaponKit.h"
#include <set>
#include <Engine/Classes/Kismet/GameplayStatics.h>
#include "CoreMinimal.h"
#include <Engine/Classes/Components/SphereComponent.h>



const FVector& CalculationRatioSpeed(const FVector& Ratio) {
	return Ratio;
}

void EastMove::Execute(AActor* Target) {

	UE_LOG(LogTemp, Log, TEXT("EastMove Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	IFuselage* Fuselage = Cast<IFuselage>(Target);
	checkf(Fuselage != nullptr, TEXT("Fuselage is nullptr"));

	float Speed = Fuselage->GetSpeed();
	FVector EastVector = CalculationRatioSpeed({ 0.0f,Speed,  0.0f });
	Fuselage->MoveLocation(EastVector);
}

void WestMove::Execute(AActor* Target) {

	UE_LOG(LogTemp, Log, TEXT("WestMove Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	IFuselage* Fuselage = Cast<IFuselage>(Target);
	checkf(Fuselage != nullptr, TEXT("Fuselage is nullptr"));

	float Speed = Fuselage->GetSpeed();
	FVector WestVector = CalculationRatioSpeed({ 0.0f,-Speed,  0.0f });
	Fuselage->MoveLocation(WestVector);
}

void SouthMove::Execute(AActor* Target) {

	UE_LOG(LogTemp, Log, TEXT("SouthMove Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	IFuselage* Fuselage = Cast<IFuselage>(Target);
	checkf(Fuselage != nullptr, TEXT("Fuselage is nullptr"));

	float Speed = Fuselage->GetSpeed();
	FVector SouthVector = CalculationRatioSpeed({ -Speed,0.0f,  0.0f });
	Fuselage->MoveLocation(SouthVector);
}

void NorthMove::Execute(AActor* Target) {

	UE_LOG(LogTemp, Log, TEXT("NorthMove Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	IFuselage* Fuselage = Cast<IFuselage>(Target);
	checkf(Fuselage != nullptr, TEXT("Fuselage is nullptr"));

	float Speed = Fuselage->GetSpeed();
	FVector NortVector = CalculationRatioSpeed({ Speed,0.0f,  0.0f });
	Fuselage->MoveLocation(NortVector);
}


void Guidance::Execute(AActor* Target) {

	UE_LOG(LogTemp, Log, TEXT("NorthMove Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	FVector PlayerLocation = Target->GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	FVector TargetLocation = Target->GetActorLocation();

	IFuselage* Fuselage = Cast<IFuselage>(Target);
	checkf(Fuselage != nullptr, TEXT("Fuselage is nullptr"));

	float Speed = Fuselage->GetSpeed();

	float Adjacent = PlayerLocation.X - TargetLocation.X;
	float Opposite = PlayerLocation.Y - TargetLocation.Y ;
	float Hypotenuse = sqrt(pow(Adjacent, 2) + pow(Opposite, 2));

	FVector MoveLocation = { Adjacent / Hypotenuse, Opposite / Hypotenuse,0.0f };
	MoveLocation *= Speed;

	Fuselage->MoveLocation(MoveLocation);
}

void AttachPlayer::Execute(AActor* Target)
{
	UE_LOG(LogTemp, Log, TEXT("NorthMove Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	Target->K2_AttachRootComponentToActor(Target->GetWorld()->GetFirstPlayerController()->GetPawn());

}


void Shooting::Execute(AActor* Target) {
	UE_LOG(LogTemp, Log, TEXT("Shooting Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	UWorld* TargetWorld = Target->GetWorld();
	FVector TargetLocation = Target->GetActorLocation();

	IAirframe* Airframe = Cast<IAirframe>(Target);
	checkf(Airframe != nullptr, TEXT("Airframe is nullptr"));

	FWeaponStruct WeaponStruct = Airframe->GetWeapon();
	//GetWeapon으로 무기를 만들자.
	
	switch (WeaponStruct.m_weapon)

	{
	case EVariousWeapon::RIFLE_WEAPON:
	{
		TArray<FVector> SpawnLocations;
		switch (WeaponStruct.m_weapon_level)
		{
		case 1:
			SpawnLocations.Add(TargetLocation);
			break;
		case 2:
			SpawnLocations.Add(TargetLocation);
			SpawnLocations.Add(TargetLocation - FVector{ 0.0f,40.0f,0.0f});
			SpawnLocations.Add(TargetLocation + FVector{ 0.0f,40.0f,0.0f });
			break;
		case 3:
			SpawnLocations.Add(TargetLocation);
			SpawnLocations.Add(TargetLocation - FVector{ 0.0f,40.0f,0.0f });
			SpawnLocations.Add(TargetLocation + FVector{ 0.0f,40.0f,0.0f });
			SpawnLocations.Add(TargetLocation - FVector{ 0.0f,80.0f,0.0f });
			SpawnLocations.Add(TargetLocation + FVector{ 0.0f,80.0f,0.0f });
			break;
		default:
			break;
		}
		for (auto i : SpawnLocations)
		{
			ARifle* Rifle = TargetWorld->SpawnActor<ARifle>(i, FRotator::ZeroRotator);
			Rifle->WeaponInitalize(WeaponStruct);
			Rifle->SetLifeSpan(WeaponStruct.m_lifespan);
		}
		break;
	}
		break;
	case EVariousWeapon::LASERBEAM_WEAPON:
	{
		FTransform LaserScale{ FQuat{},FVector::ZeroVector, FVector::OneVector };
		switch (WeaponStruct.m_weapon_level)
		{
		case 1:
			LaserScale.SetScale3D(FVector::OneVector);
			LaserScale.SetScale3D(FVector{ 1.0f,5.0f,1.0f });
			break;
		case 2:
			LaserScale.SetScale3D(FVector{ 1.0f,15.0f,1.0f });
			WeaponStruct.m_attack_power = 2;
			break;
		case 3:
			LaserScale.SetScale3D(FVector{1.0f,25.0f,1.0f });
			WeaponStruct.m_attack_power = 3;
			break;
		default:
			break;
		}
		ALaserBeam* LaserBeam = TargetWorld->SpawnActor<ALaserBeam>(ALaserBeam::StaticClass(), LaserScale);
		LaserBeam->WeaponInitalize(WeaponStruct);
		LaserBeam->SetLifeSpan(WeaponStruct.m_lifespan);
		break;
	}
		break;
	case EVariousWeapon::METEORICSTONE_WEAPON:
	{
		if (Airframe->GetMaxHP() > 1)
		{
			AMeteoricStone* MeteoricActor
				= TargetWorld->SpawnActor<AMeteoricStone>(TargetLocation, FRotator::ZeroRotator);
			MeteoricActor->SetLifeSpan(10.0f);
			MeteoricActor->Initialize_Implementation(
				WeaponStruct.m_speed, Airframe->GetMaxHP() - 1, WeaponStruct);
		}
	}
		break;
	case EVariousWeapon::FIRESHOOT_WEAPON:
	{
		AFireShoot* FireShoot = TargetWorld->SpawnActor<AFireShoot>(TargetLocation, FRotator::ZeroRotator);
		FireShoot->WeaponInitalize(WeaponStruct);
		FireShoot->SetLifeSpan(WeaponStruct.m_lifespan);
		break;
	}
		break;
	default:
		break;
	}
	
}

void Attack::Execute(AActor* Target) {
	UE_LOG(LogTemp, Log, TEXT("Attack Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	IFuselage* TargetFuselage = Cast<IFuselage>(Target);
	checkf(TargetFuselage != nullptr, TEXT("Fuselage is nullptr"));

	//타격이 가능한 대상을 선별한다.
	std::set<EFuselageKind> Wanted;
	switch (TargetFuselage->GetKind())
	{
	case EFuselageKind::PLAYER_FUSELAGE:
	{
		Wanted.insert(EFuselageKind::ENEMY_WEAPON);
	}
	case EFuselageKind::PLAYER_WEAPON:
	{
		Wanted.insert(EFuselageKind::ENEMY_FUSELAGE);
		break;
	}
	case EFuselageKind::ENEMY_FUSELAGE:
	{
		Wanted.insert(EFuselageKind::PLAYER_WEAPON);
	}
	case EFuselageKind::ENEMY_WEAPON:
	{
		Wanted.insert(EFuselageKind::PLAYER_FUSELAGE);
		break;
	}
	default:
		break;
	}


	TSet<AActor*> OverlapActors;
	Target->GetOverlappingActors(OverlapActors);

	UE_LOG(LogTemp, Log, TEXT("Healing Player Search Size %d"), OverlapActors.GetAllocatedSize());

	//그외
	for (auto& i : OverlapActors)
	{
		IFuselage* OverlapFuselage = Cast<IFuselage>(i);
		checkf(OverlapFuselage != nullptr, TEXT("OverlapFuselage is nullptr"));


		for (auto& k : Wanted)
		{
			if (OverlapFuselage->GetKind() == k)
			{
				OverlapFuselage->AttackFuselage(-TargetFuselage->GetAttackPower());
				break;
			}
		}

	}
}

void BoomAttack::Execute(AActor* Target) {
	UE_LOG(LogTemp, Log, TEXT("BoomAttack Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	const UWorld* TargetWorld = Target->GetWorld();

	IAirframe* TargetAirframe = Cast<IAirframe>(Target);
	checkf(TargetAirframe != nullptr, TEXT("Fuselage is nullptr"));

	if (TargetAirframe->GetWeapon().m_weapon != EVariousWeapon::BOOM_WEAPON)
	{
		UE_LOG(LogTemp, Log, TEXT("TargetAirframe Weapon is not Boom"));
		return;
	}

	TArray<AActor*> AllFuselageActor;
	UGameplayStatics::GetAllActorsOfClassWithTag(
		TargetWorld, AActor::StaticClass(), TEXT("Airframe"), AllFuselageActor);

	//그외
	for (auto& i : AllFuselageActor)
	{
		IFuselage* OverlapFuselage = Cast<IFuselage>(i);
		checkf(OverlapFuselage != nullptr, TEXT("OverlapFuselage is nullptr"));
	
		if (Target != i && Target->GetDistanceTo(i) < 200.0f)
		{
			UE_LOG(LogTemp, Log, TEXT("i"));
			OverlapFuselage->AttackFuselage(-TargetAirframe->GetWeapon().m_attack_power);
		}
	}
}

void Healing::Execute(AActor* Target) {
	UE_LOG(LogTemp, Log, TEXT("Healing Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	IFuselage* Fuselage = Cast<IFuselage>(Target);
	checkf(Fuselage != nullptr, TEXT("Fuselage is nullptr"));


	TSet<AActor*> OverlapActors;
	Target->GetOverlappingActors(OverlapActors);

	UE_LOG(LogTemp, Log, TEXT("Healing Player Search Size %d"), OverlapActors.Num());
	
	//그외
	for (auto& i : OverlapActors)
	{
		APlayerCharacter* OverlapFuselage = Cast<APlayerCharacter>(i);
		if (OverlapFuselage != nullptr)
		{
			UE_LOG(LogTemp, Log, TEXT("Healing Heal"));
			OverlapFuselage->AttackFuselage(Fuselage->GetAttackPower());
			break;
		}
	}

}

void WeaponUpgrad::Execute(AActor* Target)
{
	UE_LOG(LogTemp, Log, TEXT("WeaponChange Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	AWeaponKit* WeaponKit = Cast<AWeaponKit>(Target);
	checkf(WeaponKit != nullptr, TEXT("Item is nullptr"));

	TSet<AActor*> OverlapActors;
	WeaponKit->GetOverlappingActors(OverlapActors);

	UE_LOG(LogTemp, Log, TEXT("Healing Player Search Size %d"), OverlapActors.Num());

	//그외
	for (auto& i : OverlapActors)
	{
		APlayerCharacter* OverlapFuselage = Cast<APlayerCharacter>(i);
		if (OverlapFuselage != nullptr)
		{
			UE_LOG(LogTemp, Log, TEXT("WeaponChange"));
			OverlapFuselage->UpgradeWeapon();
			break;
		}
	}
}

void Death::Execute(AActor* Target) {
	UE_LOG(LogTemp, Log, TEXT("Death Excute"));
	checkf(Target != nullptr, TEXT("Target is nullptr"));

	Target->SetActorEnableCollision(false);

	UWorld* TargetWorld = Target->GetWorld();

	IFuselage* Fuselage = Cast<IFuselage>(Target);
	checkf(Fuselage != nullptr, TEXT("Fuselage is nullptr"));

	TargetWorld->DestroyActor(Target);
}

