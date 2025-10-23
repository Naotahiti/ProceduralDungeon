// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StructForRoom.h"
#include "Room.h"
#include "RoomGenerator.generated.h"

UCLASS()
class PROCEDURALDUNGEON_API ARoomGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARoomGenerator();

	UPROPERTY(EditAnywhere)
	int rooms_num;

	void generaterooms();


	UPROPERTY(EditAnywhere)
	float radius;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ARoom> roomref;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
