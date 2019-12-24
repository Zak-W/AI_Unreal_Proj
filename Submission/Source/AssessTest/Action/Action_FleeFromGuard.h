#pragma once

// Includes
#include "CoreMinimal.h"
#include "Node.h"

// Mutate class
class ASSESSTEST_API Action_FleeFromGuard : public Node
{
public:
	Action_FleeFromGuard(AAIAgent* a_pOwner);
	~Action_FleeFromGuard();

	BEHAVIOUR_STATUS Update();

private:
};
