// This file's header
#include "BehaviourTree.h"

// Includes
#include "AIAgent.h"
#include "Composite/Selector.h"
#include "Composite/Sequence.h"
#include "Condition/Condition_HaveIArrived.h"
#include "Condition/Condition_CanISeeGoal.h"
#include "Condition/Condition_CanISeeGuard.h"
#include "Condition/Condition_CanISeeSpy.h"
#include "Action/Action_FindNearestTarget.h"
#include "Action/Action_MoveToTarget.h"
#include "Action/Action_FindRandomPosition.h"
#include "Action/Action_FindPatrolLocation.h"
#include "Action/Action_TargetGoal.h"
#include "Action/Action_ChaseSpy.h"
#include "Action/Action_FindNearestGuard.h"
#include "Action/Action_FleeFromGuard.h"
#include "Decorator/Decorator_Inverter.h"

BehaviourTree::BehaviourTree(AAIAgent* a_pOwnerAgent)
{
	// Create all nodes
	m_pRootSelector = new Selector(a_pOwnerAgent);

	m_pGuardSequencePatrol = new Sequence(a_pOwnerAgent);
	m_pGuardSequenceChase = new Sequence(a_pOwnerAgent);
	m_pGuardBehaviourSelector = new Selector(a_pOwnerAgent);

	m_pSpySequenceWander = new Sequence(a_pOwnerAgent);
	m_pSpySequenceFlee = new Sequence(a_pOwnerAgent);
	m_pSpySequenceSeek = new Sequence(a_pOwnerAgent);
	m_pSpyBehaviourSelectorFlee = new Selector(a_pOwnerAgent);
	m_pSpyBehaviourSelectorSeek = new Selector(a_pOwnerAgent);

	m_pHaveIArrived = new Condition_HaveIArrived(a_pOwnerAgent);

	m_pCanSeeSpy = new Condition_CanISeeSpy(a_pOwnerAgent);
	m_pCanSeeGuard = new Condition_CanISeeGuard(a_pOwnerAgent);
	m_pCanSeeGoal = new Condition_CanISeeGoal(a_pOwnerAgent);

	m_pFindNearestTarget = new Action_FindNearestTarget(a_pOwnerAgent);
	m_pMovetoTarget = new Action_MoveToTarget(a_pOwnerAgent);
	m_pFindPatrol = new Action_FindPatrolLocation(a_pOwnerAgent);

	m_pFindGuard = new Action_FindNearestGuard(a_pOwnerAgent);
	m_pTargetGoal = new Action_TargetGoal(a_pOwnerAgent);
	m_pFleeGuard = new Action_FleeFromGuard(a_pOwnerAgent);
	m_pChaseSpy = new Action_ChaseSpy(a_pOwnerAgent);
	m_pFindRandomPosition = new Action_FindRandomPosition(a_pOwnerAgent);

	m_pInverter = new Decorator_Inverter(a_pOwnerAgent);

	// Top level selectors
	AAIAgent* pAgent = Cast<AAIAgent>(a_pOwnerAgent);
	if (pAgent->GetIsGuard())
	{
		m_pRootSelector->AddChild(m_pGuardBehaviourSelector);
		m_pGuardBehaviourSelector->AddChild(m_pGuardSequenceChase);
		m_pGuardBehaviourSelector->AddChild(m_pGuardSequencePatrol);
	}
	else
	{
		m_pRootSelector->AddChild(m_pSpyBehaviourSelectorFlee);
		m_pSpyBehaviourSelectorFlee->AddChild(m_pSpyBehaviourSelectorSeek);
		m_pSpyBehaviourSelectorFlee->AddChild(m_pSpySequenceFlee);
		m_pSpyBehaviourSelectorSeek->AddChild(m_pSpySequenceSeek);
		m_pSpyBehaviourSelectorSeek->AddChild(m_pSpySequenceWander);
	}

	//Guard Patrol Sequence
	m_pGuardSequencePatrol->AddChild(m_pFindPatrol);
	m_pGuardSequencePatrol->AddChild(m_pMovetoTarget);

	//Spy Wander Sequence
	m_pSpySequenceWander->AddChild(m_pFindRandomPosition);
	m_pSpySequenceWander->AddChild(m_pMovetoTarget);

	//Guard Chase Sequence
	m_pGuardSequenceChase->AddChild(m_pCanSeeSpy);
	m_pGuardSequenceChase->AddChild(m_pChaseSpy);
	m_pGuardSequenceChase->AddChild(m_pMovetoTarget);

	//Spy Flee Sequence
	m_pSpySequenceFlee->AddChild(m_pCanSeeGuard);
	m_pSpySequenceFlee->AddChild(m_pFleeGuard);
	m_pSpySequenceFlee->AddChild(m_pMovetoTarget);

	//Spy Seek Sequence
	m_pSpySequenceSeek->AddChild(m_pCanSeeGoal);
	m_pSpySequenceSeek->AddChild(m_pTargetGoal);
	m_pSpySequenceSeek->AddChild(m_pMovetoTarget);

}

void BehaviourTree::Update()
{
	m_pRootSelector->Update();
}
