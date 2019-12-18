#pragma once

// Includes
#include "CoreMinimal.h"
#include "Node.h"

// Mutate class
class ASSESSTEST_API Action_FindPatrolLocation : public Node
{
public:
	Action_FindPatrolLocation(AAIAgent* a_pOwner);
	~Action_FindPatrolLocation();

	BEHAVIOUR_STATUS Update();

private:

	float m_fPatrolRadius = 300.0f;
};