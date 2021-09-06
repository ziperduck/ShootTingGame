// Fill out your copyright notice in the Description page of Project Settings.


#include "Character.h"
#include "EnemyCharacter.h"
#include "PlayerCharacter.h"
#include "Rifle.h"
#include "Weapon.h"
#include <Engine/World.h>
#include <Engine.h>
#include "ObjectManager.h"

WrappingObject::WrappingObject(std::weak_ptr<IObject> Object, const uint16& Address)
	: m_wrap_object(Object), m_address(Address)
{

}

WrappingObject::~WrappingObject()
{
	m_wrap_object.reset();
}

void WrappingObject::AddAction(std::shared_ptr<IAction> Action)
{
	if (m_wrap_object.use_count() > 0 && Action.use_count() > 0)
	{
		m_wrap_object.lock()->AddAction(Action);
		return;
	}
	UE_LOG(LogTemp, Log, TEXT("Object(%s) is NULL"));
}

void WrappingObject::AddAnimation(std::queue<std::queue<std::shared_ptr<IAction>>> Animation)
{
	m_wrap_object.lock()->AddAnimation(Animation);
}

const uint16 WrappingObject::GetAddress() const
{
	return m_address;
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

std::unique_ptr<WrappingObject> ObjectManager::CreateObject(const ObjectKind Kind, UWorld* SpawnWorld, const FVector SpawnPoint)
{

	std::unique_ptr<WrappingObject> ReturnId = nullptr;
	UE_LOG(LogTemp, Log, TEXT("m_tail_num %d"), m_tail_num);
	//spawn world가 비어있는지 확인
	if (SpawnWorld == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("World is nullptr"));
	}
	else
	{
		//spawn world가 채워져 있을경우 ObjectKind값을 통해 world에 Actor들을 배치한다

		AActor* SpawnObject = nullptr;
		switch (Kind)
		{
		case ObjectKind::PlayerObject:
		{

			SpawnObject = SpawnWorld->SpawnActor<APlayerCharacter>(SpawnPoint, FRotator{ 0.0f,0.0f,0.0f });
			IObject* RifleObject = new RifleGun(ObjectKind::RifleObject, 1, 4.0f, 2, nullptr);
			m_lived_objects[m_tail_num]
				= std::make_unique<ActorCharacter>(Kind, 10, 2.0f, SpawnObject->GetRootComponent(), RifleObject);
			break;
		}
		case ObjectKind::EnemyObject:
		{
			SpawnObject = SpawnWorld->SpawnActor<AEnemyCharacter>(SpawnPoint, FRotator{ 0.0f,0.0f,0.0f });
			IObject* RifleObject = new RifleGun(ObjectKind::RifleObject, 1, 4.0f, 2, nullptr);
			m_lived_objects[m_tail_num]
				= std::make_unique<ActorCharacter>(Kind, 10, 2.0f, SpawnObject->GetRootComponent(), RifleObject);
			break;
		}
		case ObjectKind::RifleObject:
		{
			SpawnObject = SpawnWorld->SpawnActor<ARifle>(SpawnPoint, FRotator{ 0.0f,0.0f,0.0f });
		m_lived_objects[m_tail_num]
			= std::make_unique<RifleGun>(Kind, 10, 2.0f, 2, SpawnObject->GetRootComponent());
		break;
		}
		default:
			checkNoEntry();
			break;
		}
		checkf(SpawnObject != nullptr, TEXT("CreateObject memeber function in SpawnObject Data is nullptr"));
		ReturnId = std::make_unique<WrappingObject>(m_lived_objects[m_tail_num], m_tail_num);

		//lived_object의 메모리공간이 부족하다고 에러가 난다.
		m_tail_num = GetBinArraySpace();
	}
	
	return std::move(ReturnId);
}

void ObjectManager::DeleteObject(std::unique_ptr<WrappingObject> wraping)
{
	const int16 Address = wraping->GetAddress();
	m_lived_objects[Address].reset();
	m_lived_objects[Address] = nullptr;
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