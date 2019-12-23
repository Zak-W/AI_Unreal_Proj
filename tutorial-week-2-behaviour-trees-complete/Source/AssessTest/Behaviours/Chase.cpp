#include "Chase.h"
#include "CPP_Agent.h"
#include "AIController.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/Classes/Components/SkeletalMeshComponent.h"
#include "Classes/Blueprint/AIBlueprintHelperLibrary.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "Behaviours/Wander.h"
#include "AIAgent.h"

Chase::Chase(ACPP_Agent* pOwner) : Behaviour(pOwner)
{
	m_eCurrentChaseState = FIND_NEAREST_TARGET;
}

void Chase::Update()
{
	switch (m_eCurrentChaseState)
	{
	case FIND_NEAREST_TARGET:
	{
		TArray<AActor*> aFoundAgents;//To store list of all agents
		UGameplayStatics::GetAllActorsOfClass(GetOwner()->GetWorld(), ACPP_Agent::StaticClass(), aFoundAgents);//Get All agents

		float fClosestDistance = 1000000.0f;//Max distance to compare to
		m_pTargetActor = nullptr;//Reset target actor

		for (AActor* a_Actor : aFoundAgents)//Loop through actor list
		{
			if (a_Actor)//Null check
			{
				if (a_Actor->ActorHasTag("Spy"))//Check if Actor is Spy
				{
					float fThisDistance = FVector::Dist(GetOwner()->GetActorLocation(), a_Actor->GetActorLocation());//Get distance between two actors

					if (fThisDistance <= fClosestDistance)//If closer than last actor
					{
						m_pTargetActor = a_Actor;//Set new target
						fClosestDistance = fThisDistance;//New closest distance
					}
				}
			}
		}

		m_eCurrentChaseState = MOVE_TO_TARGET;
		break;
	}
	case MOVE_TO_TARGET:
	{
		AAIController* pAIController = Cast<AAIController>(GetOwner()->GetController());
		if (pAIController)
		{
			UAIBlueprintHelperLibrary::SimpleMoveToActor(pAIController, m_pTargetActor);//Move to target actor

			if (m_pTargetActor)//Null check
			{
				if (FVector::Dist(GetOwner()->GetActorLocation(), m_pTargetActor->GetActorLocation()) <= 100.0f)//Seeker is in range
				{
					m_eCurrentChaseState = BROADCAST_ALARM;
				}
			}
			else
			{
				m_eCurrentChaseState = FIND_NEAREST_TARGET; //Find new target
			}
		}

		break;
	}
	case BROADCAST_ALARM:
	{
		TArray<AActor*> aFoundAgents;//To store list of all agents
		UGameplayStatics::GetAllActorsOfClass(GetOwner()->GetWorld(), ACPP_Agent::StaticClass(), aFoundAgents);//Get All agents

		for (AActor* a_Actor : aFoundAgents)//Loop through actor list
		{
			if (a_Actor)//Null check
			{
				if (a_Actor->ActorHasTag("Guard"))//Check if Actor is Spy
				{
					float fThisDistance = FVector::Dist(GetOwner()->GetActorLocation(), a_Actor->GetActorLocation());//Get distance between two actors

					if (fThisDistance <= mfBroadcastRange)//If closer than last broadcast range
					{
						AAIAgent* pAgent = Cast<AAIAgent>(a_Actor);
						pAgent->SetPatrolCentre(GetOwner()->GetActorLocation());
					}
				}
			}
		}

		m_eCurrentChaseState = FIND_NEAREST_TARGET;
		break;
	}
	}
}

Behaviour* Chase::CheckConditions()
{
	//if cant see spy, return to wander.
	if (GetOwner()->GetCanSeeSpy() == false)
	{
		return new Wander(GetOwner());
	}
	return nullptr;
}