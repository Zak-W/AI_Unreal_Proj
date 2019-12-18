#pragma once

// Includes
#include "CoreMinimal.h"

// Forward declarations
class AAIAgent;
class Selector;
class Sequence;
class Condition_AmIInfected;
class Condition_WasIBitten;
class Condition_HaveIArrived;
class Action_FindNearestTarget;
class Action_MoveToTarget;
class Action_FindRandomPosition;
class Action_BiteActor;
class Action_Mutate;
class Decorator_Inverter;
class Action_FindPatrolLocation;

// BehaviourTree class
class ASSESSTEST_API BehaviourTree
{
public:
	BehaviourTree(AAIAgent* a_pOwnerAgent);
	~BehaviourTree() {}

	void Update();

private:
	Selector* m_pRootSelector;
	Sequence* m_pInfectedSequence;
	Condition_AmIInfected* m_pAmIInfected;
	Condition_WasIBitten* m_pWasIBitten;
	Condition_HaveIArrived* m_pHaveIArrived;
	Action_FindNearestTarget* m_pFindNearestTarget;
	Action_MoveToTarget* m_pMovetoTarget;
	Sequence* m_pHealthySequence;
	Action_FindRandomPosition* m_pFindRandomPosition;
	Action_Mutate* m_pMutate;
	Action_BiteActor* m_pBiteActor;
	Decorator_Inverter* m_pInverter;
	Selector* m_pHumanSelector;
	Sequence* m_pMutateSequence;
	Action_FindPatrolLocation* m_pFindPatrol;

};
