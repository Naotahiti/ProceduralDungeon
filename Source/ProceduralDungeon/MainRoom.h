// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Room.h"
#include"StructForRoom.h"
#include "MainRoom.generated.h"

UCLASS()
class PROCEDURALDUNGEON_API AMainRoom : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMainRoom();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "room stats")
	int num_of_exits;

	UPROPERTY(EditAnywhere, Category = "room stats")
	int num_of_rooms;

	UPROPERTY(EditAnywhere , Category = "rooms stats")
	TArray<int> weights;

	

	UPROPERTY(EditAnywhere , Category = "rooms")
	TArray<TSubclassOf<ARoom>> rooms;

};
