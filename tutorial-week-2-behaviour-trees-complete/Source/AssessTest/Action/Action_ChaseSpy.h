#pragma once

// Includes
#include "CoreMinimal.h"
#include "Node.h"

// Mutate class
class ASSESSTEST_API Action_ChaseSpy : public Node
{
public:
	Action_ChaseSpy(AAIAgent* a_pOwner);
	~Action_ChaseSpy();

	BEHAVIOUR_STATUS Update();
};