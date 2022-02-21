// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <memory>

class FuselageCharacter;
/**
 * Fusealge Character에서 이벤트를 실행하기 전에 실행시키는 특별한 이벤트 
 */
class SpecialEvent {
public:
	
	SpecialEvent() {};
	virtual ~SpecialEvent() =0 {};
	
	//자신이 직접 자신을 호출하기때문에 shared_ptr이 아닌 그냥 포인터 값을 받는다.
	virtual void EventPlay(FuselageCharacter* Character) = 0;

};
