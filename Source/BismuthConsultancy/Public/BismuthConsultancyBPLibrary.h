// Copyright Bismuth Consultancy BV. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "BismuthConsultancyBPLibrary.generated.h"


UCLASS()
class UBismuthConsultancyBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	// Gets all registered actors for a given Level.
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get All Actors in a Level", Keywords = "All Actor World"), Category = "BismuthConsultancy")
	static TArray<AActor*> GetActorsInLevel(UWorld* World);
	
	// Loads all Actors for the Map Bounds of a given WorldPartition level.
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Load All WorldPartition Actors", Keywords = "WorldPartition"), Category = "BismuthConsultancy")
	static void LoadEntireMap(UWorld* World);

};
