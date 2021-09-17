// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "RossUnrealSampleHUD.generated.h"

UCLASS()
class ARossUnrealSampleHUD : public AHUD
{
	GENERATED_BODY()

public:
	ARossUnrealSampleHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

