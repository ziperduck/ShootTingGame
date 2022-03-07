// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageStatus.h"

/**
 * �ϳ��� Ŀ�ٶ� ������ ����� �����
 * �𸮾��� �߻�Ŭ������ ����ؼ� �� �����͸� �����ϰ� ����� �װ��� ���ؼ� attack�� �Ѵ�.
 * 
 * �ʿ��� ������
 * 
 * ����
 * ��ü ���ݷ�, ü��, ���ǵ�
 * �浹�� ��ü, �ڽ� �Ҽ�
 * �̵� �̺�Ʈ, ���� �̺�Ʈ, �ٷ��̵� �̺�Ʈ 
 * ���� �̺�Ʈ, ������ ������, ü��ȸ���ϱ�, ���� (�ٲٱ�, ���׷��̵�)
 * Actor�� �ް� �̺�Ʈ�� ĳ������ �����Ѱ�?
 * player�� ĳ������ �ؼ� ����غ���
 * 
 * ���� �̺�Ʈ, �� ������, �׳� ���
 * ������ �̺�Ʈ, ������ ����Ʈ����, ����, 
 * 
 * ���� ������ ����ؼ� �������� ���׸� ���� ������ ���ϰ� ����ų� ����
 * 
 * 
 * �÷��̾�����
 * ��ź����, ���ھ�
 * 
 * ���������� ����Ѵٸ� Ű���带 ��� �޾Ƽ� �������� ������ ��� �����Ұ��ΰ�?
 * 
 * �ൿ���� ������ �����ϸ� ���ִ� ������ ���� set que�� �̿��ؼ�
 * 
 * �浹�� �ൿ�� �߰��ϸ� ������ �̵��� �̺�Ʈ �߰��� ��� ������ �����غ���
 * 
 * ������Ʈ������ ����ؼ� ���� �׾����� ��Ҵ��� Ȯ���Ѵ�.
 * 
 * ����, �⺻����, ��������, �ε��� ����
 * 
 * �÷��̾��� ���¹� �ൿ���� �Ҽ��ְ� �ϴ� Ŭ���� �ϳ��� �������� 
 * 
 * 
 */


 /*
 * � ��ü�� �浹���� �ڽ��� ��� �Ҽ������� ��Ÿ���� Struct
 */
class WeaponStruct;

struct FuselageUnion
{
public:

	FuselageUnion(const int8 Union, const int8 Collision);

	~FuselageUnion();

	const int8 GetUnion() const;

	const int8 GetCollision() const;

private:

	FuselageUnion() = delete;

private:

	const int8 m_union;

	const int8 m_collision;

};

/*
* ��ü���� �ɷ�ġ�� �⵹ ó�� ������ �������ִ� ������
*/
class FuselageData
{
public:

	FuselageData(WeaponStruct* Weapon,FuselageStatus& Status, const FuselageUnion& Union);
	~FuselageData() {};
		
	//�ִ�ü���� ���� ������ŭ�� ü���� ȸ���Ѵ�.
	void AddHP(float Num);

	//���⸦ ��ü�Ѵ�
	void ChangeWeapon(WeaponStruct* Weapon);

	//��ü�� ���ݷ��� �����Ѵ�.
	void SetAttackPower(const float Power);


	//���� ü���� �޴´�.
	const float GetCurrentHP() const;

	//���� ���⸦ �޴´�.
	WeaponStruct* GetWeapon() const;

	//���� �ɷ�ġ�� �޴´�.
	const FuselageStatus& GetStatus() const;

	//���� (�浹����)�Ҽ��� �޴´�.
	const FuselageUnion& GetUnion()const;


private:

	FuselageData() = delete;

private:

	float m_current_hp;

	WeaponStruct* m_weapon;

	FuselageStatus& m_fix_status;

	const FuselageUnion& m_union;

};
