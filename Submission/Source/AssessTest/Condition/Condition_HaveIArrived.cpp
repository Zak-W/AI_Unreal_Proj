// Fill out your copyright notice in the Description page of Project Settings.


#include "Condition_HaveIArrived.h"

// Includes
#include "AIAgent.h"
#include "Math/Vector.h"

// Typedefs
typedef Node PARENT;

Condition_HaveIArrived::Condition_HaveIArrived(AAIAgent* a_pOwner) : PARENT(a_pOwner)
{
}

Condition_HaveIArrived::~Condition_HaveIArrived()
{
}

BEHAVIOUR_STATUS Condition_HaveIArrived::Update()
{
	if (FVector::Dist(GetOwner()->GetActorLocation(), GetOwner()->GetTargetActor()->GetActorLocation()) < 10.0f)
	{
		return SUCCESS;
	}
	else
	{
		return FAILURE;
	}
}
