// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * ����Ű �̵��� �׳� ����Ű ���� �����ͷ� �޾Ƽ� ���� �����ϸ� �ȴ�.
 */
class FuselageMove
{
public:
	FuselageMove(){};
	virtual ~FuselageMove() = 0 {};

	virtual bool Move() = 0;


};
