// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageData.h"
#include "WeaponStruct.h"

#include "specialEvent.h"

#include <memory>

/**
* character���� ������ ���� �� Ŭ�����ȿ����� ����� �ϴ� ������ ���� �ϰ� ������
 * stauts�� union�� weaponstatus�� �������� ���� ����
 */
class FuselageCharacter
{
public:
	FuselageCharacter(AActor* Actor, std::shared_ptr<FuselageData> BaseData);
	FuselageCharacter(const FuselageCharacter& Reference);
	~FuselageCharacter(){};

	//�̵��� ������ �޴´�. Z���� �̵��ϰų� �������� ������� false�� �����Ѵ�.
	void MoveTo(FVector Direction);

	//�ִ�ü���� ���� �ʰ� ���ڰ� ��ŭ ü���� ȸ���Ѵ�.
	void AddHP(float HP);

	//���� ��� �Լ�
	void Shooting();

	//�״� �Լ�
	void Death();

	//���⸦ ��ü�Ѵ�.
	void SetWeapon(std::shared_ptr<WeaponStruct> ChangeWeapon);


	void SetDeathEvent(std::vector<std::shared_ptr<SpecialEvent>> DeathEvents);

	void AddDeathEvent(std::shared_ptr<SpecialEvent> DeathEvent);

	const AActor* GetActor() const;

	const int32 GetCurrentHP() const;

	const float GetSpeed() const;

	const int32 GetAttackPower() const;

	const int8 GetUnion() const;

	const int8 GetCollision() const;

private:

	FuselageCharacter() = delete;


protected:

	AActor* m_actor;

	//��ü�� �⺻ ������
	std::shared_ptr<FuselageData> m_base_data;

	//������� ȣ��Ǵ� �̺�Ʈ
	std::vector<std::shared_ptr<SpecialEvent>> m_death_events;
};
