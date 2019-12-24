////////////////////////////////////////////////////////////
// File:  <Condition_HaveIArrived.h>
// Author:  <Zak Waters>  
// Date Created: <05/11/2019> 
// Brief:  <header file for checking if the character has arrived>
////////////////////////////////////////////////////////////

#pragma once

#include "CoreMinimal.h"
#include "Node.h"

// Forward declarations
class AAIAgent;


class ASSESSTEST_API Condition_HaveIArrived: public Node
{
public:
	Condition_HaveIArrived(AAIAgent* a_pOwner);
	~Condition_HaveIArrived();

	virtual BEHAVIOUR_STATUS Update();
};
