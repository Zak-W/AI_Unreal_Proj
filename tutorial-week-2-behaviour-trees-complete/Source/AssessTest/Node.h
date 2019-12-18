#pragma once

// Includes
#include "CoreMinimal.h"

// Forward declarations
class AAIAgent;

//namespace EBehaviourStatus
//{
//	enum Type
//	{
//		SUCCESS,
//		FAILURE,
//		RUNNING,
//		NONE
//	};
//}

// Enums
enum BEHAVIOUR_STATUS
{
	SUCCESS,
	FAILURE,
	RUNNING,
	NONE
};

// Node Class
class ASSESSTEST_API Node
{
public:
	Node(AAIAgent* a_pOwner) : m_eCurrentBehaviourStatus(NONE), m_pOwnerAgent(a_pOwner) {}
	virtual ~Node() {};

	virtual BEHAVIOUR_STATUS Update() = 0;

	AAIAgent* GetOwner() { return m_pOwnerAgent; }	

private:
	BEHAVIOUR_STATUS m_eCurrentBehaviourStatus;
	AAIAgent* m_pOwnerAgent;
};
