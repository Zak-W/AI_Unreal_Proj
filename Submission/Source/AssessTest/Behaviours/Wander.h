#pragma once
////////////////////////////////////////////////////////////
// File:  <Wander.h>
// Author:  <Zak Waters>  
// Date Created: <05/11/2019> 
// Brief:  <header file for wandering in a state machine> 
////////////////////////////////////////////////////////////
#include "Behaviour.h"

class ACPP_Agent;

enum WANDER_STATE
{
	FIND_RANDOM_POSITION,
	START_MOVE_TO,
	MOVING,
};

class Wander : public Behaviour
{
public:
	Wander(ACPP_Agent* pOwner);
	~Wander() {};

	void Update();
	Behaviour* CheckConditions();

private:
	WANDER_STATE m_eCurrentWanderState;
};