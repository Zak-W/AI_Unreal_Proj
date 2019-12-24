// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Node.h"

// Forward declarations
class AAIAgent;


class ASSESSTEST_API Condition_HaveIArrived: public Node
{
public:
	Condition_HaveIArrived(AAIAgent* a_pOwner);
	~Condition_HaveIArrived();

	virtual BEHAVIOUR_STATUS Update();
};
