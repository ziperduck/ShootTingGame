// Fill out your copyright notice in the Description page of Project Settings.



#include "FuselageManager.h"
#include "PlayerCharacter.h"
#include "Rifle.h"
#include "EnemyDragon.h"
#include <Engine/World.h>
#include <Engine.h>

WrappingFuselage::WrappingFuselage(TSharedPtr<IFuselage> Fuselage, const uint16& Address)
	: m_wrap_fuselage(Fuselage), m_address(Address)
{

}

WrappingFuselage::~WrappingFuselage()
{
}

void WrappingFuselage::AddAction(std::shared_ptr<IAction> Action)
{
	if (m_wrap_fuselage != nullptr)
	{
		m_wrap_fuselage->AddAction(Action);
		return;
	}
	UE_LOG(LogTemp, Log, TEXT("Object(%s) is NULL"));
}

const uint16 WrappingFuselage::GetAddress() const
{
	return m_address;
}


FuselageManager::FuselageManager() : m_lived_fuselage{ nullptr, }, m_tail_num(0){
	UE_LOG(LogTemp, Log, TEXT("FuselageManager Constructor"));
};

FuselageManager::~FuselageManager()
{
}

FuselageManager* FuselageManager::GetInstance()
{
	static FuselageManager* Manager = new FuselageManager();
	return Manager;
}

std::unique_ptr<WrappingFuselage> FuselageManager::AddFuselage(const FuselageKind Kind, const FVector SpawnPoint)
{
	UE_LOG(LogTemp, Log, TEXT("m_tail_num %d"), m_tail_num);
	
	/*
	* new Object를 해서 makeshared를 해보자
	*/
	switch (Kind)
	{
	case FuselageKind::PlayerFuselage:

		m_lived_fuselage[m_tail_num] = MakeShared<IFuselage>(Cast<IFuselage>(NewObject<UEnemyDragon>()));
		break;
	case FuselageKind::EnemyFuselage:

		m_lived_fuselage[m_tail_num] = MakeShared<IFuselage>(Cast<IFuselage>(NewObject<UEnemyDragon>()));

		break;
	case FuselageKind::RifleFuselage:

		m_lived_fuselage[m_tail_num] = MakeShared<IFuselage>(Cast<IFuselage>(NewObject<URifle>()));
		break;
	default:
		checkNoEntry();
		break;
	}

	checkf(m_lived_fuselage[m_tail_num].Get() != nullptr, TEXT("AddFuselage is nullptr"));

	CreateFuselage(m_lived_fuselage[m_tail_num], SpawnPoint);

	std::unique_ptr<WrappingFuselage> ReturnId 
		= std::make_unique<WrappingFuselage>(m_lived_fuselage[m_tail_num], m_tail_num);

	//lived_object의 메모리공간이 부족하다고 에러가 난다.
	m_tail_num = GetBinArraySpace();

	return std::move(ReturnId);
}

std::unique_ptr<WrappingFuselage> FuselageManager::AddFuselage(TSharedPtr<IFuselage> Fuselage, const FVector SpawnPoint)
{

	checkf(Fuselage.Get() != nullptr, TEXT("Fuselage is nullptr"));

	m_lived_fuselage[m_tail_num] = Fuselage;

	CreateFuselage(m_lived_fuselage[m_tail_num], SpawnPoint);

	std::unique_ptr<WrappingFuselage> ReturnId
		= std::make_unique<WrappingFuselage>(m_lived_fuselage[m_tail_num], m_tail_num);

	m_tail_num = GetBinArraySpace();

	return std::move(ReturnId);
}

void FuselageManager::CreateFuselage(TSharedPtr<IFuselage> Fuselage,const FVector SpawnPoint)
{
	checkf(Fuselage != nullptr, TEXT("Fuselage  is nullptr"));
	AActor* CehckActor = Fuselage->GetFuselageWorld()
		->SpawnActor<AActor>(Fuselage->GetComponentClass(), SpawnPoint, Fuselage->GetRotation());

	checkf(CehckActor != nullptr, TEXT("CehckActor  is nullptr"));
}

void FuselageManager::DeleteObject(std::unique_ptr<WrappingFuselage> wraping)
{
	const int16 Address = wraping->GetAddress();
	m_lived_fuselage[Address].Reset();
	m_lived_fuselage[Address] = nullptr;
}

int16 FuselageManager::GetBinArraySpace()
{
	int16 Seat = 0;
	for (int16 i = m_tail_num + 1; i != m_tail_num; i++)
	{

		if (i >= LIVED_OBJECT_SIZE)
		{
			i = 0;
		}
		if (m_lived_fuselage[i] == nullptr)
		{
			Seat = i;
			break;
		}


	}
	checkf(m_lived_fuselage[Seat] == nullptr, TEXT("Array haven't Space"));

	return Seat;
}

void FuselageManager::ObjectsUpdate()
{
	for (auto& i : m_lived_fuselage)
	{
		if (i != nullptr) {
			i->Update();
			
		}
	}
}