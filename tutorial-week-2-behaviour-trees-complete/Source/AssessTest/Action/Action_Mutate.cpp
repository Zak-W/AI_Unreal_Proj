// This file's header
#include "Action_Mutate.h"

// Includes
#include "AIAgent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/Classes/Components/SkeletalMeshComponent.h"
#include "AIController.h"

// Constants
const float fCOLOUR_CHANGE_RATE = 0.1f;

// Typedef
typedef Node PARENT;

Action_Mutate::Action_Mutate(AAIAgent* a_pOwner) : PARENT(a_pOwner)
									, m_pDynamicMaterial(nullptr)
{
	AAIAgent* pOwner = GetOwner();
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

Action_Mutate::~Action_Mutate()
{
}

BEHAVIOUR_STATUS Action_Mutate::Update()
{
	if (m_pDynamicMaterial)
	{
		AAIController* pAIController = Cast<AAIController>(GetOwner()->GetController());
		if (pAIController)
		{
			pAIController->StopMovement();
		}

		// Get the existing colour from our dynamic macterial
		FLinearColor xCurrentColour;
		m_pDynamicMaterial->GetVectorParameterValue(FMaterialParameterInfo("BodyColor"), xCurrentColour);

		// Add a little something to our green channel
		float fRed = xCurrentColour.R - fCOLOUR_CHANGE_RATE;
		float fGreen = xCurrentColour.G + fCOLOUR_CHANGE_RATE;
		float fBlue = xCurrentColour.B - fCOLOUR_CHANGE_RATE;

		if (fGreen >= 1.0f)
		{
			Cast<AAIAgent>(GetOwner())->SetMutated();
			return SUCCESS;
		}
		else
		{
			m_pDynamicMaterial->SetVectorParameterValue("BodyColor", FLinearColor(fRed, fGreen, fBlue));
			return RUNNING;
		}
		

	}

	// Error
	return NONE;
}