#pragma once

#include "CoreMinimal.h"
#include "Node.h"

class AAIAgent;
class AIPerception;
class AActor;
class FAIStimulus;

class ASSESSTEST_API Condition_CanISeeGuard : public Node
{

public:
	Condition_CanISeeGuard(AAIAgent* a_pOwner);
	~Condition_CanISeeGuard();

	virtual BEHAVIOUR_STATUS Update();
	
	UAIPerceptionComponent* m_pAIPerceptionComponent;
	bool m_bCanSee;

	void HasSensedObject(AActor* UpdatedActor, FAIStimulus Stimulus);
};
