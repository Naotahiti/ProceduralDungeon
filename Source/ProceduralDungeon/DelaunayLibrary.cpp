// Fill out your copyright notice in the Description page of Project Settings.

#include "DelaunayLibrary.h"

struct FTriangleData
{
    int32 A, B, C;

    FTriangleData(int32 InA, int32 InB, int32 InC) : A(InA), B(InB), C(InC) {}

    bool ContainsVertex(int32 V) const
    {
        return (A == V || B == V || C == V);
    }
    bool operator==(const FTriangleData& Other) const
    {
        return (A == Other.A && B == Other.B && C == Other.C);
    }
};



// teste si un point est dans le cercle circonscrit
static bool IsPointInCircumcircle(const FVector2D& P, const FVector2D& A, const FVector2D& B, const FVector2D& C)
{
    float Ax = A.X - P.X;
    float Ay = A.Y - P.Y;
    float Bx = B.X - P.X;
    float By = B.Y - P.Y;
    float Cx = C.X - P.X;
    float Cy = C.Y - P.Y;

    float Det = (Ax * (By * (Cx * Cx + Cy * Cy) - Cy * (Bx * Bx + By * By))
        - Ay * (Bx * (Cx * Cx + Cy * Cy) - Cx * (Bx * Bx + By * By))
        + (Ax * Ax + Ay * Ay) * (Bx * Cy - Cx * By));

    return Det < 0.0f;

}

TArray<FTriangle> UDelaunayLibrary::TriangulateDelaunay(const TArray<FVector2D>& Points)
{
    TArray<FVector2D> WorkingPoints = Points;
    TArray<FTriangleData> Triangles;

    if (Points.Num() < 3)
        return {};

    // Super-triangle 
    float MinX = Points[0].X, MaxX = Points[0].X;
    float MinY = Points[0].Y, MaxY = Points[0].Y;
    for (auto& P : Points)
    {
        MinX = FMath::Min(MinX, P.X);
        MaxX = FMath::Max(MaxX, P.X);
        MinY = FMath::Min(MinY, P.Y);
        MaxY = FMath::Max(MaxY, P.Y);
    }

    float DX = MaxX - MinX;
    float DY = MaxY - MinY;
    float DeltaMax = FMath::Max(DX, DY) * 10.f;

    FVector2D P1(MinX - 1, MinY - 1 - DeltaMax);
    FVector2D P2(MinX + DX * 0.5f, MaxY + DeltaMax);
    FVector2D P3(MaxX + DeltaMax, MinY - 1 - DeltaMax);

    int32 I1 = WorkingPoints.Add(P1);
    int32 I2 = WorkingPoints.Add(P2);
    int32 I3 = WorkingPoints.Add(P3);

    Triangles.Add(FTriangleData(I1, I2, I3));

    // Étape 2 : Boucle sur les points
    for (int32 i = 0; i < Points.Num(); i++)
    {
        const FVector2D& Point = Points[i];
        TArray<FTriangleData> BadTriangles;

        // Trouver les triangles dont le cercle circonscrit contient le point
        for (auto& T : Triangles)
        {
            if (IsPointInCircumcircle(Point, WorkingPoints[T.A], WorkingPoints[T.B], WorkingPoints[T.C]))
                BadTriangles.Add(T);
        }

        // Trouver le polygone "bordure"
        TArray<TPair<int32, int32>> PolygonEdges;
        for (auto& T : BadTriangles)
        {
            TArray<TPair<int32, int32>> Edges = {
                {T.A, T.B},
                {T.B, T.C},
                {T.C, T.A}
            };

            for (auto& E : Edges)
            {
                bool bShared = false;
                for (auto& T2 : BadTriangles)
                {
                    if (&T2 == &T) continue;
                    if (T2.ContainsVertex(E.Key) && T2.ContainsVertex(E.Value))
                    {
                        bShared = true;
                        break;
                    }
                }
                if (!bShared)
                    PolygonEdges.Add(E);
            }
        }

        // Supprimer les mauvais triangles
        for (auto& T : BadTriangles)
        {
            Triangles.RemoveSingle(T);
        }

        // Créer de nouveaux triangles
        int32 PIndex = i;
        for (auto& Edge : PolygonEdges)
        {
            Triangles.Add(FTriangleData(Edge.Key, Edge.Value, PIndex));
        }
    }

    // Étape 3 : Supprimer les triangles qui utilisent le super-triangle
    TArray<FTriangle> FinalTriangles;
    for (auto& T : Triangles)
    {
        if (T.ContainsVertex(I1) || T.ContainsVertex(I2) || T.ContainsVertex(I3))
            continue;
        FinalTriangles.Add(FTriangle(T.A, T.B, T.C));
    }

    return FinalTriangles;
}

TArray<FEdgeMST> UDelaunayLibrary::BuildMinimumSpanningTree(const TArray<FVector2D>& Points, const TArray<FTriangle>& Triangles)

    {
        // construire une liste d’arêtes uniques issues de la triangulation
        struct FWeightedEdge
        {
            int32 A, B;
            float Weight;
            FWeightedEdge(int32 InA, int32 InB, float InWeight)
                : A(InA), B(InB), Weight(InWeight) {
            }
        };

        TArray<FWeightedEdge> Edges;
        for (const FTriangle& T : Triangles)
        {
            TArray<TPair<int32, int32>> TriangleEdges = {
                {T.A, T.B},
                {T.B, T.C},
                {T.C, T.A}
            };

            for (auto& E : TriangleEdges)
            {
                // Éviter les doublons (AB = BA)
                bool bExists = false;
                for (auto& Existing : Edges)
                {
                    if ((Existing.A == E.Key && Existing.B == E.Value) ||
                        (Existing.A == E.Value && Existing.B == E.Key))
                    {
                        bExists = true;
                        break;
                    }
                }

                if (!bExists)
                {
                    float Dist = FVector2D::Distance(Points[E.Key], Points[E.Value]);
                    Edges.Add(FWeightedEdge(E.Key, E.Value, Dist));
                }
            }
        }

        // initialisation du MST
        TArray<int32> InMST;       // indices des sommets déjà dans l’arbre
        TArray<FEdgeMST> MSTEdges;    // résultat final

        if (Points.Num() == 0)
            return MSTEdges;

        InMST.Add(0); // point de départ arbitraire

        // boucle jusqu’à ce que tous les points soient connectés
        while (InMST.Num() < Points.Num())
        {
            FWeightedEdge BestEdge(-1, -1, FLT_MAX);

            // Parcourir toutes les arêtes connectant MST à un nœud hors MST
            for (const FWeightedEdge& E : Edges)
            {
                bool bAIn = InMST.Contains(E.A);
                bool bBIn = InMST.Contains(E.B);

                // On veut exactement un des deux dans l’arbre
                if (bAIn != bBIn)
                {
                    if (E.Weight < BestEdge.Weight)
                    {
                        BestEdge = E;
                    }
                }
            }

            // Si aucune arête valide 
            if (BestEdge.A == -1)
                break;

            MSTEdges.Add(FEdgeMST(BestEdge.A, BestEdge.B));

            // Ajouter le nouveau sommet dans l’arbre
            if (!InMST.Contains(BestEdge.A)) InMST.Add(BestEdge.A);
            if (!InMST.Contains(BestEdge.B)) InMST.Add(BestEdge.B);
        }

        return MSTEdges;
    }


