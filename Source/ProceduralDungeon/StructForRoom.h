// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StructForRoom.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FStructForRoom
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int numofexits;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<int> weights;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    double scaleX;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    double scaleY;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float rotation;
};

