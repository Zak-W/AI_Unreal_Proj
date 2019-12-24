#pragma once
////////////////////////////////////////////////////////////
// File:  <Action_ChaseSpy.h>
// Author:  <Zak Waters>  
// Date Created: <8/12/2019> 
// Brief:  <header file for moving toward a spy agent> 
////////////////////////////////////////////////////////////
// Includes
#include "CoreMinimal.h"
#include "Node.h"

// Mutate class
class ASSESSTEST_API Action_ChaseSpy : public Node
{
public:
	Action_ChaseSpy(AAIAgent* a_pOwner);
	~Action_ChaseSpy();

	BEHAVIOUR_STATUS Update();
};