// This file's header
#include "Action_BiteActor.h"

// Includes
#include "AIAgent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/Classes/Components/SkeletalMeshComponent.h"
#include "AIController.h"

// Constants
const float fCOLOUR_CHANGE_RATE = 0.001f;

// Typedef
typedef Node PARENT;

Action_BiteActor::Action_BiteActor(AAIAgent* a_pOwner) : PARENT(a_pOwner)
									
{
	
}

Action_BiteActor::~Action_BiteActor()
{
}

BEHAVIOUR_STATUS Action_BiteActor::Update()
{
	if (GetOwner()->GetTargetActor())
	{
		AAIAgent* pTarget = Cast<AAIAgent>(GetOwner()->GetTargetActor());
		if (pTarget)
		{
			pTarget->SetInfected();
			return SUCCESS;
		}
	}

	// Error
	return NONE;
}