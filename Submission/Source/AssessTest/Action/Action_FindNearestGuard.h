#pragma once
////////////////////////////////////////////////////////////
// File:  <Action_FindNearestGuard.h>
// Author:  <Zak Waters>  
// Date Created: <15/12/2019> 
// Brief:  <header file for finding closest guard agent> 
////////////////////////////////////////////////////////////
// Includes
#include "CoreMinimal.h"
#include "Node.h"

// Mutate class
class ASSESSTEST_API Action_FindNearestGuard : public Node
{
public:
	Action_FindNearestGuard(AAIAgent* a_pOwner);
	~Action_FindNearestGuard();

	BEHAVIOUR_STATUS Update();

private:
};