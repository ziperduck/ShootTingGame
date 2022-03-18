// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "WeaponState.h"

/**
* ������ ������
 */
class WeaponStruct {
public:

	WeaponStruct(UClass* WeaponClass, IWeaponState* WeaponState
		,const int32 WeaponLevel, const float Power, const float LifeSpan, const FVector Scale);
	virtual ~WeaponStruct() =0 {};
	
	//������ �����͸� ���� Actor�� �����Ѵ�.
	virtual void CreateWeapon(AActor* Gunner) = 0;

	//�����ֱ⸦ �����Ѵ�.
	void SetLifeSpan(const float LifeSpan);

	//���� ������ ��ȭ�� ���⸦ ��ȯ�մϴ�. ������� �ڱ� �ڽ��� �����մϴ�.
	virtual WeaponStruct* GetUpgradeWeapon() = 0;


	//������¿� input�� �ް� �˸´� �����ൿ�� �����ϴ� �Լ�
	void HandleInput(std::shared_ptr<FuselageCharacter> Character, EInputBehavior Input);

	//������¿� �Էµ� �̺�Ʈ�� �����ϰ� ���¿� �´� Ư�� �ൿ�� �ϴ� �Լ�
	void Update(std::shared_ptr<FuselageCharacter> Character);

	//ũ�⸦ �޴´�.
	const int32 GetWeaponLevel()const;

	//���ݷ��� �޴´�.
	const float GetPower()const;

	//�����ֱ⸦ �޴´�.
	const float GetLifeSpan()const;

	//ũ�⸦ �޴´�.
	const FVector GetScale()const;

	//������ UClass�� �޴´�.
	const UClass* GetUClass() const;

private:

	WeaponStruct() = delete;

protected:

	UClass* m_weapon_class;

	const int32 m_level;

	const float m_power;

	float m_lifespan;

	const FVector m_scale;

	IWeaponState* m_weapon_state;
};


//�����ϴ� ��ü�� �����ϴ��� Ŭ������ �°� �����ƴ��� Ȯ���Ѵ�.
AActor* CheckCreateActor(UClass* ActorClass, AActor* CheckActor);