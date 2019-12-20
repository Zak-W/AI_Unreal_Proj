// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_Agent.h"
#include "Behaviours/Behaviour.h"
#include "Behaviours/Wander.h"
#include "Behaviours/Chase.h"
#include "Engine/Classes/Components/CapsuleComponent.h"

// Sets default values
ACPP_Agent::ACPP_Agent()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_pTriggerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("BoxOverlapThingy"));
	m_pTriggerCapsule->InitCapsuleSize(55.f, 96.0f);;
	m_pTriggerCapsule->SetCollisionProfileName(TEXT("Trigger"));
	m_pTriggerCapsule->SetupAttachment(RootComponent);
	m_pTriggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &ACPP_Agent::OnOverlapBegin);
}

// Called when the game starts or when spawned
void ACPP_Agent::BeginPlay()
{
	Super::BeginPlay();

	m_pCurrentBehaviour = new Wander(this);
}

// Called every frame
void ACPP_Agent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_pCurrentBehaviour)
	{
		Behaviour* pNewBehaviour = m_pCurrentBehaviour->CheckConditions();
		if (pNewBehaviour)
		{
			delete m_pCurrentBehaviour;

			m_pCurrentBehaviour = pNewBehaviour;
		}

		m_pCurrentBehaviour->Update();
	}
}

// Called to bind functionality to input
void ACPP_Agent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

bool ACPP_Agent::GetInfectedStatus()
{
	return m_bInfected;
}

void ACPP_Agent::SetInfectedStatus(bool a_bTrue)
{
	m_bInfected = a_bTrue;
}

void ACPP_Agent::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ACPP_Agent* pOtherAgent = Cast<ACPP_Agent>(OtherActor);
		if (pOtherAgent && pOtherAgent->GetInfectedStatus())
		{
			SetInfectedStatus(true);
		}
	}
}