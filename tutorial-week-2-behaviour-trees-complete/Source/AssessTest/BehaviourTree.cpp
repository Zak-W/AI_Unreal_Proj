// This file's header
#include "BehaviourTree.h"

// Includes
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
#include "Action/Action_ChaseSpy.h"
#include "Action/Action_FindNearestGuard.h"
#include "Action/Action_FleeFromGuard.h"
#include "Decorator/Decorator_Inverter.h"

BehaviourTree::BehaviourTree(AAIAgent* a_pOwnerAgent)
{
	// Create all nodes
	m_pRootSelector = new Selector(a_pOwnerAgent);
	m_pGuardSequence = new Sequence(a_pOwnerAgent);
	m_pGuardSelector = new Selector(a_pOwnerAgent);

	m_pFindNearestTarget = new Action_FindNearestTarget(a_pOwnerAgent);
	m_pMovetoTarget = new Action_MoveToTarget(a_pOwnerAgent);
	m_pFindPatrol = new Action_FindPatrolLocation(a_pOwnerAgent);
	m_pHaveIArrived = new Condition_HaveIArrived(a_pOwnerAgent);

	m_pSpySequence = new Sequence(a_pOwnerAgent);
	m_pFindRandomPosition = new Action_FindRandomPosition(a_pOwnerAgent);

	m_pInverter = new Decorator_Inverter(a_pOwnerAgent);

	// Top level selector
	/*m_pRootSelector->AddChild(m_pGuardSequence);*/

	m_pRootSelector->AddChild(m_pGuardSelector);

	//// Infected sequence
	//m_pInfectedSequence->AddChild(m_pAmIInfected);
	//m_pInfectedSequence->AddChild(m_pFindNearestTarget);
	//m_pInfectedSequence->AddChild(m_pMovetoTarget);
	//m_pInfectedSequence->AddChild(m_pBiteActor);
	//// Selector to link sequences
	////m_pHumanSelector->AddChild(m_pMutateSequence);
	m_pGuardSelector->AddChild(m_pSpySequence);

	// Spy sequence
	//m_pHealthySequence->AddChild(m_pHaveIArrived);
	m_pSpySequence->AddChild(m_pFindRandomPosition);
	m_pSpySequence->AddChild(m_pMovetoTarget);

}

void BehaviourTree::Update()
{
	m_pRootSelector->Update();
}
