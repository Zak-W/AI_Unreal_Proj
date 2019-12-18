// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Node.h"

class AAIAgent;

/**
 * 
 */
class ASSESSTEST_API Condition_WasIBitten : public Node
{
public:
	Condition_WasIBitten(AAIAgent* a_pOwner);
	~Condition_WasIBitten();

	virtual BEHAVIOUR_STATUS Update();
};
