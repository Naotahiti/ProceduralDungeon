// Fill out your copyright notice in the Description page of Project Settings.


#include "MainRoom.h"

// Sets default values
AMainRoom::AMainRoom()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*for(int i = 0 ; i<num_of_rooms;i++)

	{
	
	}*/

}

// Called when the game starts or when spawned
void AMainRoom::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainRoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

