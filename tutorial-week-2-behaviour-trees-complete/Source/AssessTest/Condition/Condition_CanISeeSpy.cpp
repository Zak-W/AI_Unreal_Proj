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
	AAIController* pAIController = Cast<AAIController>(GetOwner());
	if (pAIController)//Null check
	{
  		m_pAIPerceptionComponent = pAIController->GetPerceptionComponent();
	}
}

Condition_CanISeeSpy::~Condition_CanISeeSpy()
{
}

BEHAVIOUR_STATUS Condition_CanISeeSpy::Update()
{
	m_bCanSee = false;
	m_pAIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &Condition_CanISeeSpy::HasSensedObject);
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
