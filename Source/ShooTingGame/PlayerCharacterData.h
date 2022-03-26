// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class PlayerCharacterData
{
public:
	PlayerCharacterData(AActor* PlayerActor,uint32 BoomNum);
	~PlayerCharacterData();

	//������ ���Ѵ�.
	void AddScore(const int32 Score);

	//��ź�� ������ ���δ�.
	void UseSuperBoom();


	//���� �÷��̾��� ���͸� ��ȯ�Ѵ�.
	const AActor* GetPlayerActor() const;

	//���� ���ھ ��ȯ�Ѵ�.
	const uint32 GetScore() const;

	//���� ��ź�� ������ ��ȯ�Ѵ�.
	const uint32 GetSuperBoomNum() const;

private:

	uint32 m_score;

	uint32 m_boom_num;

	AActor* m_player_actor;
};
