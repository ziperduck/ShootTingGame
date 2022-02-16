// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"

#include "Fuselages.h"

#include "FuselageBaseData.h"
#include "FuselageData.h"
#include "FuselageStatus.h"

#include "FuselageBehavior.h"
#include "FuselageAttack.h"

#include "FuselageCharacter.h"

#include "GameFramework/Pawn.h"
#include "TestCharacter.generated.h"


UCLASS()
class SHOOTINGGAME_API ATestCharacter : public APawn, public IFuselageBaseData
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATestCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//�浹�� ȣ��Ǵ� �Լ�
	virtual void NotifyActorBeginOverlap(AActor* other) final;

	UFUNCTION(BlueprintCallable, Category = "TestFuselage")
	void m_left_right(int Direction);
	UFUNCTION(BlueprintCallable, Category = "TestFuselage")
	void m_up_dawn(int Direction);


private:

	//���� ���� �ൿ
	std::shared_ptr<FuselageBehavior> m_attackevent;

	//�̵� ���� �ൿ��
	std::shared_ptr<FuselageBehavior> m_leftevent;
	std::shared_ptr<FuselageBehavior> m_rightevent;
	std::shared_ptr<FuselageBehavior> m_forwardevent;
	std::shared_ptr<FuselageBehavior> m_backwardevent;

	//�ش� ��ü�� ��� �ൿ��
	std::queue<std::shared_ptr<FuselageBehavior>> m_behavior;
};
