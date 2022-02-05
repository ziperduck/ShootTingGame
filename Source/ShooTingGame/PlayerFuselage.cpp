// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFuselage.h"

PlayerFuselage::PlayerFuselage(AActor* Actor, std::shared_ptr<FuselageData> BaseData)
    :FuselageCharacter(Actor), m_move(BaseData), m_collision(BaseData), m_base_data(BaseData) {}

PlayerFuselage::~PlayerFuselage(){}


bool PlayerFuselage::Move()
{
    return m_move.execute(m_actor);
}

bool PlayerFuselage::Collision()
{
    return m_collision.execute(m_actor);
}

bool PlayerFuselage::Death()
{
    return false;
}


void PlayerFuselage::LeftPresses()
{
    m_move.LeftPresses();
}

void PlayerFuselage::RightPresses()
{
    m_move.RightPresses();
}

void PlayerFuselage::ForwardPresses()
{
    m_move.ForwardPresses();
}

void PlayerFuselage::BackwardPresses()
{
    m_move.BackwardPresses();
}


void PlayerFuselage::LeftRelease()
{
    m_move.LeftRelease();
}

void PlayerFuselage::RightRelease()
{
    m_move.RightRelease();
}

void PlayerFuselage::ForwardRelease()
{
    m_move.ForwardRelease();
}

void PlayerFuselage::BackwardRelease()
{
    m_move.BackwardRelease();
}

void PlayerFuselage::Resetkey()
{
    m_move.Resetkey();
}

