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
	AAIController* pAIController = Cast<AAIController>(GetOwner());
	if (pAIController)//Null check
	{
  		m_pAIPerceptionComponent = pAIController->GetPerceptionComponent();
	}
}

Condition_CanISeeGuard::~Condition_CanISeeGuard()
{
}

BEHAVIOUR_STATUS Condition_CanISeeGuard::Update()
{
	m_bCanSee = false;
	m_pAIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &Condition_CanISeeGuard::HasSensedObject);
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
