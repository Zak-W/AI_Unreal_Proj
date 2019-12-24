////////////////////////////////////////////////////////////
// File:  <BehaviourTree.h>
// Author:  <Zak Waters>  
// Date Created: <05/12/2019> 
// Brief:  <header file for creating a behaviour tree> 
////////////////////////////////////////////////////////////
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
class Action_TargetGoal;
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
	Sequence* m_pGuardSequencePatrol;
	Sequence* m_pGuardSequenceChase;
	Selector* m_pGuardBehaviourSelector;
	Sequence* m_pSpySequenceWander;
	Sequence* m_pSpySequenceFlee;
	Sequence* m_pSpySequenceSeek;
	Selector* m_pSpyBehaviourSelectorFlee;
	Selector* m_pSpyBehaviourSelectorSeek;
	Decorator_Inverter* m_pInverter;
	Condition_HaveIArrived* m_pHaveIArrived;
	Condition_CanISeeSpy* m_pCanSeeSpy;
	Condition_CanISeeGuard* m_pCanSeeGuard;
	Condition_CanISeeGoal* m_pCanSeeGoal;
	Action_FindNearestTarget* m_pFindNearestTarget;
	Action_MoveToTarget* m_pMovetoTarget;
	Action_FindPatrolLocation* m_pFindPatrol;
	Action_FindNearestGuard* m_pFindGuard;
	Action_TargetGoal* m_pTargetGoal;
	Action_FleeFromGuard* m_pFleeGuard;
	Action_ChaseSpy* m_pChaseSpy;
	Action_FindRandomPosition* m_pFindRandomPosition;

};
