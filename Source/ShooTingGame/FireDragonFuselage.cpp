// Fill out your copyright notice in the Description page of Project Settings.


#include "FireDragonFuselage.h"

FireDragonFuselage::FireDragonFuselage(AActor* Actor, std::shared_ptr<FuselageData> BaseData)
    :FuselageCharacter(Actor), m_move(BaseData), m_collision(BaseData),m_base_data(BaseData){}

FireDragonFuselage::~FireDragonFuselage()
{
}

bool FireDragonFuselage::Move()
{
    return m_move.execute(m_actor);
}

bool FireDragonFuselage::Collision()
{
    return m_collision.execute(m_actor);
}

bool FireDragonFuselage::Death()
{
    return false;
}
