// This file's header
#include "Action_MoveToTarget.h"

// Includes
#include "AIAgent.h"
#include "AIController.h"
#include "Classes/Blueprint/AIBlueprintHelperLibrary.h"

// Typedef
typedef Node PARENT;

Action_MoveToTarget::Action_MoveToTarget(AAIAgent* a_pOwner) : PARENT(a_pOwner)
{
	m_bMoveRequested = false;
}

Action_MoveToTarget::~Action_MoveToTarget()
{
}

BEHAVIOUR_STATUS Action_MoveToTarget::Update()
{
	if (GetOwner())
	{
		AAIController* pAIController = Cast<AAIController>(GetOwner()->GetController());
		if (pAIController && GetOwner()->GetTargetActor())
		{
			UAIBlueprintHelperLibrary::SimpleMoveToActor(pAIController, GetOwner()->GetTargetActor());

			if (pAIController->GetMoveStatus() == EPathFollowingStatus::Moving)
			{
				return RUNNING;
			}
			else if (pAIController->GetMoveStatus() == EPathFollowingStatus::Idle)
			{
				return SUCCESS;
			}
		}
	}

	return FAILURE;
}