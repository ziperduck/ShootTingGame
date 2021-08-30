// Fill out your copyright notice in the Description page of Project Settings.


#include "Character.h"
#include "Object.h"
#include "ObjectManager.h"


ObjectManager::~ObjectManager()
{
}

ObjectManager* ObjectManager::GetInstance()
{
	static ObjectManager* Manager = new ObjectManager();
	return Manager;
}

void ObjectManager::AddObject(std::shared_ptr<IObject> Object) 
{
	m_lived_objects.push_back(Object);
	UE_LOG(LogTemp, Log, TEXT("AddObject"));
}


void ObjectManager::AddObjects(std::vector<std::shared_ptr<IObject>> Objects)
{
	m_lived_objects.insert(m_lived_objects.end(), Objects.begin(),Objects.end());
}


void ObjectManager::ObjectsUpdate()
{
	UE_LOG(LogTemp, Log, TEXT("m_lived_objects size %d"), m_lived_objects.size());
	for (auto i : m_lived_objects)
	{
		if (i.use_count() > 1) {
			i->Update();
			
		}
	}
}
