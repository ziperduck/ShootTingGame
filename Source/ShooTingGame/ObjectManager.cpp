// Fill out your copyright notice in the Description page of Project Settings.


#include "Character.h"
#include "EnemyCharacter.h"
#include "PlayerCharacter.h"
#include <Engine/World.h>
#include <Engine.h>
#include "ObjectManager.h"

const int ObjectId::GetElement() const {
	return m_arr_element;
}

bool operator==(const ObjectId& Left, const ObjectId& Right) 
{
	return (Left.m_arr_element == Right.m_arr_element) && (Left.m_identity_num == Right.m_identity_num);
}

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
			= std::make_shared<ActorCharacter>(ObjectName, 10, 2.0f, ObjectActor->GetRootComponent());
		ReturnId = std::make_unique<ObjectId>(m_tail_num, m_lived_objects[m_tail_num]->GetIdentityNumber());

		++m_tail_num;
	}
	
	return std::move(ReturnId);
}

std::unique_ptr<ObjectId> ObjectManager::AddAction(std::unique_ptr<ObjectId> Id, std::shared_ptr<IAction> Action)
{
	checkf(m_lived_objects[Id->GetElement()] != nullptr, TEXT("AddAction memeber function no element in m_lived_objects"));

	m_lived_objects[Id->GetElement()]->AddAction(Action);

	return std::move(Id);
}

void ObjectManager::ObjectsUpdate()
{
	for (auto i : m_lived_objects)
	{
		if (i.use_count() > 1) {
			i->Update();
			
		}
	}
}

const int32 CirculatorElerment(const int32 num)
{
	if (num >= MANAGER_SIZE)
	{
		return 0;
	}
	return num + 1;
}