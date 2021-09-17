// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetCharacter.h"

// Sets default values
ATargetCharacter::ATargetCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BodyMaterial = NULL;
}

// Called when the game starts or when spawned
void ATargetCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATargetCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATargetCharacter::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATargetCharacter::OnHitByPlayer(FString HitComponent, FVector HitLocation)
{
	//Get the name of the bone nearest the hit location. 
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, GetMesh()->FindClosestBone(HitLocation).ToString());
	FString BoneName= GetMesh()->FindClosestBone(HitLocation).ToString();
	FString TempHitComponent = BoneName;

	//FString TempHitComponent = HitComponent;
	int32 CharacterPostion = 0;
	//Get the location of the _
	bool SideFlag = BoneName.FindLastChar('_', CharacterPostion);
	//Get the side location from the string
	if (SideFlag) TempHitComponent = TempHitComponent.RightChop(CharacterPostion + 1);
	if (TempHitComponent == "r") //Right Side
	{
		BodyColor = FColor::Blue;
		SpawnLocation.Y = 100;
		SpawnedCrates.X++;
		SpawnLocation.Z = (175 + SpawnedCrates.X * 10);
	}
	else if (TempHitComponent == "l") //LeftSide
	{
		BodyColor = FColor::Red;
		SpawnLocation.Y = 120;
		SpawnedCrates.Z++;
		SpawnLocation.Z = (175 + SpawnedCrates.Z * 10);
	}
	else if (BoneName == "head") //Right Side
	{
		BodyColor = FColor::White;
		SpawnLocation.Y = 130;
		SpawnedCrates.X++;
		SpawnLocation.Z = (175 + SpawnedCrates.X * 10);
	}
	else //Center
	{
		BodyColor = FColor::Black;
		SpawnLocation.Y = 110;
		SpawnedCrates.Y++;
		SpawnLocation.Z = (175 + SpawnedCrates.Y * 10);
	}
	//Get the Name of the part from the string
	TempHitComponent = BoneName;
	if (SideFlag) TempHitComponent = TempHitComponent.LeftChop(BoneName.Len() - CharacterPostion);

	//Debug call out the part that was hit
	GEngine->AddOnScreenDebugMessage(-1, 1.f, BodyColor, FString::Printf(TEXT("You are being hit: %s"), *TempHitComponent));

	//Create a material instance for the player character, if its not already set, then change the color on it
	if (BodyMaterial == NULL) {

		//Get the skeletal mesh Material
		UMaterialInterface* MeshMaterial = GetMesh()->GetMaterial(0);

		//Create a Material instance, apply it to the mesh
		BodyMaterial = GetMesh()->CreateDynamicMaterialInstance(0, MeshMaterial);

		//GEngine->AddOnScreenDebugMessage(-1, 1.f, BodyColor, FString::Printf(TEXT("Initialize material")));
	}
	if (BodyMaterial != NULL)
	{
		BodyMaterial->SetVectorParameterValue("BodyColor", BodyColor);
	}
	//Spawn a crate
	//SpawnCrate(BodyColor);
}

void ATargetCharacter::SpawnCrate(FColor SpawnedColor)
{
	//Check to see if there is something to spawn
	if (WhatToSpawn != NULL)
	{
		//Get the world
		UWorld* const World = GetWorld();
		if (World)
		{
			//Set Spawn Parameters
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = this;
			//Set Rotation to 0,0,0
			FRotator SpawnRotation = (FRotator)(0, 0, 0);

			//Creat the crate
			ASpawnedCrate* LastSpawnedCrate = World->SpawnActor<ASpawnedCrate>(WhatToSpawn, SpawnLocation, SpawnRotation, SpawnParams);

			//create a dynamic material instance then change the vector on that instance
			UMaterialInterface* CrateMaterial = LastSpawnedCrate->CrateMesh->GetMaterial(0);
			UMaterialInstanceDynamic* MatInstance = LastSpawnedCrate->CrateMesh->CreateDynamicMaterialInstance(0, CrateMaterial);
			if (MatInstance != NULL)
			{
				MatInstance->SetVectorParameterValue("CrateColor", SpawnedColor);
			}
		}

	}

}