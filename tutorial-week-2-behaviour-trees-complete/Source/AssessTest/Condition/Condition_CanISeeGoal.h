#pragma once

#include "CoreMinimal.h"
#include "Node.h"

class AAIAgent;
class AIPerception;
class AActor;
class FAIStimulus;

class ASSESSTEST_API Condition_CanISeeGoal : public Node
{

public:
	Condition_CanISeeGoal(AAIAgent* a_pOwner);
	~Condition_CanISeeGoal();

	virtual BEHAVIOUR_STATUS Update();
	
	UAIPerceptionComponent* m_pAIPerceptionComponent;
	bool m_bCanSee;

	void HasSensedObject(AActor* UpdatedActor, FAIStimulus Stimulus);
};
