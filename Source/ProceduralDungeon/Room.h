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

	void initialize(FStructForRoom s);
	
protected :



	UPROPERTY(EditAnywhere, Category = "room components")
	USceneComponent* scenecomp;

	UPROPERTY(EditAnywhere, Category = "room components")
	USceneComponent* geocomp;

	UPROPERTY(EditAnywhere, Category = "room components")
	USceneComponent* overlapcomp;

	//UPROPERTY(VisibleAnywhere, Category = "room components")
	UPROPERTY(EditAnywhere, Category = "room components")
	UStaticMeshComponent* wall_1;

	//UPROPERTY(VisibleAnywhere, Category = "room components")
	UPROPERTY(EditAnywhere, Category = "room components")
	UStaticMeshComponent* wall_2;

	//UPROPERTY(VisibleAnywhere, Category = "room components")
	UPROPERTY(EditAnywhere, Category = "room components")
	UStaticMeshComponent* wall_3;

	//UPROPERTY(VisibleAnywhere, Category = "room components")
	UPROPERTY(EditAnywhere, Category = "room components")
	UStaticMeshComponent* wall_4;

	//UPROPERTY(VisibleAnywhere, Category = "room components")
	UPROPERTY(EditAnywhere, Category = "room components")
	UStaticMeshComponent* wall_5;

	//UPROPERTY(VisibleAnywhere, Category = "room components")
	UPROPERTY(EditAnywhere, Category = "room components")
	UStaticMeshComponent* wall_6;

	//UPROPERTY(VisibleAnywhere, Category = "room components")
	UPROPERTY(EditAnywhere, Category = "room components")
	UStaticMeshComponent* wall_7;

	//UPROPERTY(VisibleAnywhere, Category = "room components")
	UPROPERTY(EditAnywhere, Category = "room components")
	UStaticMeshComponent* wall_8;

	//UPROPERTY(VisibleAnywhere, Category = "room components")
	UPROPERTY(EditAnywhere, Category = "room components")
	UStaticMeshComponent* floor;

	//UPROPERTY(VisibleAnywhere, Category = "room components")
	UPROPERTY(EditAnywhere, Category = "room components")
	UBoxComponent* collision_box;

};
