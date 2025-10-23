// Fill out your copyright notice in the Description page of Project Settings.


#include "Room.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ARoom::ARoom()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	room = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("floor"));
	RootComponent = room;





}

// Called when the game starts or when spawned
void ARoom::BeginPlay()
{
	Super::BeginPlay();


	
	
}

// Called every frame
void ARoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARoom::setsize(int x, int y)
{

	if (room)
	{
		
		
		room->SetWorldScale3D(FVector(x, y, 1.));
		if (x > 2 || y > 2)
		{
			isabigroom = true;
			room->SetMaterial(0, mat);
		}
	}
}



