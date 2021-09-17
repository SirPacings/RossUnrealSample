// Copyright Epic Games, Inc. All Rights Reserved.

#include "RossUnrealSampleGameMode.h"
#include "RossUnrealSampleHUD.h"
#include "RossUnrealSampleCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARossUnrealSampleGameMode::ARossUnrealSampleGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ARossUnrealSampleHUD::StaticClass();
}
