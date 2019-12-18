// This file's header
#include "Composite.h"

// Typedefs
typedef Node PARENT;

Composite::Composite(AAIAgent* a_pOwner) : PARENT(a_pOwner)
{
	m_iCurrentIndex = 0;
}

void Composite::AddChild(Node* a_pNode)
{
	m_aChildNodes.Push(a_pNode);
}

const TArray<Node*>& Composite::GetChildNodes()
{
	return m_aChildNodes;
}

void Composite::Initialise()
{
	m_iCurrentIndex = 0;
	// Initialise vector??
}

void Composite::Reset()
{
	m_iCurrentIndex = 0;
}
