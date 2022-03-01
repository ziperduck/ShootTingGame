// Fill out your copyright notice in the Description page of Project Settings.


#include "TestPlayerWeapon.h"

#include "TestBullet.h"
#include "TestLaserBeam.h"

//생성하는 주체가 존재하는지 클래스는 맞게 생성됐는지 확인한다.
AActor* CheckCreateActor(UClass* ActorClass,AActor* CheckActor);

namespace PlayerWeapon {

	//----------------------총알----------------------

	PlayerWeapon::BulletLvel_1::BulletLvel_1()
	 : WeaponStruct(Cast<UClass>(StaticLoadClass(ATestBullet::StaticClass(), NULL,
		 TEXT("Class'/Game/Blueprint/BP_TestBullet.BP_TestBullet_C'")))
		 ,1,1.0f,10.0f,FVector(1.0f,1.0f,1.0f)){}

	BulletLvel_1::~BulletLvel_1(){}

	void BulletLvel_1::CreateWeapon(AActor* Gunner)
	{
		UE_LOG(LogTemp, Log, TEXT("Create BulletLvel_1"));

		//AActor를 생성한다.
		AActor* Weapon = CheckCreateActor(m_weapon_class,Gunner);

		Weapon->SetActorScale3D(m_scale);
		Weapon->SetLifeSpan(m_lifespan);

		//레벨마다 다른 공격력을 AActor에 조절한다.
		IFuselageBaseData* WeaponBaseData = Cast<IFuselageBaseData>(Weapon);
		checkf(WeaponBaseData != nullptr, TEXT("WeaponBaseData is nullptr"));

		WeaponBaseData->GetBaseData()->SetAttackPower(m_power);
	}
	BulletLvel_2::BulletLvel_2()
		: WeaponStruct(Cast<UClass>(StaticLoadClass(ATestBullet::StaticClass(), NULL,
			TEXT("Class'/Game/Blueprint/BP_TestBullet.BP_TestBullet_C'")))
			, 1, 2.0f, 10.0f, FVector(1.0f, 1.0f, 1.0f)), m_bullet_number(3){}

	BulletLvel_2::~BulletLvel_2(){}

	void BulletLvel_2::CreateWeapon(AActor* Gunner)
	{
		UE_LOG(LogTemp, Log, TEXT("Create BulletLvel_2"));

		//AActor를 생성한다.
		AActor* Weapon = CheckCreateActor(m_weapon_class, Gunner);

		Weapon->SetActorScale3D(m_scale);
		Weapon->SetLifeSpan(m_lifespan);

		//레벨마다 다른 공격력을 AActor에 조절한다.
		IFuselageBaseData* WeaponBaseData = Cast<IFuselageBaseData>(Weapon);
		checkf(WeaponBaseData != nullptr, TEXT("WeaponBaseData is nullptr"));

		WeaponBaseData->GetBaseData()->SetAttackPower(m_power);

		//총알을 하나 생성했으니 나머지 총알만큼 생성한다.
		for (int32 i = 1; i < m_bullet_number; i++)
		{

		}

	}

	//----------------------레이저 빔----------------------

	LaserBeamLvel_1::LaserBeamLvel_1()
		: WeaponStruct(Cast<UClass>(StaticLoadClass(ATestBullet::StaticClass(), NULL,
			TEXT("Class'/Game/Blueprint/BP_TestBullet.BP_TestBullet_C'")))
			, 1, 0.1f, 0.0f, FVector(1.0f, 1.0f, 1.0f)) {}
	
	LaserBeamLvel_1::~LaserBeamLvel_1(){}

	void LaserBeamLvel_1::CreateWeapon(AActor* Gunner)
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
	LaserBeamLvel_2::LaserBeamLvel_2()
		: WeaponStruct(Cast<UClass>(StaticLoadClass(ATestBullet::StaticClass(), NULL,
			TEXT("Class'/Game/Blueprint/BP_TestBullet.BP_TestBullet_C'")))
			, 1, 0.2f, 0.0f, FVector(1.0f, 1.0f, 1.0f)) {}

	LaserBeamLvel_2::~LaserBeamLvel_2(){}

	void LaserBeamLvel_2::CreateWeapon(AActor* Gunner)
	{
	}
}

AActor* CheckCreateActor(UClass* ActorClass, AActor* CheckActor)
{
	checkf(CheckActor != nullptr, TEXT("CreateWeapon Gunner is nullptr "));
	UWorld* CreateWorld = CheckActor->GetWorld();

	checkf(CreateWorld != nullptr, TEXT("CreateWeapon Gunner is nullptr "));
	AActor* Weapon
		= CreateWorld->SpawnActor<AActor>(ActorClass, CheckActor->GetActorLocation(), FRotator::ZeroRotator);

	checkf(Weapon != nullptr, TEXT("CreateWeapon SpawnActor is nullptr "));
	
	return Weapon;
}