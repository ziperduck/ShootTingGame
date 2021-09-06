// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <memory>
#include <cassert>
#include "CoreMinimal.h"
/**
 * 
 */

#define LIVED_OBJECT_SIZE 10

class IObject;
class IAction;
enum class ObjectKind;

//IObject를 랩핑하여 AddAction만 실행할수있게 만든 클래스
 class WrappingObject
 {
 public:
	 WrappingObject(std::weak_ptr<IObject>,const uint16&);
	 ~WrappingObject();

	 void AddAction(std::shared_ptr<IAction>);

	 void AddAnimation(std::queue<std::queue<std::shared_ptr<IAction>>>);

	 const uint16 GetAddress() const;

 private:

	 WrappingObject() =delete;
	 WrappingObject(const WrappingObject&) = delete;
	 WrappingObject& operator=(const WrappingObject&) = delete;

 private:

	 std::weak_ptr<IObject> m_wrap_object;

	 const uint16 m_address;
 };


/*
* 게임내에 있는 모든 Object를 가지고있는 클래스다
*/

class ObjectManager
{
public:
	~ObjectManager();

	static ObjectManager* GetInstance();

	//오브젝트 생성을 요청한다. 오브젝트의 종류와 월드 정보 그리고 위치를 데이터로 받는다. 
	//그리고 유일하게 Object아이디를 생성하여 리턴한다.
	std::unique_ptr<WrappingObject> CreateObject(const ObjectKind, UWorld*,const FVector);

	//맵에에있는 모든 오브젝트 업데이트
	void ObjectsUpdate();

	//Id에 해당하는 Object를 제거한다.
	void DeleteObject(std::unique_ptr<WrappingObject>);
private:

	ObjectManager();
	ObjectManager(const ObjectManager&) = delete;
	ObjectManager& operator=(const ObjectManager&) = delete;

	//현재 비어있는 원소위치를 반환한다. 한칸이 더 비어있다.
	int16 GetBinArraySpace();

private:

	std::shared_ptr<IObject> m_lived_objects[LIVED_OBJECT_SIZE];

	//배열의 마지막을 원소위치
	uint16  m_tail_num;

};
