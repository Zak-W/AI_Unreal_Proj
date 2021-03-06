#include "Condition_CanISeeGuard.h"

// Includes
#include "AIAgent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/Classes/Components/SkeletalMeshComponent.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "DrawDebugHelpers.h"

// Typedef
typedef Node PARENT;

Condition_CanISeeGuard::Condition_CanISeeGuard(AAIAgent * a_pOwner) : PARENT(a_pOwner)
{
	m_pAIPerceptionComponent = Cast<UAIPerceptionComponent>(GetOwner()->FindComponentByClass(UAIPerceptionComponent::StaticClass()));
}

Condition_CanISeeGuard::~Condition_CanISeeGuard()
{
}

BEHAVIOUR_STATUS Condition_CanISeeGuard::Update()
{
	m_bCanSee = false;
	TArray<AActor*> paSensedActors;
	m_pAIPerceptionComponent->GetCurrentlyPerceivedActors(nullptr, paSensedActors);
	for (int i = 0; i < paSensedActors.Num(); ++i)
	{
		AActor* pCurrentActor = paSensedActors[i];
		if (pCurrentActor->ActorHasTag("Guard") || pCurrentActor->ActorHasTag("Seeker"))
		{
			m_bCanSee = true;
		}
	}
	//m_pAIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &Condition_CanISeeGuard::HasSensedObject);
	if (m_bCanSee)
	{
		return SUCCESS;
	}
	else
	{
		return FAILURE;
	}
}

void Condition_CanISeeGuard::HasSensedObject(AActor * UpdatedActor, FAIStimulus Stimulus)
{
	UE_LOG(LogTemp, Warning, TEXT("Successfully sensed!"));
	DrawDebugLine(GetOwner()->GetWorld(), GetOwner()->GetActorLocation(), UpdatedActor->GetActorLocation(), FColorList::Red, false, 0.1f);
	if (UpdatedActor->ActorHasTag("Guard") && UpdatedActor->GetUniqueID() != GetOwner()->GetUniqueID())
	{
		m_bCanSee = true;
	}
}
