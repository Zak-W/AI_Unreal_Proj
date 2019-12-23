#pragma once

// Includes
#include "CoreMinimal.h"
#include "Node.h"

// Mutate class
class ASSESSTEST_API Action_FindNearestGuard : public Node
{
public:
	Action_FindNearestGuard(AAIAgent* a_pOwner);
	~Action_FindNearestGuard();

	BEHAVIOUR_STATUS Update();

private:
};