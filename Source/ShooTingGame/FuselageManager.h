// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <memory>
#include "CoreMinimal.h"
/**
 * 
 */

#define LIVED_OBJECT_SIZE 10

class IFuselage;

class IAction;
enum class FuselageKind;

//IFuselage를 랩핑하여 AddAction만 실행할수있게 만든 클래스
 class WrappingFuselage
 {
 public:
	 WrappingFuselage(IFuselage*,const uint16&);
	 ~WrappingFuselage();

	 void AddAction(std::shared_ptr<IAction>);

	 const uint16 GetAddress() const;

 private:

	 WrappingFuselage() =delete;
	 WrappingFuselage(const WrappingFuselage&) = delete;
	 WrappingFuselage& operator=(const WrappingFuselage&) = delete;

 private:

	 IFuselage* m_wrap_fuselage;

	 const uint16 m_address;
 };


/*
* 게임내에 있는 모든 Object를 가지고있는 클래스다
*/

class FuselageManager
{
public:
	~FuselageManager();

	static FuselageManager* GetInstance();


	//오브젝트 생성을 요청한다. 오브젝트의 종류와 월드 정보 그리고 위치를 데이터로 받는다. 
	//그리고 유일하게 Object아이디를 생성하여 리턴한다.
	std::unique_ptr<WrappingFuselage> AddFuselage(const FuselageKind, const FVector);

	//오버로딩
	std::unique_ptr<WrappingFuselage> AddFuselage(TSharedPtr<IFuselage>, const FVector);

	//맵에에있는 모든 오브젝트 업데이트
	void ObjectsUpdate();

	//Id에 해당하는 Object를 제거한다.
	void DeleteObject(std::unique_ptr<WrappingFuselage>);
private:

	FuselageManager();
	FuselageManager(const FuselageManager&) = delete;
	FuselageManager& operator=(const FuselageManager&) = delete;

	//현재 비어있는 원소위치를 반환한다. 한칸이 더 비어있다.
	int16 GetBinArraySpace();

private:

	IFuselage* m_lived_fuselage[LIVED_OBJECT_SIZE];

	//배열의 마지막을 원소위치
	uint16  m_tail_num;

};


