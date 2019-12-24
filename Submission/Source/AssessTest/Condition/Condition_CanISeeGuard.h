#pragma once
////////////////////////////////////////////////////////////
// File:  <Condition_CanISeeGuard.h>
// Author:  <Zak Waters>  
// Date Created: <05/12/2019> 
// Brief:  <header file for seeing a enemy guard> 
////////////////////////////////////////////////////////////
#include "CoreMinimal.h"
#include "Node.h"

class AAIAgent;
class AActor;
struct FAIStimulus;
class UAIPerceptionComponent;

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
