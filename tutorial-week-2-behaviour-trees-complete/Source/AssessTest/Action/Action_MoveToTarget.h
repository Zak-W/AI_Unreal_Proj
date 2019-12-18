#pragma once

// Includes
#include "CoreMinimal.h"
#include "Node.h"

// Mutate class
class ASSESSTEST_API Action_MoveToTarget : public Node
{
public:
	Action_MoveToTarget(AAIAgent* a_pOwner);
	~Action_MoveToTarget();

	BEHAVIOUR_STATUS Update();

private:
	bool m_bMoveRequested;
};