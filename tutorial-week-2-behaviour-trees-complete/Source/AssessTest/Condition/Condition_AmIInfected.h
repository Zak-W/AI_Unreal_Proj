#pragma once

// Includes
#include "CoreMinimal.h"
#include "Node.h"

// Forward declarations
class AAIAgent;

// Class
class ASSESSTEST_API Condition_AmIInfected : public Node
{
public:
	Condition_AmIInfected(AAIAgent* a_pOwner);
	~Condition_AmIInfected();

	virtual BEHAVIOUR_STATUS Update();
};
