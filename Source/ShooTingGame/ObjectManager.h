// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <memory>
#include <cassert>
#include "CoreMinimal.h"
/**
 * 
 */

#define MANAGER_SIZE 10

class IObject;
class ObjectManager;
class IAction;
enum class ObjectKind;

//ObjectManager의 Object들의 뱌열 위치를 가지고있는 클래스다.
//이 Id값이 있어야지만 Actino값을 추가할수있다.
class ObjectId {
public:
	ObjectId(const int Element, const int Identity)
		:m_arr_element(Element), m_identity_num(Identity) {};

	const int GetElement() const;

private:
	ObjectId(const ObjectId&) = delete;
	ObjectId& operator=(const ObjectId&) = delete;


	friend bool operator==(const ObjectId&, const ObjectId&);

private:
	const int m_arr_element;
	const int m_identity_num;

};

 bool operator==(const ObjectId&, const ObjectId&);

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
private:

	ObjectManager() : m_tail_num(0){
		UE_LOG(LogTemp, Log, TEXT("ObjectManager Constructor"));
	};
private:

	std::shared_ptr<IObject> m_lived_objects[MANAGER_SIZE];

	//배열의 마지막을 원소위치
	int32 m_tail_num;

};

const int32 CirculatorElerment(const int32 num);