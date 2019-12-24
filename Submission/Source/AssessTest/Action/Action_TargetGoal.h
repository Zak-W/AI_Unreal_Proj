#pragma once
////////////////////////////////////////////////////////////
// File:  <Action_TargetGoal.h>
// Author:  <Zak Waters>  
// Date Created: <20/12/2019> 
// Brief:  <Code for moving toward the goal> 
////////////////////////////////////////////////////////////
// Includes
#include "CoreMinimal.h"
#include "Node.h"

class ASSESSTEST_API Action_TargetGoal : public Node
{
public:
	Action_TargetGoal(AAIAgent* a_pOwner);
	~Action_TargetGoal();

	BEHAVIOUR_STATUS Update();
};