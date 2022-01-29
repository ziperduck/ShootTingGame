// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FuselageMove.h"
#include <Engine/Classes/Components/SceneComponent.h>
#include "CoreMinimal.h"
#include "EnumPack.h"
#include <array>


/**
 * ������ ��ġ�� ����ϴ°Ͱ� ������ ��ġ �����͸� ���� �η��� ������ FuselageMove���� �̱���ȭ �ؾ��ؼ� �׳� ���Ĺ��ȴ�. 
 */
class DirectMove : public FuselageMove
{
public:

	//������ ��ü�� ��ġ�� �̵��ӵ� �׸��� ������ ��ġ���� �޴´�.
	DirectMove();
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

	virtual const FVector& GetDirections()const final;

private:

	DirectMove(DirectMove&) = delete;
	const DirectMove& operator=(const DirectMove&) = delete;

};
