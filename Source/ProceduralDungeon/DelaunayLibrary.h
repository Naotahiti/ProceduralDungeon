// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DelaunayLibrary.generated.h"

/**
 * 
 */



USTRUCT(BlueprintType)
struct FTriangle
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    int32 A;

    UPROPERTY(BlueprintReadOnly)
    int32 B;

    UPROPERTY(BlueprintReadOnly)
    int32 C;

    FTriangle() : A(0), B(0), C(0) {}
    FTriangle(int32 InA, int32 InB, int32 InC) : A(InA), B(InB), C(InC) {}

 
};

USTRUCT(BlueprintType)
struct FEdgeMST
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    int32 A;

    UPROPERTY(BlueprintReadOnly)
    int32 B;

    FEdgeMST() : A(0), B(0) {}
    FEdgeMST(int32 InA, int32 InB) : A(InA), B(InB) {}
};

UCLASS()
class PROCEDURALDUNGEON_API UDelaunayLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
   
    UFUNCTION(BlueprintCallable, Category = "Delaunay")
    static TArray<FTriangle> TriangulateDelaunay(const TArray<FVector2D>& Points);

    UFUNCTION(BlueprintCallable, Category = "Minimal Spanning Tree")
    static TArray<FEdgeMST> BuildMinimumSpanningTree(const TArray<FVector2D>& Points, const TArray<FTriangle>& Triangles);
};



