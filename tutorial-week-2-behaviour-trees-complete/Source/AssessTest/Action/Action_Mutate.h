#pragma once

// Includes
#include "CoreMinimal.h"
#include "Node.h"

// Mutate class
class ASSESSTEST_API Action_Mutate : public Node
{
public:
	Action_Mutate(AAIAgent* a_pOwner);
	~Action_Mutate();

	BEHAVIOUR_STATUS Update();

private:
	UMaterialInstanceDynamic* m_pDynamicMaterial;
};