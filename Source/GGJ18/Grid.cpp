// Fill out your copyright notice in the Description page of Project Settings.

#include "Grid.h"


// Sets default values
AGrid::AGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGrid::BeginPlay()
{
	Super::BeginPlay();


	for (int x = 0; x < width; x++) {
		Grid.Add(TArray<ABuilding*>());
		for (int y = 0; y < height; y++) {
			Grid[x].Add(NULL);
		}
	}

	GenMap(5);

}

ABuilding* AGrid::GetBuildingAtLocation(int X, int Y) {
	return Grid[X][Y];
}

bool AGrid::PlaceBuilding(ABuilding* Building, int X, int Y) {
	if (CanPlaceBuilding(Building, X, Y)) { // Check if the Building Can Be Placed
										  // Add the Building to the List
		BuildingList.Add(Building);
		
		FVector Location(X * 100 - 50, Y * 100 - 50, 0.0f);
		Building->SetActorLocation(Location);
		Building->AttachRootComponentToActor(this);
		
		// Add the Building the Grid
		for (int i = X; i < X + Building->GetWidth(); i++) {
			for (int j = Y; j < Y + Building->GetHeight(); j++) {
				Grid[i][j] = Building;
			}
		}
		return true;
	}
	else {
		return false;
	}
}

bool AGrid::CanPlaceBuilding(ABuilding* Building, int X, int Y) {
	if ((X + Building->GetWidth()) >= width || (Y + Building->GetHeight()) >= height) {
		return false;
	}
	else {
		for (int i = X; i < X + Building->GetWidth(); i++) {
			for (int j = Y; j < Y + Building->GetHeight(); j++) {
				if (Grid[i][j] != NULL) {
					return false;
				}
			}
		}
		return true;
	}
}

int AGrid::GetGridWidth() {
	return width;
}

int AGrid::GetGridHeight() {
	return height;
}

void AGrid::SetGridWidth(int W) {
	width = W;
}

void AGrid::SetGridHeight(int H) {
	height = H;
}

void AGrid::GenMap(int NumBuildings) {

	for (int i = 0; i < NumBuildings; i++) {
		ABuilding * building;
		int x;
		int y;
		do {
			int bi = FMath::RandRange(0, buildings.Num() - 1);
			building = Cast<ABuilding>(GetWorld()->SpawnActor(buildings[bi]));

			x = FMath::RandRange(0, width - 1);
			y = FMath::RandRange(0, height - 1);
		} while (!PlaceBuilding(building, x, y));
	}
	
}