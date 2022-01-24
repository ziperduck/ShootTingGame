// Fill out your copyright notice in the Description page of Project Settings.

#include "DirectData.h"
#include "EnumPack.h"

DirectData::DirectData() 
	:  m_pressed_key{ EDirectMove::NON, }, m_current_point(0) {}

DirectData::DirectData(const DirectData& Data)
	:  m_pressed_key(Data.m_pressed_key), m_current_point(Data.m_current_point){};

DirectData::~DirectData()
{

}

void DirectData::LeftPresses()
{
	m_pressed_key[m_current_point] = EDirectMove::LEFT_MOVE;
	++m_current_point;
}
void DirectData::RightPresses()
{
	m_pressed_key[m_current_point] = EDirectMove::RIGHT_MOVE;
	++m_current_point;
}
void DirectData::StrightPresses()
{
	m_pressed_key[m_current_point] = EDirectMove::STRAIGHT_MOVE;
	++m_current_point;
}
void DirectData::BackPresses()
{
	m_pressed_key[m_current_point] = EDirectMove::BACK_MOVE;
	++m_current_point;
}

void DirectData::ResetPressed()
{
	for (auto& i : m_pressed_key)
	{
		i = EDirectMove::NON;
	}
	m_current_point = 0;
}

const std::array<EDirectMove, 4>& DirectData::GetPressedKey() const
{
	return m_pressed_key;
}
