// This file's header
#include "Decorator_Inverter.h"

Decorator_Inverter::Decorator_Inverter(AAIAgent* a_pOwner) : Decorator(a_pOwner)
{
}

BEHAVIOUR_STATUS Decorator_Inverter::Update()
{
	// Update our child node
	BEHAVIOUR_STATUS eChildNodeStatus = GetChildNode()->Update();

	switch (eChildNodeStatus)
	{
		case SUCCESS:
		{
			// Convert success to failure
			return FAILURE;
		}
		case FAILURE:
		{
			// Convert failure to success
			return SUCCESS;
		}
		case RUNNING:
		{
			return RUNNING;
		}
		default:
		{
			return FAILURE;
		}
	}
}
