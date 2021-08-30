// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <memory>
#include <cassert>
#include "CoreMinimal.h"
/**
 * 
 */
class IObject;

/*
* 게임내에 있는 모든 Object를 가지고있는 클래스다
*/
class ObjectManager
{
public:
	~ObjectManager();

	static ObjectManager* GetInstance();

	//오브젝트 추가
	void AddObject(std::shared_ptr<IObject>);

	void AddObjects(std::vector<std::shared_ptr<IObject>>);

	//맵에에있는 모든 오브젝트 업데이트
	void ObjectsUpdate();
private:

	ObjectManager() {};

private:

	std::vector<std::shared_ptr<IObject>> m_lived_objects;

};