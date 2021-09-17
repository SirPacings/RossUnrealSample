// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnedCrate.h"

// Sets default values
ASpawnedCrate::ASpawnedCrate()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Create static mesh component
	CrateMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CrateMesh"));
	RootComponent = CrateMesh;
	SetActorScale3D((FVector)(0.1, 0.1, 0.1));
}

// Called when the game starts or when spawned
void ASpawnedCrate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnedCrate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

