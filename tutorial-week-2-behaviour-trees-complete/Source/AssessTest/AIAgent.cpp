// This file's header
#include "AIAgent.h"

// Includes
#include "AIController.h"
#include "BehaviourTree.h"
#include "Engine/Classes/Components/CapsuleComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/Classes/Components/SkeletalMeshComponent.h"

// Sets default values
AAIAgent::AAIAgent()
{
	m_pTargetActor = nullptr;

	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a trigger capsule for use with our collision detection.
	m_pTriggerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Capsule"));
	m_pTriggerCapsule->InitCapsuleSize(55.f, 96.0f);;
	m_pTriggerCapsule->SetCollisionProfileName(TEXT("Trigger"));
	m_pTriggerCapsule->SetupAttachment(RootComponent);
	m_pTriggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &AAIAgent::OnOverlapBegin);

	m_fVPatrolCentre = GetActorLocation();
}

// Called when the game starts or when spawned
void AAIAgent::BeginPlay()
{
	Super::BeginPlay();
	if (m_bIsGuard)
	{
		USkeletalMeshComponent* pMesh = GetMesh();
		if (pMesh)
		{
			UMaterialInterface* pMaterial = pMesh->GetMaterial(0);
			if (pMaterial)
			{
				m_pDynamicMaterial = UMaterialInstanceDynamic::Create(pMaterial, GetOwner());
				pMesh->SetMaterial(0, m_pDynamicMaterial);

				// Get the existing colour from our dynamic macterial
				FLinearColor xCurrentColour;
				m_pDynamicMaterial->GetVectorParameterValue(FMaterialParameterInfo("BodyColor"), xCurrentColour);

				// Add a little something to our green channel
				float fRed = xCurrentColour.R + 1.0f;
				float fGreen = xCurrentColour.G - 1.0f;
				float fBlue = xCurrentColour.B - 1.0f;

				m_pDynamicMaterial->SetVectorParameterValue("BodyColor", FLinearColor(fRed, fGreen, fBlue));
			}
		}
	}
}

// Called every frame
void AAIAgent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	m_pBehaviourTree->Update();
}

// Called to bind functionality to input
void AAIAgent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AAIAgent::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	// Initialise our behaviour tree
	m_pBehaviourTree = new BehaviourTree(this);
}

void AAIAgent::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}