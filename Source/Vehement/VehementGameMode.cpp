// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "VehementGameMode.h"
#include "VehementHUD.h"
#include "Player/FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

AVehementGameMode::AVehementGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AVehementHUD::StaticClass();
}
