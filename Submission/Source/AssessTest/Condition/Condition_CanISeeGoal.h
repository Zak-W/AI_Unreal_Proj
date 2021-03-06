////////////////////////////////////////////////////////////
// File:  <Condition_CanISeeGoal.h>
// Author:  <Zak Waters>  
// Date Created: <05/12/2019> 
// Brief:  <header file for seeing the end goal for the spy> 
////////////////////////////////////////////////////////////
#pragma once

#include "CoreMinimal.h"
#include "Node.h"

class AAIAgent;
class AActor;
struct FAIStimulus;
class UAIPerceptionComponent;

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
