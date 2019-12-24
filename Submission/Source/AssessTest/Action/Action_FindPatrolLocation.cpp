//files header
#include "Action_FindPatrolLocation.h"

// Includes
#include "AIAgent.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/World.h"
#include "Engine/TargetPoint.h"
#include "Math/Vector.h"
#include "Classes/Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/AI/NavigationSystemBase.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "Runtime/NavigationSystem/Public/AbstractNavData.h"

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

	UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetOwner()->GetWorld());//Get the current Navmesh system data
	FVector vRandLoc = NavSys->GetRandomPointInNavigableRadius(GetOwner()->GetWorld(), GetOwner()->GetPatrolCentre(), m_fPatrolRadius);//Choose a random location on the navmesh

	TArray<AActor*> pWaypoints;
	UGameplayStatics::GetAllActorsOfClass(GetOwner()->GetWorld(), ATargetPoint::StaticClass(), pWaypoints);

	// Get ready to cache our nearest distance and agent
	float fNearestAgentDistance = TNumericLimits<float>::Max();
	AActor* pTargetActor = nullptr;

	for (int i = 0; i < pWaypoints.Num(); ++i)
	{
		ATargetPoint* pCurrentTarget = Cast<ATargetPoint>(pWaypoints[i]);
		float fDistanceBetween = FVector::Dist(vRandLoc, pCurrentTarget->GetActorLocation());
		if (fDistanceBetween < fNearestAgentDistance)
		{
			fNearestAgentDistance = fDistanceBetween;
			pTargetActor = pCurrentTarget;
		}
	}

	if (pTargetActor)
	{
		GetOwner()->SetTargetActor(pTargetActor);
		return SUCCESS;
	}
	else
	{
		return FAILURE;
	}
}