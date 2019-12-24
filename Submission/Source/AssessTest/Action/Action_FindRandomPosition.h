#pragma once
////////////////////////////////////////////////////////////
// File:  <Action_FindRandomPosition.h>
// Author:  <Zak Waters>  
// Date Created: <05/11/2019> 
// Brief:  <header file for moving to a random position> 
////////////////////////////////////////////////////////////
// Includes
#include "CoreMinimal.h"
#include "Node.h"

// Mutate class
class ASSESSTEST_API Action_FindRandomPosition : public Node
{
public:
	Action_FindRandomPosition(AAIAgent* a_pOwner);
	~Action_FindRandomPosition();

	BEHAVIOUR_STATUS Update();

private:
};