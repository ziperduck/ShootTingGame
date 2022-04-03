// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWeapon.h"

#include "Bullet.h"
#include "LaserBeam.h"

constexpr float ONE_TICK()
{
	return 0.016f;
}

namespace PlayerWeapon {

	//----------------------총알----------------------
	PlayerWeapon::BulletLvel_1::BulletLvel_1()
		: WeaponStruct(Cast<UClass>(StaticLoadClass(ABullet::StaticClass(), NULL,
			TEXT("Class'/Game/Blueprint/BP_Bullet.BP_Bullet_C'")))
			, 1, 1.0f, 10.0f, FVector(1.0f, 1.0f, 1.0f),3.0f) {}

	BulletLvel_1::~BulletLvel_1() {}
	
	WeaponStruct* BulletLvel_1::GetUpgradeWeapon()
	{
		return new BulletLvel_2;
	}

	void BulletLvel_1::PressedShoot(AActor* Gunner)
	{
		if (Gunner->GetWorldTimerManager().IsTimerActive(m_weapon_timer))
		{
			return;
		}
		Gunner->GetWorldTimerManager().SetTimer(m_weapon_timer, m_load_time, false);

		CreateWeapon(Gunner);
	}

	void BulletLvel_1::ReleaseShoot(AActor* Gunner)
	{
	}

	void BulletLvel_1::CreateWeapon(AActor* Gunner)
	{
		UE_LOG(LogTemp, Log, TEXT("Create BulletLvel_1"));

		//AActor를 생성한다.
		AActor* Weapon = CheckCreateActor(m_weapon_class, Gunner);

		Weapon->SetActorScale3D(m_scale);
		Weapon->SetLifeSpan(float(m_lifespan_tick));

		//레벨마다 다른 공격력을 AActor에 조절한다.
		IFuselageBaseData* WeaponBaseData = Cast<IFuselageBaseData>(Weapon);
		checkf(WeaponBaseData != nullptr, TEXT("WeaponBaseData is nullptr"));

		WeaponBaseData->GetBaseData()->SetAttackPower(m_power);
	}
	
	BulletLvel_2::BulletLvel_2()
		: WeaponStruct(Cast<UClass>(StaticLoadClass(ABullet::StaticClass(), NULL,
			TEXT("Class'/Game/Blueprint/BP_Bullet.BP_Bullet_C'")))
			, 1, 2.0f, 10.0f, FVector(1.0f, 1.0f, 1.0f), 2.0f), m_bullet_number(3) {}

	BulletLvel_2::~BulletLvel_2() {}

	void BulletLvel_2::PressedShoot(AActor* Gunner)
	{
		if (Gunner->GetWorldTimerManager().IsTimerActive(m_weapon_timer))
		{
			return;
		}
		Gunner->GetWorldTimerManager().SetTimer(m_weapon_timer, m_load_time, false);

		CreateWeapon(Gunner);
	}

	void BulletLvel_2::ReleaseShoot(AActor* Gunner)
	{
	}

	WeaponStruct* BulletLvel_2::GetUpgradeWeapon()
	{
		return this;
	}
	
	void BulletLvel_2::CreateWeapon(AActor* Gunner)
	{
		UE_LOG(LogTemp, Log, TEXT("Create BulletLvel_2"));

		int32 MultiplicationLocation = (m_bullet_number - 1) * 0.5;

		//AActor를 생성한다.
		AActor* Weapon = CheckCreateActor(m_weapon_class, Gunner);

		Weapon->SetActorLocation(Weapon->GetActorLocation() + FVector(0.0f, 50.0f * -MultiplicationLocation, 0.0f));
		Weapon->SetActorScale3D(m_scale);
		Weapon->SetLifeSpan(float(m_lifespan_tick));

		//레벨마다 다른 공격력을 AActor에 조절한다.
		IFuselageBaseData* WeaponBaseData = Cast<IFuselageBaseData>(Weapon);
		checkf(WeaponBaseData != nullptr, TEXT("WeaponBaseData is nullptr"));

		WeaponBaseData->GetBaseData()->SetAttackPower(m_power);

		UWorld* WeaponWorld = Weapon->GetWorld();
		UClass* WeaponClass = Weapon->StaticClass();

		//총알을 하나 생성했으니 나머지 총알만큼 생성한다.
		for (int32 i = 1; i < m_bullet_number; i++)
		{
			AActor* Bullet = CheckCreateActor(m_weapon_class, Gunner);
			Bullet->SetActorLocation(Bullet->GetActorLocation() + FVector(0.0f, 50.0f * (i - MultiplicationLocation), 0.0f));

			Bullet->SetActorScale3D(m_scale);
			Bullet->SetLifeSpan(m_lifespan_tick);

			//레벨마다 다른 공격력을 AActor에 조절한다.
			WeaponBaseData = Cast<IFuselageBaseData>(Bullet);
			checkf(WeaponBaseData != nullptr, TEXT("WeaponBaseData is nullptr"));

			WeaponBaseData->GetBaseData()->SetAttackPower(m_power);
		}

	}


	//----------------------레이저 빔----------------------

	LaserBeamLvel_1::LaserBeamLvel_1()
		: WeaponStruct(Cast<UClass>(StaticLoadClass(ALaserBeam::StaticClass(), NULL,
			TEXT("Class'/Game/Blueprint/BP_LaserBeam.BP_LaserBeam_C'")))
			, 1, 0.1f, 0.0f, FVector(1.0f, 1.0f, 1.0f),5.5f), m_lifespan_tick_limit(90){}

	LaserBeamLvel_1::~LaserBeamLvel_1() {}

	WeaponStruct* LaserBeamLvel_1::GetUpgradeWeapon()
	{
		return new LaserBeamLvel_2;
	}

	void LaserBeamLvel_1::PressedShoot(AActor* Gunner)
	{
		if (Gunner->GetWorldTimerManager().IsTimerActive(m_weapon_timer))
		{
			return;
		}
		
		if (++m_lifespan_tick > m_lifespan_tick_limit)
		{
			m_lifespan_tick = m_lifespan_tick_limit;
		}
	}

	void LaserBeamLvel_1::ReleaseShoot(AActor* Gunner)
	{
		if (Gunner->GetWorldTimerManager().IsTimerActive(m_weapon_timer))
		{
			return;
		}
		Gunner->GetWorldTimerManager().SetTimer(m_weapon_timer, m_load_time, false);

		if (float(m_lifespan_tick) * ONE_TICK() > 1.0f)
		{
			CreateWeapon(Gunner);
		}
		m_lifespan_tick = 0;
	}

	void LaserBeamLvel_1::CreateWeapon(AActor* Gunner)
	{
		UE_LOG(LogTemp, Log, TEXT("Create LaserBeamLvel_1"));

		//AActor를 생성한다.
		AActor* Weapon = CheckCreateActor(m_weapon_class, Gunner);

		Weapon->SetActorScale3D(m_scale);
		Weapon->SetLifeSpan(float(m_lifespan_tick) * ONE_TICK());

		IFuselageBaseData* WeaponBaseData = Cast<IFuselageBaseData>(Weapon);

		//레벨마다 다른 공격력을 AActor에 조절한다.
		WeaponBaseData->GetBaseData()->SetAttackPower(m_power);
		Weapon->AttachToActor(Gunner, FAttachmentTransformRules(EAttachmentRule::KeepWorld, true), TEXT("LaserBeam Attach"));
	}


	LaserBeamLvel_2::LaserBeamLvel_2()
		: WeaponStruct(Cast<UClass>(StaticLoadClass(ALaserBeam::StaticClass(), NULL,
			TEXT("Class'/Game/Blueprint/BP_LaserBeam.BP_LaserBeam_C'")))
			, 2, 0.2f, 0.0f, FVector(2.0f, 2.0f, 1.0f), 5.5f), m_lifespan_tick_limit(180) {}

	LaserBeamLvel_2::~LaserBeamLvel_2() {}

	WeaponStruct* LaserBeamLvel_2::GetUpgradeWeapon()
	{
		return this;
	}

	void LaserBeamLvel_2::PressedShoot(AActor* Gunner)
	{
		if (Gunner->GetWorldTimerManager().IsTimerActive(m_weapon_timer))
		{
			return;
		}
		
		if (++m_lifespan_tick > m_lifespan_tick_limit)
		{
			m_lifespan_tick = m_lifespan_tick_limit;
		}
	}

	void LaserBeamLvel_2::ReleaseShoot(AActor* Gunner)
	{
		if (Gunner->GetWorldTimerManager().IsTimerActive(m_weapon_timer))
		{
			return;
		}
		Gunner->GetWorldTimerManager().SetTimer(m_weapon_timer, m_load_time, false);
		if (float(m_lifespan_tick) * ONE_TICK() > 1.0f)
		{
			CreateWeapon(Gunner);
		}
		m_lifespan_tick = 0;
	}

	void LaserBeamLvel_2::CreateWeapon(AActor* Gunner)
	{
		UE_LOG(LogTemp, Log, TEXT("Create LaserBeamLvel_2"));

		//AActor를 생성한다.
		AActor* Weapon = CheckCreateActor(m_weapon_class, Gunner);

		Weapon->SetActorScale3D(m_scale);
		Weapon->SetLifeSpan(float(m_lifespan_tick) * ONE_TICK());

		IFuselageBaseData* WeaponBaseData = Cast<IFuselageBaseData>(Weapon);

		//레벨마다 다른 공격력을 AActor에 조절한다.
		WeaponBaseData->GetBaseData()->SetAttackPower(m_power);
		Weapon->AttachToActor(Gunner, FAttachmentTransformRules(EAttachmentRule::KeepWorld, true), TEXT("LaserBeam Attach"));
	}

}