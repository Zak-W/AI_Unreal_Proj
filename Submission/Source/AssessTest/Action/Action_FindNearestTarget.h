#pragma once
////////////////////////////////////////////////////////////
// File:  <Action_FindNearestTarget.h>
// Author:  <Zak Waters>  
// Date Created: <05/11/2019> 
// Brief:  <header file for finding closest targetpoint> 
////////////////////////////////////////////////////////////
// Includes
#include "CoreMinimal.h"
#include "Node.h"

// Mutate class
class ASSESSTEST_API Action_FindNearestTarget : public Node
{
public:
	Action_FindNearestTarget(AAIAgent* a_pOwner);
	~Action_FindNearestTarget();

	BEHAVIOUR_STATUS Update();

private:
};