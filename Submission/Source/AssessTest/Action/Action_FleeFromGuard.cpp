// This file's header
#include "Action_FleeFromGuard.h"

// Includes
#include "AIAgent.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Engine/TargetPoint.h"

// Constants
const float fCOLOUR_CHANGE_RATE = 0.001f;

// Typedef
typedef Node PARENT;

Action_FleeFromGuard::Action_FleeFromGuard(AAIAgent * a_pOwner) : PARENT(a_pOwner)
{
}

Action_FleeFromGuard::~Action_FleeFromGuard()
{
}

BEHAVIOUR_STATUS Action_FleeFromGuard::Update()
{
	// Null check
	if (!GetOwner())
	{
		return FAILURE; // Early out
	}

	// Get all actors of type "TargetPoint"
	TArray<AActor*> aFoundTargets;
	UGameplayStatics::GetAllActorsOfClass(GetOwner()->GetWorld(), ATargetPoint::StaticClass(), aFoundTargets);

	// Get guard
	AActor* pCurrentGuard = GetOwner()->GetTargetActor();

	// Get ready to cache our furthest distance and target
	float fFurthestTargetDistance = 0;
	ATargetPoint* pTarget = nullptr;

	for (int i = 0; i < aFoundTargets.Num(); ++i)
	{
		ATargetPoint* pCurrentAgent = Cast<ATargetPoint>(aFoundTargets[i]);;
		float fDistanceBetween = FVector::Dist(pCurrentGuard->GetActorLocation(), aFoundTargets[i]->GetActorLocation());
		if (fDistanceBetween > fFurthestTargetDistance)
		{
			fFurthestTargetDistance = fDistanceBetween;
			pTarget = pCurrentAgent;
		}
	}

	if (pTarget)
	{
		GetOwner()->SetTargetActor(pTarget);
		return SUCCESS;
	}
	else
	{
		return FAILURE;
	}
}
