// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Airframe.h"
#include "Fuselage.h"
#include "EnumPack.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerCharacter.generated.h"

UCLASS(Blueprintable, BlueprintType, ClassGroup = "Fuselage")
class SHOOTINGGAME_API APlayerCharacter : public APawn, public IFuselage
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	virtual void Tick(float Delta) override;
	
	//Getter
	virtual const EFuselageKind GetKind() const override;

	virtual const float GetSpeed() const override;

	virtual const FVector GetLocation() const override;

	virtual const FRotator GetRotation() const override;

	virtual UWorld* GetFuselageWorld() const override;

	virtual UClass* GetComponentClass() const override;

	//Setter
	virtual void MoveLocation(const FVector& MoveLocation) override;
	
	//Event
	virtual void EventUpdate() override;
	
	UFUNCTION(BlueprintCallable)
	void MoveX(float Direction);

	UFUNCTION(BlueprintCallable)
	void MoveY(float Direction);

	UFUNCTION(BlueprintCallable)
		void MoveA(float Direction);

	UFUNCTION(BlueprintSetter)
		void SetWeapon(TSubclassOf<class AActor> Weapon);
	
	UFUNCTION(BlueprintCallable)
		void ShootingGun();

public:
	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<class AActor> m_weapon;
private:

	USceneComponent* m_characterScene;

private:

	EFuselageKind m_kind;

	float m_speed;

	int8 m_max_HP;

	int8 m_current_HP;

	std::queue<EVariousAction> m_actions;
};
