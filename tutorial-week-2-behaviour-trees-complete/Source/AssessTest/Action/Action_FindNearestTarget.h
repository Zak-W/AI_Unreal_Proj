#pragma once

// Includes
#include "CoreMinimal.h"
#include "Node.h"

// Mutate class
class ASSESSTEST_API Action_FindNearestTarget : public Node
{
public:
	Action_FindNearestTarget(AAIAgent* a_pOwner);
	~Action_FindNearestTarget();

	BEHAVIOUR_STATUS Update();

private:
};