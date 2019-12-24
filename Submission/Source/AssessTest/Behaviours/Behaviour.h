#pragma once
////////////////////////////////////////////////////////////
// File:  <Behaviour.h>
// Author:  <Zak Waters>  
// Date Created: <05/11/2019> 
// Brief:  <defining statemachine behaviours> 
////////////////////////////////////////////////////////////
#include "CPP_Agent.h"

class Behaviour
{
public:
	Behaviour(ACPP_Agent* pOwner) { m_pOwner = pOwner; }
	virtual ~Behaviour() {};

	virtual void Update() = 0;
	virtual Behaviour* CheckConditions() = 0;

	ACPP_Agent* GetOwner() { return m_pOwner; }

private:
	ACPP_Agent* m_pOwner;
};