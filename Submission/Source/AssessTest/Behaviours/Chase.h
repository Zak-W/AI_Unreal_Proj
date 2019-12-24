#pragma once
////////////////////////////////////////////////////////////
// File:  <Chase.h>
// Author:  <Zak Waters>  
// Date Created: <05/11/2019> 
// Brief:  <header file for chasing as a state in a state machine> 
////////////////////////////////////////////////////////////
#include "Behaviour.h"

class ACPP_Agent;
class AAIAgent;

enum CHASE_STATE
{
	FIND_NEAREST_TARGET,
	MOVE_TO_TARGET,
	BROADCAST_ALARM
};

class Chase : public Behaviour
{
public:
	Chase(ACPP_Agent* pOwner);
	~Chase() {};

	void Update();
	Behaviour* CheckConditions();

private:

	CHASE_STATE m_eCurrentChaseState;
	UMaterialInstanceDynamic* m_pDynamicMaterial;

	float mfBroadcastRange = 900.0f; // max broadcast distance

	AActor* m_pTargetActor;//Stores the actor that we are chasing
};