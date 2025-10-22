// Fill out your copyright notice in the Description page of Project Settings.


#include "Room.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ARoom::ARoom()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*wall_1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("wall 1"));
	wall_2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("wall 2"));
	wall_3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("wall 3"));
	wall_4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("wall 4"));
	wall_5 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("wall 5"));
	wall_6 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("wall 6"));
	wall_7 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("wall 7"));
	wall_8 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("wall 8"));
	floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("floor"));

	collision_box = CreateDefaultSubobject<UBoxComponent>(TEXT("collision"));

	scenecomp = CreateDefaultSubobject<USceneComponent>(TEXT("scene component"));
	geocomp = CreateDefaultSubobject<USceneComponent>(TEXT("geometry component"));
	overlapcomp = CreateDefaultSubobject<USceneComponent>(TEXT("overlap component"));

	scenecomp->SetupAttachment(RootComponent);
	geocomp->SetupAttachment(scenecomp);
	overlapcomp->SetupAttachment(scenecomp);

	wall_1->SetupAttachment(geocomp);
	wall_2->SetupAttachment(geocomp);
	wall_3->SetupAttachment(geocomp);
	wall_4->SetupAttachment(geocomp);
	wall_5->SetupAttachment(geocomp);
	wall_6->SetupAttachment(geocomp);
	wall_7->SetupAttachment(geocomp);
	wall_8->SetupAttachment(geocomp);
	floor->SetupAttachment(geocomp);

	collision_box->SetupAttachment(overlapcomp);*/


	

}

// Called when the game starts or when spawned
void ARoom::BeginPlay()
{
	Super::BeginPlay();


	//UWorld* w = GetWorld();
	//FActorSpawnParameters asp;
	////asp.Instigator = this;
	//asp.Owner = this;
	//asp.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	//if(room)
	//w->SpawnActor<ARoom>(room, GetActorLocation() + FVector(0., 0., 2000.), GetActorRotation(),asp);
	
}

// Called every frame
void ARoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARoom::initialize(FStructForRoom s)
{
	floor->SetRelativeScale3D(FVector(s.scaleX, s.scaleY, 10.));
}

