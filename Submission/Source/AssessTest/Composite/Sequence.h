#pragma once

////////////////////////////////////////////////////////////
// File:  <Sequence.h>
// Author:  <Zak Waters>  
// Date Created: <05/11/2019> 
// Brief:  <header file for the sequence part of a behaviour tree> 
////////////////////////////////////////////////////////////

// Includes
#include "CoreMinimal.h"
#include "Composite.h"

class ASSESSTEST_API Sequence : public Composite
{
public:
	Sequence(AAIAgent* a_pOwner);
	~Sequence();

	virtual BEHAVIOUR_STATUS Update();
};
