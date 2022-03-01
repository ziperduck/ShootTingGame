// Fill out your copyright notice in the Description page of Project Settings.


#include "TestPlayerWeapon.h"

#include "TestBullet.h"
#include "TestLaserBeam.h"

//�����ϴ� ��ü�� �����ϴ��� Ŭ������ �°� �����ƴ��� Ȯ���Ѵ�.
AActor* CheckCreateActor(UClass* ActorClass,AActor* CheckActor);

namespace PlayerWeapon {

	//----------------------�Ѿ�----------------------

	PlayerWeapon::BulletLvel_1::BulletLvel_1()
	 : WeaponStruct(Cast<UClass>(StaticLoadClass(ATestBullet::StaticClass(), NULL,
		 TEXT("Class'/Game/Blueprint/BP_TestBullet.BP_TestBullet_C'")))
		 ,1,1.0f,10.0f,FVector(1.0f,1.0f,1.0f)){}

	BulletLvel_1::~BulletLvel_1(){}

	void BulletLvel_1::CreateWeapon(AActor* Gunner)
	{
		UE_LOG(LogTemp, Log, TEXT("Create BulletLvel_1"));

		//AActor�� �����Ѵ�.
		AActor* Weapon = CheckCreateActor(m_weapon_class,Gunner);

		Weapon->SetActorScale3D(m_scale);
		Weapon->SetLifeSpan(m_lifespan);

		//�������� �ٸ� ���ݷ��� AActor�� �����Ѵ�.
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

		//AActor�� �����Ѵ�.
		AActor* Weapon = CheckCreateActor(m_weapon_class, Gunner);

		Weapon->SetActorScale3D(m_scale);
		Weapon->SetLifeSpan(m_lifespan);

		//�������� �ٸ� ���ݷ��� AActor�� �����Ѵ�.
		IFuselageBaseData* WeaponBaseData = Cast<IFuselageBaseData>(Weapon);
		checkf(WeaponBaseData != nullptr, TEXT("WeaponBaseData is nullptr"));

		WeaponBaseData->GetBaseData()->SetAttackPower(m_power);

		//�Ѿ��� �ϳ� ���������� ������ �Ѿ˸�ŭ �����Ѵ�.
		for (int32 i = 1; i < m_bullet_number; i++)
		{

		}

	}

	//----------------------������ ��----------------------

	LaserBeamLvel_1::LaserBeamLvel_1()
		: WeaponStruct(Cast<UClass>(StaticLoadClass(ATestBullet::StaticClass(), NULL,
			TEXT("Class'/Game/Blueprint/BP_TestBullet.BP_TestBullet_C'")))
			, 1, 0.1f, 0.0f, FVector(1.0f, 1.0f, 1.0f)) {}
	
	LaserBeamLvel_1::~LaserBeamLvel_1(){}

	void LaserBeamLvel_1::CreateWeapon(AActor* Gunner)
	{
		UE_LOG(LogTemp, Log, TEXT("Create LaserBeamLvel_1"));

		//AActor�� �����Ѵ�.
		AActor* Weapon = CheckCreateActor(m_weapon_class, Gunner);

		Weapon->SetActorScale3D(m_scale);
		Weapon->SetLifeSpan(m_lifespan);

		IFuselageBaseData* WeaponBaseData = Cast<IFuselageBaseData>(Weapon);

		//�������� �ٸ� ���ݷ��� AActor�� �����Ѵ�.
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