// This file's header
#include "Action_FindNearestTarget.h"

// Includes
#include "AIAgent.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/World.h"

// Constants
const float fCOLOUR_CHANGE_RATE = 0.001f;

// Typedef
typedef Node PARENT;

Action_FindNearestTarget::Action_FindNearestTarget(AAIAgent* a_pOwner) : PARENT(a_pOwner)
{
	
}

Action_FindNearestTarget::~Action_FindNearestTarget()
{
}

BEHAVIOUR_STATUS Action_FindNearestTarget::Update()
{
	// Null check
	if (!GetOwner())
	{
		return FAILURE; // Early out
	}

	// Get all actors of type "AAIAgent"
	TArray<AActor*> aFoundAgents;
	UGameplayStatics::GetAllActorsOfClass(GetOwner()->GetWorld(), AAIAgent::StaticClass(), aFoundAgents);

	// Get this actor's current position
	FVector vCurrentPos = GetOwner()->GetActorLocation();

	// Get ready to cache our nearest distance and agent
	float fNearestAgentDistance = TNumericLimits<float>::Max();
	AAIAgent* pTargetAgent = nullptr;

	for (int i = 0; i < aFoundAgents.Num(); ++i)
	{
		// Make sure we don't chase ourselves...
		if (aFoundAgents[i]->GetUniqueID() != GetOwner()->GetUniqueID())
		{
			AAIAgent* pCurrentAgent = Cast<AAIAgent>(aFoundAgents[i]);;
			if (pCurrentAgent && !pCurrentAgent->IsInfected())
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