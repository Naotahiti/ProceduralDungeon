// Fill out your copyright notice in the Description page of Project Settings.


#include "RoomGenerator.h"
#include "Kismet/KismetMathLibrary.h"
#include "DelaunayLibrary.h"

// Sets default values
ARoomGenerator::ARoomGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}



void ARoomGenerator::GenerateHallways()
{
}

// Called when the game starts or when spawned
void ARoomGenerator::BeginPlay()
{
	Super::BeginPlay();

	FVector genloc = GetActorLocation();

	UWorld* w = GetWorld();
	FActorSpawnParameters asp;
	asp.Owner = this;
	asp.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;// AdjustIfPossibleButDontSpawnIfColliding;

	if(w)
	for (int i = 0; i < rooms_num; i++)
	{
		
		FVector2D v = FMath::RandPointInCircle(radius);
		int length = FMath::RandRange(1, 3);
		int width = FMath::RandRange(1, 3);
		ARoom* r = w->SpawnActor<ARoom>(roomref, FVector(genloc.X+v.X, genloc.Y+v.Y, 100.),GetActorRotation(),asp);
		r->setsize(length, width);
		
	if(r->isabigroom) 
	{
		// store all main rooms
		centers.Add(FVector2D(r->GetActorLocation().X, r->GetActorLocation().Y));
	}

	}
	
	TArray<FTriangle> triangles = UDelaunayLibrary::TriangulateDelaunay(centers);
    for (auto& t : triangles)
	{
		DrawDebugLine(GetWorld(), FVector(centers[t.A].X, centers[t.A].Y, 200.), 
			FVector(centers[t.B].X, centers[t.B].Y, 200.), FColor::Cyan,false,5.,10.);
		DrawDebugLine(GetWorld(), FVector(centers[t.B].X, centers[t.B].Y, 200.),
			FVector(centers[t.C].X, centers[t.C].Y, 200.), FColor::Cyan,false,5.,10.);
		DrawDebugLine(GetWorld(), FVector(centers[t.C].X, centers[t.C].Y, 200.),
			FVector(centers[t.A].X, centers[t.A].Y, 200.), FColor::Cyan,false,5.,10.);
	}

	TArray<FEdgeMST> edges = UDelaunayLibrary::BuildMinimumSpanningTree(centers, triangles);
	for (auto& edge : edges)
	{
		DrawDebugLine(GetWorld(), FVector(centers[edge.A].X,centers[edge.A].Y,200.), 
			FVector(centers[edge.B].X, centers[edge.B].Y, 200.), FColor::Yellow, false, 20., 10.);
	}
}

// Called every frame
void ARoomGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

