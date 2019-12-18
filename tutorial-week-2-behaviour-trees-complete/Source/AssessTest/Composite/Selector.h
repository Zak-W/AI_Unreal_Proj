#pragma once

// Includes
#include "CoreMinimal.h"
#include "Composite.h"

// Class
class ASSESSTEST_API Selector : public Composite
{
public:
	Selector(AAIAgent* a_pOwner);
	~Selector();

	BEHAVIOUR_STATUS Update();
};
