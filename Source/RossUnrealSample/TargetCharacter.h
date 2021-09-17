// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpawnedCrate.h"
#include "TargetCharacter.generated.h"

UCLASS()
class ROSSUNREALSAMPLE_API ATargetCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATargetCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Activates when the player hits this target
	UFUNCTION(Category = "Hit Testing")
		void OnHitByPlayer(FString HitComponent, FVector HitLocation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/**Color the body will be set to*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Hit Testing")
		FColor BodyColor;

	/**The characters material instance*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Hit Testing")
		UMaterialInstanceDynamic* BodyMaterial;

	/** What is spawned when the character is hit */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Hit Testing")
		TSubclassOf<class ASpawnedCrate> WhatToSpawn;
	
	/** What is spawned when the character is hit */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawning")
		FVector SpawnLocation;

	//Keeps an index of the spawned crates
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawning")
		FVector SpawnedCrates;
private:

	void SpawnCrate(FColor SpawnedColor);



};