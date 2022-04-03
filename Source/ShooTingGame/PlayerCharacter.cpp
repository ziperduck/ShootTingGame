// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "FuselageData.h"
#include "FuselageStatus.h"

#include "WeaponStruct.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Player RootComponenet"));

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	m_base_data = std::make_shared<FuselageCharacter>(this,0.0f, FuselageMaker::GetUFO());

	m_player_data = std::make_shared<PlayerCharacterData>(this, 5);

	m_overlap_befor_hp = m_base_data->GetCurrentHP();
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("KeyboadA", IE_Pressed, this, &APlayerCharacter::PressedAttackKey);
	InputComponent->BindAction("KeyboadA", IE_Released, this, &APlayerCharacter::ReleasedAttackKey);

	InputComponent->BindAction("KeyboadX", IE_Pressed, this, &APlayerCharacter::FinishiMoveKey);

	InputComponent->BindAxis("UpDown", this, &APlayerCharacter::m_up_dawn);
	InputComponent->BindAxis("LeftRight", this, &APlayerCharacter::m_left_right);
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	checkf(m_base_data.get() != nullptr, TEXT("APlayerCharacter base data is nullptr"));

	//����Ű�� ���� �����ϰ�� pleasedcommand�� �߰��Ѵ�.
	if (m_pressed_attack_key)
	{
		UE_LOG(LogTemp, Log, TEXT("m_pressed_attack_key"));
		m_all_command.push(&m_pressedshoot_command);
	}

	//�÷��̾� �����ϰ�� ������ ��ü�Ѵ�.
	if (m_base_data->GetUnion() == static_cast<int8>(EUnionBinary::PLAYER_INVINCIBILITY_BINARY))
	{
		//�÷��̾��� �������ӽð��� ���� ���δ�.
		if (++m_invincibility_count > m_invincibility_time)
		{
			m_all_command.push(&m_invincibility_off_command);
			m_invincibility_count = 0;
		}
	}

	//�������� �޾��� ��� 
	if (m_base_data->GetCurrentHP() < m_overlap_befor_hp)
	{
		//�÷��̾� ���������
		m_all_command.push(&m_invincibility_on_command);

		m_overlap_befor_hp = m_base_data->GetCurrentHP();

		//���� ������쿡�� ��� �ൿ���� ���ְ� command�� �����Ų��.
		if (m_base_data->GetCurrentHP() <= 0.0f)
		{
			m_all_command.push(&m_death_command);
		}
	}

	//��� �ൿ���� �����Ų��.
	while (!m_all_command.empty())
	{
		m_all_command.front()->execute(m_base_data);
		m_all_command.pop();
	}
	
	while (!m_all_player_command.empty())
	{
		m_all_player_command.front()->execute(m_player_data);
		m_all_player_command.pop();
	}

	UE_LOG(LogTemp, Log, TEXT("Player Location(%s)"), *GetActorLocation().ToString());
	UE_LOG(LogTemp, Log, TEXT("Player HP %f"), m_base_data->GetCurrentHP());
	UE_LOG(LogTemp, Log, TEXT("Player Score %d"), m_player_data->GetScore());

}

void APlayerCharacter::NotifyActorBeginOverlap(AActor* other)
{
	m_all_command.push(&m_collision_command);
	m_overlap_befor_hp = m_base_data->GetCurrentHP();
}

//�ӽ÷� ��� ����Ű�� move�� push�ߴ�
void APlayerCharacter::m_left_right(float Direction)
{
	switch ((int32)Direction)
	{
	case -1:
		m_all_command.push(&m_leftmove_command);
		break;
	case 1:
		m_all_command.push(&m_rightmove_command);
		break;
	default:
		break;
	}
}

void APlayerCharacter::m_up_dawn(float Direction)
{
	switch ((int32)Direction)
	{
	case -1:
		m_all_command.push(&m_backwardmove_command);
		break;
	case 1:
		m_all_command.push(&m_forwardmove_command);
		break;
	default:
		break;
	}
}

void APlayerCharacter::PressedAttackKey()
{
	m_pressed_attack_key = true;
}

void APlayerCharacter::ReleasedAttackKey()
{
	m_pressed_attack_key = false;
	m_all_command.push(&m_releaseshoot_command);
}

void APlayerCharacter::FinishiMoveKey()
{
	m_all_player_command.push(&m_finishmove_command);
}

