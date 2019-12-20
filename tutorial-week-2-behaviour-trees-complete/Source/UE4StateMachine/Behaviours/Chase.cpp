#include "Chase.h"
#include "CPP_Agent.h"
#include "AIController.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/Classes/Components/SkeletalMeshComponent.h"
#include "Classes/Blueprint/AIBlueprintHelperLibrary.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"

Chase::Chase(ACPP_Agent* pOwner) : Behaviour(pOwner)
{
	m_eCurrentChaseState = MUTATE;

	// Create a dynamic material so we can change the colour later
	CreateDynamicMaterial(pOwner);
}

void Chase::Update()
{
	switch (m_eCurrentChaseState)
	{
	case MUTATE:
	{
		// TODO - Change colour gradually over time then when at full, progress to FIND_NEAREST_TARGET
		m_pDynamicMaterial->SetVectorParameterValue("BodyColor", FLinearColor(1.0f, 0.0f, 0.0f));

		m_eCurrentChaseState = FIND_NEAREST_TARGET;
	}
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
				if (Cast<ACPP_Agent>(a_Actor) != GetOwner() && Cast<ACPP_Agent>(a_Actor)->GetInfectedStatus() == false)//Check current loop actor is not self and not already infected
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
				if (FVector::Dist(GetOwner()->GetActorLocation(), m_pTargetActor->GetActorLocation()) <= 100.0f)//If actor is close enough to target to bite them
				{
					m_eCurrentChaseState = FIND_NEAREST_TARGET;
				}

				if (Cast<ACPP_Agent>(m_pTargetActor)->GetInfectedStatus())//If target has recently been infected
				{
					m_eCurrentChaseState = FIND_NEAREST_TARGET;//Find new target
				}
			}
			else
			{
				m_eCurrentChaseState = FIND_NEAREST_TARGET; //Find new target
			}
		}

		break;
	}
	}
}

Behaviour* Chase::CheckConditions()
{
	// TODO - Check if we bit our target, if we have then die.

	return nullptr;
}

void Chase::CreateDynamicMaterial(ACPP_Agent* pOwner)
{
	if (pOwner)
	{
		USkeletalMeshComponent* pMesh = pOwner->GetMesh();
		if (pMesh)
		{
			UMaterialInterface* pMaterial = pMesh->GetMaterial(0);
			if (pMaterial)
			{
				m_pDynamicMaterial = UMaterialInstanceDynamic::Create(pMaterial, GetOwner());
				pMesh->SetMaterial(0, m_pDynamicMaterial);
			}
		}
	}
}