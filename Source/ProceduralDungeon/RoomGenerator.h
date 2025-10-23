// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Room.h"
#include "RoomGenerator.generated.h"

UCLASS()
class PROCEDURALDUNGEON_API ARoomGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARoomGenerator();

	UPROPERTY(EditAnywhere) // number of rooms we want to spawn
	int rooms_num;




	UPROPERTY(EditAnywhere) // room spawn radius
	float radius;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ARoom> roomref;

	

	TArray<FVector2D> centers;

	void GenerateHallways();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
