// Fill out your copyright notice in the Description page of Project Settings.


#include "Condition_WasIBitten.h"

#include "AIAgent.h"

// Typedefs
typedef Node PARENT;

Condition_WasIBitten::Condition_WasIBitten(AAIAgent* a_pOwner) : PARENT(a_pOwner)
{
}

Condition_WasIBitten::~Condition_WasIBitten()
{
	
}

BEHAVIOUR_STATUS Condition_WasIBitten::Update()
{
	if (GetOwner()->HasBeenBitten())
	{
		return SUCCESS;
	}
	else
	{
		return FAILURE;
	}
}