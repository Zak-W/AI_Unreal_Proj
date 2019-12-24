// This file's header
#include "Sequence.h"

// Typedefs
typedef Composite PARENT;

Sequence::Sequence(AAIAgent* a_pOwner) : PARENT(a_pOwner)
{
}

Sequence::~Sequence()
{
}

BEHAVIOUR_STATUS Sequence::Update()
{
	BEHAVIOUR_STATUS returnStatus = FAILURE;
	Node* pCurrentNode = GetChildNodes()[m_iCurrentIndex];
	if (pCurrentNode)
	{
		BEHAVIOUR_STATUS nodeStatus = pCurrentNode->Update();

		if (nodeStatus == SUCCESS)
		{
			if (m_iCurrentIndex == (GetChildNodes().Num() - 1))
			{
				returnStatus = SUCCESS;
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
