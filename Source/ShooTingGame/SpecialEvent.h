// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <memory>

class FuselageCharacter;
/**
 * Fusealge Character���� �̺�Ʈ�� �����ϱ� ���� �����Ű�� Ư���� �̺�Ʈ 
 */
class SpecialEvent {
public:
	
	SpecialEvent() {};
	virtual ~SpecialEvent() =0 {};
	
	//�ڽ��� ���� �ڽ��� ȣ���ϱ⶧���� shared_ptr�� �ƴ� �׳� ������ ���� �޴´�.
	virtual void EventPlay(FuselageCharacter* Character) = 0;

};
