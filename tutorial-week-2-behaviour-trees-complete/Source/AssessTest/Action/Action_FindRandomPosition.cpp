// This file's header
#include "Action_FindRandomPosition.h"

// Includes
#include "AIAgent.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Engine/TargetPoint.h"

// Typedef
typedef Node PARENT;

Action_FindRandomPosition::Action_FindRandomPosition(AAIAgent* a_pOwner) : PARENT(a_pOwner)
{
}

Action_FindRandomPosition::~Action_FindRandomPosition()
{
}

BEHAVIOUR_STATUS Action_FindRandomPosition::Update()
{
	if (!GetOwner())
	{
		return FAILURE; // Early out
	}
	AAIAgent* pAgent = Cast<AAIAgent>(GetOwner());

	TArray<AActor*> Waypoints;
	UGameplayStatics::GetAllActorsOfClass(GetOwner()->GetWorld(), ATargetPoint::StaticClass(), Waypoints);

	if (Waypoints.Num() > 0)
	{
		int iIndex = FMath::RandRange(0, Waypoints.Num() - 1);
		ATargetPoint* pChosenTargetPoint = Cast<ATargetPoint>(Waypoints[iIndex]);

		if (pChosenTargetPoint)
		{
			GetOwner()->SetTargetActor(pChosenTargetPoint);

			return SUCCESS;
		}
	}

	return FAILURE;
}