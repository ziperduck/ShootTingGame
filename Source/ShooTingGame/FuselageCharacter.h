// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageData.h"

#include "specialEvent.h"

#include <memory>

/**
* character���� ������ ���� �� Ŭ�����ȿ����� ����� �ϴ� ������ ���� �ϰ� ������
 * stauts�� union�� weaponstatus�� �������� ���� ����
 */
  
class WeaponStruct;

//��ü���� ������ ������ ���� Ŭ����
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

	//����Ű�� Ű���崩����
	void PressedShoot();

	//����Ű�� Ű���嶩��
	void ReleaseShoot();

	//�״� �Լ�
	void Death();

	//���⸦ ��ü�Ѵ�.
	void ChangeWeapon(WeaponStruct* ChangeWeapon);

	//�ҼӰ� �浹ü�� ��ü�Ѵ�.
	void ChangeUnion(const FuselageUnion* Union);

	//��ü�� ���ݷ��� �����Ѵ�.
	void SetAttackPower(const float Power);

	//������ ����Ǵ� �̺�Ʈ�� �����Ѵ�.
	void SetDeathEvent(std::vector<std::shared_ptr<SpecialEvent>> DeathEvents);

	//������ ����Ǵ� �̺�Ʈ�� �߰��Ѵ�.
	void AddDeathEvent(std::shared_ptr<SpecialEvent> DeathEvent);


	//��ü�� Actor�� ��ȯ�Ѵ�.
	const AActor* GetActor() const;

	//��ü�� ����ü���� ��ȯ�Ѵ�.
	const float GetCurrentHP() const;

	//��ü�� �̵��ӵ��� ��ȯ�Ѵ�.
	const float GetSpeed() const;

	//��ü�� ���ݷ��� ��ȯ�Ѵ�.
	const float GetAttackPower() const;

	//��ü�� �Ҽ��� ��ȯ�Ѵ�.
	const int8 GetUnion() const;

	//��ü�� �浹�Ҽ��ִ� ��ü�� ��ȯ�Ѵ�.
	const int8 GetCollision() const;

	//��ü�� ���⸦ ��ȯ�Ѵ�.
	WeaponStruct* GetWeapon() const;

private:

	FuselageCharacter() = delete;


protected:

	AActor* m_actor;

	//��ü�� �⺻ ������
	std::shared_ptr<FuselageData> m_base_data;

	//������� ȣ��Ǵ� �̺�Ʈ
	std::vector<std::shared_ptr<SpecialEvent>> m_death_events;
};
