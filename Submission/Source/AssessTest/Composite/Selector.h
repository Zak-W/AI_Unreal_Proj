#pragma once
////////////////////////////////////////////////////////////
// File:  <Selector.h>
// Author:  <Zak Waters>  
// Date Created: <05/11/2019> 
// Brief:  <header file for the selector part of a behaviour tree> 
////////////////////////////////////////////////////////////
// Includes
#include "CoreMinimal.h"
#include "Composite.h"

// Class
class ASSESSTEST_API Selector : public Composite
{
public:
	Selector(AAIAgent* a_pOwner);
	~Selector();

	BEHAVIOUR_STATUS Update();
};
