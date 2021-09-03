// Fill out your copyright notice in the Description page of Project Settings.


#include "Character.h"
#include "EnemyCharacter.h"
#include "PlayerCharacter.h"
#include <Engine/World.h>
#include <Engine.h>
#include "ObjectManager.h"

const uint16 ObjectId::GetElement() const {
	return m_arr_element;
}

bool operator!=(const ObjectId& Left, const ObjectId& Right)
{
	return (Left.m_arr_element != Right.m_arr_element) || (Left.m_identity_num != Right.m_identity_num);
}
bool operator==(const ObjectId& Left, const ObjectId& Right) 
{
	return !operator!=(Left,Right);
}

ObjectManager::ObjectManager() : m_lived_objects{ nullptr, }, m_tail_num(0){
	UE_LOG(LogTemp, Log, TEXT("ObjectManager Constructor"));
};

ObjectManager::~ObjectManager()
{
}

ObjectManager* ObjectManager::GetInstance()
{
	static ObjectManager* Manager = new ObjectManager();
	return Manager;
}

std::unique_ptr<ObjectId>  ObjectManager::CreateObject(ObjectKind Kind, UWorld* SpawnWorld,FVector SpawnPoint)
{

	std::unique_ptr<ObjectId> ReturnId = nullptr;
	UE_LOG(LogTemp, Log, TEXT("m_tail_num %d"), m_tail_num);
	//spawn world가 비어있는지 확인
	if (SpawnWorld == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("World is nullptr"));
	}
	else
	{
		//spawn world가 채워져 있을경우 ObjectKind값을 통해 world에 Actor들을 배치한다

		AActor* ObjectActor = nullptr;
		char* ObjectName;
		m_lived_objects[m_tail_num] = nullptr;
		switch (Kind)
		{
		case ObjectKind::PlayerObject:
			ObjectActor = SpawnWorld->SpawnActor<APlayerCharacter>(SpawnPoint, FRotator{ 0.0f,0.0f,0.0f });
			ObjectName = "Player";
			break;
		case ObjectKind::EnemyObject:
			ObjectActor = SpawnWorld->SpawnActor<AEnemyCharacter>(SpawnPoint, FRotator{ 0.0f,0.0f,0.0f });
			ObjectName = "Enemy";
			break;
		default:
			checkNoEntry();
			break;
		}
		checkf(ObjectActor != nullptr, TEXT("CreateObject memeber function in ObjectActor Data is nullptr"));
		m_lived_objects[m_tail_num]
			= std::make_unique<ActorCharacter>(ObjectName, 10, 2.0f, ObjectActor->GetRootComponent());
		ReturnId = std::make_unique<ObjectId>(m_tail_num, m_lived_objects[m_tail_num]->GetIdentityNumber());

		//lived_object의 메모리공간이 부족하다고 에러가 난다.
		m_tail_num = GetBinArraySpace();
	}
	
	return std::move(ReturnId);
}

void ObjectManager::DeleteObject(std::unique_ptr<ObjectId> Id)
{
	m_lived_objects[Id->GetElement()].reset();
}

std::unique_ptr<ObjectId> ObjectManager::AddAction(std::unique_ptr<ObjectId> Id, std::shared_ptr<IAction> Action)
{
	checkf(Id->GetElement() < LIVED_OBJECT_SIZE, TEXT("ObjectManager::AddAction element is over"));
	
	//해당 Element위치가 비어있는지와 해당 Id의 identity번호가 맞는지 검사한다.
	if (m_lived_objects[Id->GetElement()] == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("ObjectManager::AddAction m_libed_objects is Null"));
		return nullptr;
	}
	else if (*Id != ObjectId(Id->GetElement(), m_lived_objects[Id->GetElement()]->GetIdentityNumber()))
	{
		UE_LOG(LogTemp, Log, TEXT("ObjectManager::AddAction ObjectId are m_libed_objects do not match"));
		return nullptr;
	}
	else
	{
		m_lived_objects[Id->GetElement()]->AddAction(Action);
	}


	return std::move(Id);
}

int16 ObjectManager::GetBinArraySpace()
{
	int16 Seat = 0;
	for (int16 i = m_tail_num + 1; i != m_tail_num; i++)
	{

		if (i >= LIVED_OBJECT_SIZE)
		{
			i = 0;
		}
		if (m_lived_objects[i] == nullptr)
		{
			Seat = i;
			break;
		}


	}
	checkf(m_lived_objects[Seat] == nullptr, TEXT("Array haven't Space"));

	return Seat;
}

void ObjectManager::ObjectsUpdate()
{
	for (auto& i : m_lived_objects)
	{
		if (i != nullptr) {
			i->Update();
			
		}
	}
}
const uint16  CirculatorElerment(const uint16  num)
{
	if (num >= LIVED_OBJECT_SIZE)
	{
		return 0;
	}
	return num + 1;
}