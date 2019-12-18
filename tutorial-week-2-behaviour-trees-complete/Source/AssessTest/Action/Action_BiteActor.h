#pragma once

// Includes
#include "CoreMinimal.h"
#include "Node.h"

// Mutate class
class ASSESSTEST_API Action_BiteActor : public Node
{
public:
	Action_BiteActor(AAIAgent* a_pOwner);
	~Action_BiteActor();

	BEHAVIOUR_STATUS Update();

private:
	
};