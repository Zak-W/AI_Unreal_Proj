// This file's header
#include "Action_ChaseSpy.h"

// Includes
#include "AIAgent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/Classes/Components/SkeletalMeshComponent.h"
#include "AIController.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/World.h"

// Typedef
typedef Node PARENT;

Action_ChaseSpy::Action_ChaseSpy(AAIAgent * a_pOwner) : PARENT(a_pOwner)
{
}

Action_ChaseSpy::~Action_ChaseSpy()
{
}

BEHAVIOUR_STATUS Action_ChaseSpy::Update()
{
	// Null check
	if (!GetOwner())
	{
		return FAILURE; // Early out
	}

	// Get all actors of type "AAIAgent"
	TArray<AActor*> aFoundAgents;
	UGameplayStatics::GetAllActorsOfClass(GetOwner()->GetWorld(), AAIAgent::StaticClass(), aFoundAgents);

	//to fix initialised variable - get self
	AActor* pTarget = Cast<AActor>(GetOwner());

	for (int i = 0; i < aFoundAgents.Num(); ++i)
	{
		// Get Spy Actor
		if (aFoundAgents[i]->ActorHasTag("Spy"))
		{
			pTarget = aFoundAgents[i];
		}
	}

	//if it did find the spy
	if (pTarget->ActorHasTag("Spy"))
	{
		GetOwner()->SetTargetActor(pTarget);
		return SUCCESS;
	}
	else
	{
		return FAILURE;
	}
}
