#pragma once

// Includes
#include "CoreMinimal.h"
#include "Node.h"
#include <vector>

// Composite class
class ASSESSTEST_API Composite : public Node
{
public:
	Composite(AAIAgent* a_pOwner);
	~Composite() {};

	void AddChild(Node* a_pNode);
	const TArray<Node*>& GetChildNodes();

protected:
	void Initialise();
	void Reset();

	int m_iCurrentIndex;

private:
	TArray<Node*> m_aChildNodes;
};
