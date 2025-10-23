// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StructForRoom.h"
#include "Room.generated.h"

class UBoxComponent;

UCLASS()
class PROCEDURALDUNGEON_API ARoom : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARoom();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere , Category = "room size | length")
	float minx = 1.;

	UPROPERTY(EditAnywhere, Category = "room size | length")
	float maxx = 1.;

	UPROPERTY(EditAnywhere, Category = "room size | width")
	float miny = 1.;

	UPROPERTY(EditAnywhere, Category = "room size | width")
	float maxy = 1.;

	bool isabigroom=false;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* mat;
	
	void setsize(int x, int y);


	//UPROPERTY(VisibleAnywhere, Category = "room components")
	UPROPERTY(EditAnywhere, Category = "room components")
	UStaticMeshComponent* room;



};
