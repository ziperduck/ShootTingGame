// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MoveEvent.h"
#include <Engine/Classes/Components/SceneComponent.h>
#include "CoreMinimal.h"
#include "EnumPack.h"
#include <array>


/**
 * ������ ��ġ�� ����ϴ°Ͱ� ������ ��ġ �����͸� ���� �η��� ������ MoveEvent���� �̱���ȭ �ؾ��ؼ� �׳� ���Ĺ��ȴ�. 
 */
class DirectMove : public MoveEvent
{
public:

	//������ ��ü�� ��ġ�� �̵��ӵ� �׸��� ������ ��ġ���� �޴´�.
	DirectMove(const FuselageStatus& Speed);
	virtual ~DirectMove() final;

	//���߿��� ���ø��� �̿��ؼ� compile�������� ��������

	void LeftPresses();

	void RightPresses();

	void ForwardPresses();

	void BackwardPresses();


	void LeftRelease();

	void RightRelease();

	void ForwardRelease();

	void BackwardRelease();

	void Resetkey();

	virtual bool Move(AActor* Actor) final;

};
