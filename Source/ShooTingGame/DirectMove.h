// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Engine/Classes/Components/SceneComponent.h>
#include "CoreMinimal.h"
#include "FuselageBehavior.h"
#include "FuselageStatus.h"
#include <array>


/**
 * ������ ��ġ�� ����ϴ°Ͱ� ������ ��ġ �����͸� ���� �η��� ������ MoveEvent���� �̱���ȭ �ؾ��ؼ� �׳� ���Ĺ��ȴ�. 
 */
class DirectMove : public FuselageBehavior
{
public:

	//������ ��ü�� ��ġ�� �̵��ӵ� �׸��� ������ ��ġ���� �޴´�.
	DirectMove(const FuselageStatus& Speed);
	DirectMove(const DirectMove& Temporary);
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

	virtual bool execute(AActor* Actor) final;

private:

	FVector m_directions;

	float m_speed;

};
