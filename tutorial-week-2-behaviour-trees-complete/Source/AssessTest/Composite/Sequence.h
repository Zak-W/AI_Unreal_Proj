#pragma once

// Includes
#include "CoreMinimal.h"
#include "Composite.h"

class ASSESSTEST_API Sequence : public Composite
{
public:
	Sequence(AAIAgent* a_pOwner);
	~Sequence();

	virtual BEHAVIOUR_STATUS Update();
};
