// Copyright Bismuth Consultancy BV. All Rights Reserved.


#include "BismuthConsultancyBPLibrary.h"
#include "BismuthConsultancy.h"
#include "WorldPartition/WorldPartition.h"
#include "Landscape.h"

UBismuthConsultancyBPLibrary::UBismuthConsultancyBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

TArray<AActor*> UBismuthConsultancyBPLibrary::GetActorsInLevel(UWorld* World)
{
	return World->PersistentLevel->Actors;
}

#if WITH_EDITOR
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

void UBismuthConsultancyBPLibrary::RefreshLandscape(ALandscape* Landscape)
{
	Landscape->RequestSplineLayerUpdate();
	Landscape->RequestLayersContentUpdateForceAll();
	Landscape->ForceUpdateLayersContent(/* bIntermediateRender */ false);
	Landscape->RequestLayersInitialization(true);

}
void UBismuthConsultancyBPLibrary::CreateLandscapeEditLayer(ALandscape* Landscape, FName LayerName)
{
	Landscape->CreateLayer(LayerName);
}
void UBismuthConsultancyBPLibrary::DeleteLandscapeEditLayer(ALandscape* Landscape, FName LayerName)
{
	int32 LayerIndex = Landscape->GetLayerIndex(LayerName);
	Landscape->DeleteLayer (LayerIndex);
}
#endif
