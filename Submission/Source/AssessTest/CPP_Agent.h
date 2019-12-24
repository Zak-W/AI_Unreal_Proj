////////////////////////////////////////////////////////////
// File:  <CPP_Agent.h>
// Author:  <Zak Waters>  
// Date Created: <05/12/2019> 
// Brief:  <header file for making a Finite State Machine AI> 
////////////////////////////////////////////////////////////

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

	bool GetCanSeeSpy() { return mbCanSeeSpy; }

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	Behaviour* m_pCurrentBehaviour;
	// create trigger capsule
	UPROPERTY(EditAnywhere, Category = "Trigger Capsule")
		class UCapsuleComponent* m_pTriggerCapsule;
	bool mbCanSeeSpy;
};
