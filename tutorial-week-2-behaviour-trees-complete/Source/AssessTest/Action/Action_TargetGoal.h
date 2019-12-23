#pragma once

// Includes
#include "CoreMinimal.h"
#include "Node.h"

class ASSESSTEST_API Action_TargetGoal : public Node
{
public:
	Action_TargetGoal(AAIAgent* a_pOwner);
	~Action_TargetGoal();

	BEHAVIOUR_STATUS Update();
};