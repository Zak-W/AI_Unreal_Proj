#pragma once
////////////////////////////////////////////////////////////
// File:  <Action_FleeFromGuard.h>
// Author:  <Zak Waters>  
// Date Created: <20/11/2019> 
// Brief:  <header file for fleeing to a point away from a guard> 
////////////////////////////////////////////////////////////
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
