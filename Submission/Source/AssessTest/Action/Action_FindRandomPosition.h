#pragma once

// Includes
#include "CoreMinimal.h"
#include "Node.h"

// Mutate class
class ASSESSTEST_API Action_FindRandomPosition : public Node
{
public:
	Action_FindRandomPosition(AAIAgent* a_pOwner);
	~Action_FindRandomPosition();

	BEHAVIOUR_STATUS Update();

private:
};