// This file's header
#include "Action_TargetGoal.h"

// Includes
#include "AIAgent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/Classes/Components/SkeletalMeshComponent.h"
#include "AIController.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/World.h"

// Typedef
typedef Node PARENT;

Action_TargetGoal::Action_TargetGoal(AAIAgent * a_pOwner) : PARENT(a_pOwner)
{
}

Action_TargetGoal::~Action_TargetGoal()
{
}

BEHAVIOUR_STATUS Action_TargetGoal::Update()
{
	// Null check
	if (!GetOwner())
	{
		return FAILURE; // Early out
	}

	// Get all actors
	TArray<AActor*> aFoundAgents;
	UGameplayStatics::GetAllActorsWithTag(GetOwner()->GetWorld(), "Guard", aFoundAgents);

	//initialise to the first of the Tarray, should only be one anyway
	AActor* pTarget = aFoundAgents[0];

	//if it did find the spy
	if (pTarget->ActorHasTag("Goal"))
	{
		GetOwner()->SetTargetActor(pTarget);
		return SUCCESS;
	}
	else
	{
		return FAILURE;
	}
}
