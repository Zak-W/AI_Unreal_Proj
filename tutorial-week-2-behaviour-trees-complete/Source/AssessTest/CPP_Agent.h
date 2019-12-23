// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPP_Agent.generated.h" // IMPORTANT - This has to go at the end of the includes!!!

// Forward declarations
class Behaviour;

UCLASS()
class ASSESSTEST_API ACPP_Agent : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_Agent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool GetInfectedStatus();
	void SetInfectedStatus(bool a_bTrue);

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	Behaviour* m_pCurrentBehaviour;
	// create trigger capsule
	UPROPERTY(EditAnywhere, Category = "Trigger Capsule")
		class UCapsuleComponent* m_pTriggerCapsule;
	UPROPERTY(EditAnywhere)
		bool m_bInfected = false;//Tells us whether the agent is infected or not
};
