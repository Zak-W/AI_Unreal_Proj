// This file's header
#include "BehaviourTree.h"

// Includes
#include "Composite/Selector.h"
#include "Composite/Sequence.h"
#include "Condition/Condition_AmIInfected.h"
#include "Condition/Condition_WasIBitten.h"
#include "Condition/Condition_HaveIArrived.h"
#include "Action/Action_FindNearestTarget.h"
#include "Action/Action_MoveToTarget.h"
#include "Action/Action_FindRandomPosition.h"
#include "Action/Action_FindPatrolLocation.h"
#include "Action/Action_Mutate.h"
#include "Action/Action_BiteActor.h"
#include "Decorator/Decorator_Inverter.h"

BehaviourTree::BehaviourTree(AAIAgent* a_pOwnerAgent)
{
	// Create all nodes
	m_pRootSelector = new Selector(a_pOwnerAgent);
	m_pInfectedSequence = new Sequence(a_pOwnerAgent);
	m_pHumanSelector = new Selector(a_pOwnerAgent);

	m_pAmIInfected = new Condition_AmIInfected(a_pOwnerAgent);
	m_pFindNearestTarget = new Action_FindNearestTarget(a_pOwnerAgent);
	m_pMovetoTarget = new Action_MoveToTarget(a_pOwnerAgent);
	m_pBiteActor = new Action_BiteActor(a_pOwnerAgent);
	m_pFindPatrol = new Action_FindPatrolLocation(a_pOwnerAgent);
	m_pHaveIArrived = new Condition_HaveIArrived(a_pOwnerAgent);

	m_pHealthySequence = new Sequence(a_pOwnerAgent);
	m_pFindRandomPosition = new Action_FindRandomPosition(a_pOwnerAgent);

	m_pMutateSequence = new Sequence(a_pOwnerAgent);

	m_pWasIBitten = new Condition_WasIBitten(a_pOwnerAgent);
	m_pMutate = new Action_Mutate(a_pOwnerAgent);
	m_pInverter = new Decorator_Inverter(a_pOwnerAgent);

	// Top level selector
	//m_pRootSelector->AddChild(m_pMutateSequence);

	//m_pRootSelector->AddChild(m_pInfectedSequence);

	m_pRootSelector->AddChild(m_pHumanSelector);

	//// Infected sequence
	//m_pInfectedSequence->AddChild(m_pAmIInfected);
	//m_pInfectedSequence->AddChild(m_pFindNearestTarget);
	//m_pInfectedSequence->AddChild(m_pMovetoTarget);
	//m_pInfectedSequence->AddChild(m_pBiteActor);
	//// Selector to link sequences
	////m_pHumanSelector->AddChild(m_pMutateSequence);
	m_pHumanSelector->AddChild(m_pHealthySequence);

	// healthy sequence
	//m_pHealthySequence->AddChild(m_pHaveIArrived);
	//m_pHealthySequence->AddChild(m_pFindRandomPosition);
	m_pHealthySequence->AddChild(m_pFindPatrol);
	m_pHealthySequence->AddChild(m_pMovetoTarget);


	//// Mutate sequence
	//m_pMutateSequence->AddChild(m_pWasIBitten); // TODO
	//m_pMutateSequence->AddChild(m_pMutate);
}

void BehaviourTree::Update()
{
	m_pRootSelector->Update();
}
