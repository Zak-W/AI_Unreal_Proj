#pragma once
////////////////////////////////////////////////////////////
// File:  <Action_FindPatrolLocation.h>
// Author:  <Zak Waters>  
// Date Created: <15/12/2019> 
// Brief:  <header file for moving to a point within a patrol radius> 
////////////////////////////////////////////////////////////
// Includes
#include "CoreMinimal.h"
#include "Node.h"

// Mutate class
class ASSESSTEST_API Action_FindPatrolLocation : public Node
{
public:
	Action_FindPatrolLocation(AAIAgent* a_pOwner);
	~Action_FindPatrolLocation();

	BEHAVIOUR_STATUS Update();

private:

	float m_fPatrolRadius = 1000.0f;
};