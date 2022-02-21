// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuselageStatus.h"
#include "WeaponStruct.h"

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

	FuselageData(const FuselageStatus& Status, const FuselageUnion& Union);
	~FuselageData() {};

	//�ִ�ü���� ���� ������ŭ�� ü���� ȸ���Ѵ�.
	void AddHP(int32 Num);

	const int32 GetCurrentHP() const;

	const FuselageStatus& GetStatus() const;

	const FuselageUnion& GetUnion()const;


private:

	FuselageData() = delete;

private:

	int32 m_current_hp;

	WeaponStruct m_weapon;

	const FuselageStatus& m_fix_status;

	const FuselageUnion& m_union;

};

