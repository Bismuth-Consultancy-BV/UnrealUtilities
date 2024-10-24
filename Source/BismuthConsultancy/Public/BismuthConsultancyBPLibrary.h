// Copyright Bismuth Consultancy BV. All Rights Reserved.

#pragma once

#include "Landscape.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BismuthConsultancyBPLibrary.generated.h"


UCLASS()
class UBismuthConsultancyBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	// Gets all registered actors for a given Level.
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get All Actors in a Level", Keywords = "All Actor World"), Category = "BismuthConsultancy")
	static TArray<AActor*> GetActorsInLevel(UWorld* World);

#if WITH_EDITOR
	// Loads all Actors for the Map Bounds of a given WorldPartition level.
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Load All WorldPartition Actors", Keywords = "WorldPartition"), Category = "BismuthConsultancy")
	static void LoadEntireMap(UWorld* World);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Refresh Landscape Layers", Keywords = "Landscape"), Category = "BismuthConsultancy")
	static void RefreshLandscape(ALandscape* Landscape);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Create Landscape Layer", Keywords = "Landscape"), Category = "BismuthConsultancy")
	static void CreateLandscapeEditLayer(ALandscape* Landscape, FName LayerName);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Delete Landscape Layer", Keywords = "Landscape"), Category = "BismuthConsultancy")
	static void DeleteLandscapeEditLayer(ALandscape* Landscape, FName LayerName);
#endif

};
