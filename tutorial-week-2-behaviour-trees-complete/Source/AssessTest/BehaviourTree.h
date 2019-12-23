#pragma once

// Includes
#include "CoreMinimal.h"

// Forward declarations
class AAIAgent;
class Selector;
class Sequence;
class Condition_HaveIArrived;
class Condition_CanISeeSpy;
class Condition_CanISeeGuard;
class Condition_CanISeeGoal;
class Action_FindNearestTarget;
class Action_MoveToTarget;
class Action_FindRandomPosition;
class Decorator_Inverter;
class Action_FindPatrolLocation;
class Action_FindNearestGuard;
class Action_FleeFromGuard;
class Action_ChaseSpy;

// BehaviourTree class
class ASSESSTEST_API BehaviourTree
{
public:
	BehaviourTree(AAIAgent* a_pOwnerAgent);
	~BehaviourTree() {}

	void Update();

private:
	Selector* m_pRootSelector;
	Sequence* m_pGuardSequence;
	Condition_HaveIArrived* m_pHaveIArrived;
	Action_FindNearestTarget* m_pFindNearestTarget;
	Action_MoveToTarget* m_pMovetoTarget;
	Sequence* m_pSpySequence;
	Action_FindRandomPosition* m_pFindRandomPosition;
	Decorator_Inverter* m_pInverter;
	Selector* m_pGuardSelector;
	Action_FindPatrolLocation* m_pFindPatrol;

};
