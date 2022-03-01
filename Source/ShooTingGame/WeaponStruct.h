// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
* ������ ������
 */
class WeaponStruct {
public:

	WeaponStruct(UClass* WeaponClass,const int32 WeaponLevel, const float Power, const float LifeSpan, const FVector Scale);
	virtual ~WeaponStruct() =0 {};
	
	//������ �����͸� ���� Actor�� �����Ѵ�.
	virtual void CreateWeapon(AActor* Gunner) = 0;

	//�����ֱ⸦ �����Ѵ�.
	void SetLifeSpan(const float LifeSpan);


	//ũ�⸦ �޴´�.
	const int32 GetWeaponLevel()const;

	//���ݷ��� �޴´�.
	const float GetPower()const;

	//�����ֱ⸦ �޴´�.
	const float GetLifeSpan()const;

	//ũ�⸦ �޴´�.
	const FVector GetScale()const;

private:

	WeaponStruct() = delete;

protected:

	UClass* m_weapon_class;

	const int32 m_level;

	const float m_power;

	float m_lifespan;

	const FVector m_scale;
};
