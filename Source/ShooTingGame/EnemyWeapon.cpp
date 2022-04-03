// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyWeapon.h"

#include "FireBall.h"

namespace EnemyWeapon {

	FireBallLvel_1::FireBallLvel_1()
		: WeaponStruct(Cast<UClass>(StaticLoadClass(AFireBall::StaticClass(), NULL,
			TEXT("Class'/Game/Blueprint/BP_FireBall.BP_FireBall_C'")))
			, 1, 1.0f, 1.0f, FVector(1.0f, 1.0f, 1.0f),1.5f) {}
	
	FireBallLvel_1::~FireBallLvel_1()
	{

	}

	void FireBallLvel_1::CreateWeapon(AActor* Gunner)
	{
		UE_LOG(LogTemp, Log, TEXT("Create LaserBeamLvel_1"));

		//AActor를 생성한다.
		AActor* Weapon = CheckCreateActor(m_weapon_class, Gunner);

		Weapon->SetActorScale3D(m_scale);
		Weapon->SetLifeSpan(float(m_lifespan_tick));

		IFuselageBaseData* WeaponBaseData = Cast<IFuselageBaseData>(Weapon);

		//레벨마다 다른 공격력을 AActor에 조절한다.
		WeaponBaseData->GetBaseData()->SetAttackPower(m_power);
	}
	WeaponStruct* FireBallLvel_1::GetUpgradeWeapon()
	{
		return this;
	}
	void FireBallLvel_1::PressedShoot(AActor* Gunner)
	{
		if (Gunner->GetWorldTimerManager().IsTimerActive(m_weapon_timer))
		{
			return;
		}

		Gunner->GetWorldTimerManager().SetTimer(m_weapon_timer, m_load_time, false);

		CreateWeapon(Gunner);
	}

	void FireBallLvel_1::ReleaseShoot(AActor* Gunner)
	{
	}
}