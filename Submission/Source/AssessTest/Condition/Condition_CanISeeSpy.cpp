#include "Condition_CanISeeSpy.h"

// Includes
#include "AIAgent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/Classes/Components/SkeletalMeshComponent.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "DrawDebugHelpers.h"

// Typedef
typedef Node PARENT;

Condition_CanISeeSpy::Condition_CanISeeSpy(AAIAgent * a_pOwner) : PARENT(a_pOwner)
{
	m_pAIPerceptionComponent = Cast<UAIPerceptionComponent>(GetOwner()->FindComponentByClass(UAIPerceptionComponent::StaticClass()));
}

Condition_CanISeeSpy::~Condition_CanISeeSpy()
{
}

BEHAVIOUR_STATUS Condition_CanISeeSpy::Update()
{
	m_bCanSee = false;
	TArray<AActor*> paSensedActors;
	m_pAIPerceptionComponent->GetCurrentlyPerceivedActors(nullptr, paSensedActors);
	for (int i = 0; i < paSensedActors.Num(); ++i)
	{
		AActor* pCurrentActor = paSensedActors[i];
		if (pCurrentActor->ActorHasTag("Spy"))
		{
			AAIAgent* pAgent = GetOwner();
			pAgent->SetPatrolCentre(pCurrentActor->GetActorLocation());
			m_bCanSee = true;
		}
	}
	//m_pAIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &Condition_CanISeeSpy::HasSensedObject);
	if (m_bCanSee)
	{
		return SUCCESS;
	}
	else
	{
		return FAILURE;
	}
}

void Condition_CanISeeSpy::HasSensedObject(AActor * UpdatedActor, FAIStimulus Stimulus)
{
	UE_LOG(LogTemp, Warning, TEXT("Successfully sensed!"));
	DrawDebugLine(GetOwner()->GetWorld(), GetOwner()->GetActorLocation(), UpdatedActor->GetActorLocation(), FColorList::Red, false, 0.1f);
	if (UpdatedActor->ActorHasTag("Spy") && UpdatedActor->GetUniqueID() != GetOwner()->GetUniqueID())
	{
		m_bCanSee = true;
	}
}
