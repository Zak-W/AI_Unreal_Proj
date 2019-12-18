#pragma once

// Includes
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AIAgent.generated.h"

// Forward declarations
class BehaviourTree;

// AAIAgent class
UCLASS()
class ASSESSTEST_API AAIAgent : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAIAgent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void PostInitializeComponents() override;

	// declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	AActor* GetTargetActor() { return m_pTargetActor; }
	void SetTargetActor(AActor* a_pTargetActor) { m_pTargetActor = a_pTargetActor; }

	bool IsInfected() { return m_bIsInfected; }
	void SetInfected() { m_bHasBeenBitten = true; }

	bool HasBeenBitten()
	{
		if (m_bHasBeenBitten && !m_bIsInfected)
		{
			return true;
		}
		return false;
	}

	void SetMutated() { m_bHasMutated = true; m_bIsInfected = true; m_bHasBeenBitten = false; }
	bool GetMutated() { return m_bHasMutated; }

	FVector Get_PatrolCentre() { return m_fVPatrolCentre; }

private:
	// create trigger capsule
	UPROPERTY(VisibleAnywhere, Category = "Trigger Capsule")
		class UCapsuleComponent* m_pTriggerCapsule;

	UPROPERTY(EditAnywhere, Category = "Zombie")
		bool m_bIsInfected;

	bool m_bHasBeenBitten;
	bool m_bHasMutated;

	BehaviourTree* m_pBehaviourTree;
	AActor* m_pTargetActor;
	FVector m_fVPatrolCentre;
};