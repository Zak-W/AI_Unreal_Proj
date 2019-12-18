// This file's header
#include "Condition_AmIInfected.h"

// Includes
#include "AIAgent.h"

// Typedefs
typedef Node PARENT;

Condition_AmIInfected::Condition_AmIInfected(AAIAgent* a_pOwner) : PARENT(a_pOwner)
{
}

Condition_AmIInfected::~Condition_AmIInfected()
{
}

BEHAVIOUR_STATUS Condition_AmIInfected::Update()
{
	if (GetOwner()->IsInfected() && GetOwner()->GetMutated())
	{
		return SUCCESS;
	}
	else
	{
		return FAILURE;
	}
}