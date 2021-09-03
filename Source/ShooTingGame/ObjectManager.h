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
class ObjectManager;
class IAction;
enum class ObjectKind;

//ObjectManager의 Object들의 뱌열 위치를 가지고있는 클래스다.
//이 Id값이 있어야지만 Actino값을 추가할수있다.
class ObjectId {
public:
	ObjectId(const uint16 Element, const uint16 Identity)
		:m_arr_element(Element), m_identity_num(Identity) {};

	const uint16 GetElement() const;

private:
	ObjectId(const ObjectId&) = delete;
	ObjectId& operator=(const ObjectId&) = delete;


	friend bool operator!=(const ObjectId&, const ObjectId&);

private:
	const uint16 m_arr_element;
	const uint16 m_identity_num;

};

 bool operator==(const ObjectId&, const ObjectId&);
 bool operator!=(const ObjectId&, const ObjectId&);

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
	std::unique_ptr<ObjectId> CreateObject(ObjectKind, UWorld*,FVector);

	//ObjectId값을 주어야한 해당 Object에 Action값을 전달할수있다.
	//리턴값으론 해당 인자값으로 받은 ObjectId값을 다시 리턴한다.
	std::unique_ptr<ObjectId>  AddAction(std::unique_ptr<ObjectId>, std::shared_ptr<IAction>);

	//맵에에있는 모든 오브젝트 업데이트
	void ObjectsUpdate();

	//Id에 해당하는 Object를 제거한다.
	void DeleteObject(std::unique_ptr<ObjectId>);
private:

	ObjectManager();

	//현재 비어있는 원소위치를 반환한다. 한칸이 더 비어있다.
	int16 GetBinArraySpace();

private:

	std::unique_ptr<IObject> m_lived_objects[LIVED_OBJECT_SIZE];

	//배열의 마지막을 원소위치
	uint16  m_tail_num;

};

const uint16 CirculatorElerment(const uint16 num);