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
	UGameplayStatics::GetAllActorsWithTag(GetOwner()->GetWorld(), "Goal", aFoundAgents);

	//initialise to the first of the Tarray, should only be one anyway
	AActor* pTarget = nullptr;

	//null check
	if (aFoundAgents[0])
	{
		pTarget = aFoundAgents[0];
	}

	//if tag is goal, another null check
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
