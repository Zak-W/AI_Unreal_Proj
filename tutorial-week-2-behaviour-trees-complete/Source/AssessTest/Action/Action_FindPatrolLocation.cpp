//files header
#include "Action_FindPatrolLocation.h"

// Includes
#include "AIAgent.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/World.h"
#include "Engine/TargetPoint.h"
#include "Math/Vector.h"

// Typedef
typedef Node PARENT;

Action_FindPatrolLocation::Action_FindPatrolLocation(AAIAgent * a_pOwner) : PARENT(a_pOwner)
{
}

Action_FindPatrolLocation::~Action_FindPatrolLocation()
{
}

BEHAVIOUR_STATUS Action_FindPatrolLocation::Update()
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
		ATargetPoint* pChosenTargetPoint = nullptr;
		while (pChosenTargetPoint == nullptr)
		{
			int iIndex = FMath::RandRange(0, Waypoints.Num() - 1);
			if (FVector::Dist(Waypoints[iIndex]->GetActorLocation(), GetOwner()->Get_PatrolCentre()) < m_fPatrolRadius)
			{
				pChosenTargetPoint = Cast<ATargetPoint>(Waypoints[iIndex]);
			}
		}


		if (pChosenTargetPoint != nullptr)
		{
			GetOwner()->SetTargetActor(pChosenTargetPoint);

			return SUCCESS;
		}
	}

	return FAILURE;
}