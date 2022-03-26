// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
* ������ ������
 */
class WeaponStruct {
public:

	WeaponStruct(
		UClass* WeaponClass,const int32 WeaponLevel, const float Power, const float LifeSpan, const FVector Scale, const float LoadTime);
	virtual ~WeaponStruct() =0 {};
	

	virtual void PressedShoot(AActor* Gunner) = 0;

	virtual void ReleaseShoot(AActor* Gunner) = 0;

	//���� ������ ��ȭ�� ���⸦ ��ȯ�մϴ�. ������� �ڱ� �ڽ��� �����մϴ�.
	virtual WeaponStruct* GetUpgradeWeapon() = 0;


	//ũ�⸦ �޴´�.
	const int32 GetWeaponLevel()const;

	//���ݷ��� �޴´�.
	const float GetPower()const;

	//�����ֱ⸦ �޴´�.
	const int32 GetLifeSpanSecond()const;

	//ũ�⸦ �޴´�.
	const FVector GetScale()const;

	//������ UClass�� �޴´�.
	const UClass* GetUClass() const;

protected:

	//������ �����͸� ���� Actor�� �����Ѵ�.
	virtual void CreateWeapon(AActor* Gunner) = 0;

private:

	WeaponStruct() = delete;

protected:

	//������ ���� Ŭ����
	UClass* m_weapon_class;

	const int32 m_level;

	const float m_power;

	int32 m_lifespan_tick;

	const FVector m_scale;

	//������ �ð�
	const float m_load_time;

	//������ �ð����� ȣ���� ���ϰ� �����.
	FTimerHandle m_weapon_timer;

};


//�����ϴ� ��ü�� �����ϴ��� Ŭ������ �°� �����ƴ��� Ȯ���Ѵ�.
AActor* CheckCreateActor(UClass* ActorClass, AActor* CheckActor);