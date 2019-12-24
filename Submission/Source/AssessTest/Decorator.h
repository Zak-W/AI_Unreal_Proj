////////////////////////////////////////////////////////////
// File:  <Decorator.h>
// Author:  <Zak Waters>  
// Date Created: <05/12/2019> 
// Brief:  <header file for altering behaviour outputs> 
////////////////////////////////////////////////////////////
#pragma once

// Includes
#include "CoreMinimal.h"
#include "Node.h"

// Typedef
typedef Node PARENT;

class ASSESSTEST_API Decorator : public Node
{
public:
	Decorator(AAIAgent* a_pOwner) : PARENT(a_pOwner) {};

	virtual BEHAVIOUR_STATUS Update() = 0;

	void SetChildNode(Node* a_pChildNode) { m_pChildNode = a_pChildNode; }
	Node* GetChildNode() { return m_pChildNode; }

private:
	Node* m_pChildNode;
};
