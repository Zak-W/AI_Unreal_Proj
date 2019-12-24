// This file's header
#include "Selector.h"

// Typedefs
typedef Composite PARENT;

Selector::Selector(AAIAgent* a_pOwner) : PARENT(a_pOwner)
{
}

Selector::~Selector()
{
}

BEHAVIOUR_STATUS Selector::Update()
{
	BEHAVIOUR_STATUS returnStatus = FAILURE;
	Node* pCurrentNode = GetChildNodes()[m_iCurrentIndex];
	if (pCurrentNode)
	{
		BEHAVIOUR_STATUS nodeStatus = pCurrentNode->Update();

		if (nodeStatus == FAILURE)
		{
			if (m_iCurrentIndex == (GetChildNodes().Num() - 1))
			{
				returnStatus = FAILURE;
			}
			else
			{
				++m_iCurrentIndex;
				returnStatus = RUNNING;
			}
		}
		else
		{
			returnStatus = nodeStatus;
		}

		if (returnStatus == SUCCESS || returnStatus == FAILURE)
		{
			Reset();
		}
	}

	return returnStatus;
}
