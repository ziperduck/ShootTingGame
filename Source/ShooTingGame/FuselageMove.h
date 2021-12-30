// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 방향키 이동은 그냥 방향키 값을 포인터로 받아서 서로 공유하면 된다.
 */
class FuselageMove
{
public:
	FuselageMove(){};
	virtual ~FuselageMove() = 0 {};

	virtual bool Move() = 0;


};
