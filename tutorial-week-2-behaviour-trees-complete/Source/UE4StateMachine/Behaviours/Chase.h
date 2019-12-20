#pragma once

#include "Behaviour.h"

class ACPP_Agent;

enum CHASE_STATE
{
	MUTATE,
	FIND_NEAREST_TARGET,
	MOVE_TO_TARGET
};

class Chase : public Behaviour
{
public:
	Chase(ACPP_Agent* pOwner);
	~Chase() {};

	void Update();
	Behaviour* CheckConditions();

private:
	void CreateDynamicMaterial(ACPP_Agent* pOwner);

	CHASE_STATE m_eCurrentChaseState;
	UMaterialInstanceDynamic* m_pDynamicMaterial;

	AActor* m_pTargetActor;//Stores the actor that we are chasing
};