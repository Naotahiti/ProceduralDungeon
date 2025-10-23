// Fill out your copyright notice in the Description page of Project Settings.


#include "RoomGenerator.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ARoomGenerator::ARoomGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ARoomGenerator::generaterooms()
{
}

// Called when the game starts or when spawned
void ARoomGenerator::BeginPlay()
{
	Super::BeginPlay();

	UWorld* w = GetWorld();
	FActorSpawnParameters asp;
	asp.Owner = this;
	asp.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
	if(w)
	for (int i = 0; i < rooms_num; i++)
	{
		int rd = FMath::RandRange(0,1);
		FVector2D v = FMath::RandPointInCircle(radius);
		/*FString str = FString::SanitizeFloat(v.X).Append(FString::SanitizeFloat(v.Y));
		FText::FromString(str);*/
		ARoom* r = w->SpawnActor<ARoom>(roomref, FVector(v.X, v.Y, 100.),GetActorRotation(),asp);
		
		if (!r) // pour être sûr qu'il y ait le nb souhaité de spawn
			rooms_num++;



	}
}

// Called every frame
void ARoomGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

