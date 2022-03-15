// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FuselageCharacter.h"

#include <memory>

/**
 * 
 */
class Command
{
public:
	Command() {};
	virtual ~Command() = 0 {};

	virtual bool execute(std::shared_ptr<FuselageCharacter> Character) = 0;

};

