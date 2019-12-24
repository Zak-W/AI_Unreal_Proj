#pragma once

#pragma once

#include "CoreMinimal.h"
#include "Node.h"

class AAIAgent;
class AActor;
struct FAIStimulus;
class UAIPerceptionComponent;

class ASSESSTEST_API Condition_CanISeeSpy : public Node
{

public:
	Condition_CanISeeSpy(AAIAgent* a_pOwner);
	~Condition_CanISeeSpy();

	virtual BEHAVIOUR_STATUS Update();
	
	UAIPerceptionComponent* m_pAIPerceptionComponent;
	bool m_bCanSee;

	void HasSensedObject(AActor* UpdatedActor, FAIStimulus Stimulus);
};
