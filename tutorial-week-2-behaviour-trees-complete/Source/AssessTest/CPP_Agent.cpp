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
	m_pTriggerCapsule->InitCapsuleSize(300.f, 200.0f);;
	m_pTriggerCapsule->SetCollisionProfileName(TEXT("Trigger"));
	m_pTriggerCapsule->SetupAttachment(RootComponent);
	m_pTriggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &ACPP_Agent::OnOverlapBegin);
	mbCanSeeSpy = false;
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

void ACPP_Agent::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Spy"))
	{
		mbCanSeeSpy = true;
	}
}