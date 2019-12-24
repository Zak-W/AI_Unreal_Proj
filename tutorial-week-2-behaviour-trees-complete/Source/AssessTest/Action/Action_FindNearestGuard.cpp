// This file's header
#include "Action_FindNearestGuard.h"

// Includes
#include "AIAgent.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/World.h"

// Constants
const float fCOLOUR_CHANGE_RATE = 0.001f;

// Typedef
typedef Node PARENT;

Action_FindNearestGuard::Action_FindNearestGuard(AAIAgent * a_pOwner) : PARENT(a_pOwner)
{
}

Action_FindNearestGuard::~Action_FindNearestGuard()
{
}

BEHAVIOUR_STATUS Action_FindNearestGuard::Update()
{
	// Null check
	if (!GetOwner())
	{
		return FAILURE; // Early out
	}

	// Get all actors
	TArray<AActor*> aFoundAgents;
	UGameplayStatics::GetAllActorsOfClass(GetOwner()->GetWorld(), AActor::StaticClass(), aFoundAgents);

	// Get this actor's current position
	FVector vCurrentPos = GetOwner()->GetActorLocation();

	// Get ready to cache our nearest distance and agent
	float fNearestAgentDistance = TNumericLimits<float>::Max();
	AActor* pTargetAgent = nullptr;

	for (int i = 0; i < aFoundAgents.Num(); ++i)
	{
		// Make sure we don't chase ourselves...
		if (aFoundAgents[i]->GetUniqueID() != GetOwner()->GetUniqueID())
		{
			AActor* pCurrentAgent = aFoundAgents[i];
			if (pCurrentAgent->GetOwner()->ActorHasTag("Guard") || pCurrentAgent->GetOwner()->ActorHasTag("Seeker"))
			{
				float fDistanceBetween = FVector::Dist(vCurrentPos, aFoundAgents[i]->GetActorLocation());
				if (fDistanceBetween < fNearestAgentDistance)
				{
					fNearestAgentDistance = fDistanceBetween;
					pTargetAgent = pCurrentAgent;
				}
			}

		}
	}

	if (pTargetAgent)
	{
		GetOwner()->SetTargetActor(pTargetAgent);
		return SUCCESS;
	}
	else
	{
		return FAILURE;
	}
}
