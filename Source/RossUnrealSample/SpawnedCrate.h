// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnedCrate.generated.h"

UCLASS()
class ROSSUNREALSAMPLE_API ASpawnedCrate : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpawnedCrate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Return the mesh for the crate*/
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return CrateMesh; }

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawning")
		FColor CrateColor;

	/** Static mesh spawned in game*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
		class UStaticMeshComponent* CrateMesh;
};
