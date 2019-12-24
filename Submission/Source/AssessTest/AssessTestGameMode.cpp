// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "AssessTestGameMode.h"
#include "AssessTestPlayerController.h"
#include "AssessTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAssessTestGameMode::AAssessTestGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AAssessTestPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}