#include "Wander.h"
#include "CPP_Agent.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "AbstractNavData.h"
#include "Behaviours/Chase.h"
#include "Classes/Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/AI/NavigationSystemBase.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "Runtime/NavigationSystem/Public/AbstractNavData.h"
Wander::Wander(ACPP_Agent* pOwner) : Behaviour(pOwner)
{
	m_eCurrentWanderState = FIND_RANDOM_POSITION;
}

void Wander::Update()
{
	switch (m_eCurrentWanderState)
	{
	case FIND_RANDOM_POSITION:
	{
		m_eCurrentWanderState = START_MOVE_TO;
		AAIController* pAIController = Cast<AAIController>(GetOwner()->GetController());

		if (pAIController)//Null check
		{
			UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetOwner()->GetWorld());//Get the current Navmesh system data
			FVector vRandLoc = NavSys->GetRandomPointInNavigableRadius(GetOwner()->GetWorld(), pAIController->GetNavAgentLocation(), 20000.0f);//Choose a random location on the navmesh
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(pAIController, vRandLoc);//Move to that location

			m_eCurrentWanderState = MOVING;
		}
		break;
	}
	case START_MOVE_TO:
	{
		AAIController* pAIController = Cast<AAIController>(GetOwner()->GetController());
		if (pAIController)
		{
			m_eCurrentWanderState = FIND_RANDOM_POSITION;
		}

		break;
	}
	case MOVING:
	{
		AAIController* pAIController = Cast<AAIController>(GetOwner()->GetController());
		if (pAIController)
		{
			if (pAIController->GetMoveStatus() == EPathFollowingStatus::Idle)
			{
				m_eCurrentWanderState = START_MOVE_TO;
			}
		}
		break;
	}
	}
}

Behaviour* Wander::CheckConditions()
{
	// If can see spy, new Chase
	if (GetOwner()->GetCanSeeSpy())
	{
		return new Chase(GetOwner());
	}
	return nullptr;
}