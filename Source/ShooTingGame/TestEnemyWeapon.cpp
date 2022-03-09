// Fill out your copyright notice in the Description page of Project Settings.


#include "TestEnemyWeapon.h"

#include "TestFireBall.h"

namespace EnemyWeapon {

	FireBallLvel_1::FireBallLvel_1()
		: WeaponStruct(Cast<UClass>(StaticLoadClass(ATestFireBall::StaticClass(), NULL,
			TEXT("Class'/Game/Blueprint/BP_TestFireBall.BP_TestFireBall_C'")))
			, 1, 1.0f, 1.0f, FVector(1.0f, 1.0f, 1.0f)) {}
	
	FireBallLvel_1::~FireBallLvel_1()
	{

	}

	void FireBallLvel_1::CreateWeapon(AActor* Gunner)
	{
		UE_LOG(LogTemp, Log, TEXT("Create LaserBeamLvel_1"));

		//AActor를 생성한다.
		AActor* Weapon = CheckCreateActor(m_weapon_class, Gunner);

		Weapon->SetActorScale3D(m_scale);
		Weapon->SetLifeSpan(m_lifespan);

		IFuselageBaseData* WeaponBaseData = Cast<IFuselageBaseData>(Weapon);

		//레벨마다 다른 공격력을 AActor에 조절한다.
		WeaponBaseData->GetBaseData()->SetAttackPower(m_power);
	}
	WeaponStruct* FireBallLvel_1::GetUpgradeWeapon()
	{
		return new FireBallLvel_1;
	}
}