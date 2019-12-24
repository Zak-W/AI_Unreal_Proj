#pragma once

// Includes
#include "CoreMinimal.h"
#include "Decorator.h"

class ASSESSTEST_API Decorator_Inverter : public Decorator
{
public:
	Decorator_Inverter(AAIAgent* a_pOwner);

	BEHAVIOUR_STATUS Update();
};
