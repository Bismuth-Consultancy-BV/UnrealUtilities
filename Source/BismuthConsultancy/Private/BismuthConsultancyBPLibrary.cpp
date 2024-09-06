// Copyright Bismuth Consultancy BV. All Rights Reserved.


#include "BismuthConsultancyBPLibrary.h"
#include "BismuthConsultancy.h"
#include "WorldPartition/WorldPartition.h"

UBismuthConsultancyBPLibrary::UBismuthConsultancyBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

TArray<AActor*> UBismuthConsultancyBPLibrary::GetActorsInLevel(UWorld* World)
{
	return World->PersistentLevel->Actors;
}

void UBismuthConsultancyBPLibrary::LoadEntireMap(UWorld* World) {
	
	UWorldPartition* WorldPartition = World->GetWorldPartition();
	if (WorldPartition != nullptr)
	{
		FBox WorldBound = WorldPartition->GetEditorWorldBounds();
		TArray<FBox> Zones;
		Zones.Add(WorldBound);
		WorldPartition->LoadLastLoadedRegions(Zones);
	}
}
