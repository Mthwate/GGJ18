// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Building.h"
#include "Grid.generated.h"

UCLASS(abstract)
class GGJ18_API AGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrid();

	/** Get the Building at the Current Position */
	UFUNCTION(BlueprintPure, Category = "Grid")
		ABuilding* GetBuildingAtLocation(int X, int Y);

	/** Place a Building onto the Grid */
	UFUNCTION(BlueprintCallable, Category = "Grid")
		bool PlaceBuilding(ABuilding* Building, int X, int Y);

	/**
	* Check the Grid to See if a Building Can Be Placed
	* Returns true if it a building can be placed
	*/
	UFUNCTION(BlueprintPure, Category = "Grid")
		bool CanPlaceBuilding(ABuilding* Building, int X, int Y);

	UFUNCTION(BlueprintPure, Category = "Grid")
		int GetGridWidth();

	UFUNCTION(BlueprintPure, Category = "Grid")
		int GetGridHeight();

	UFUNCTION(BlueprintCallable, Category = "Grid")
		void SetGridWidth(int W);

	UFUNCTION(BlueprintCallable, Category = "Grid")
		void SetGridHeight(int H);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	// The List of All Buildings in the Map
	TArray<ABuilding*> BuildingList;

	// The Current Layout of the Grid
	TArray<TArray<ABuilding*>> Grid;

	TArray<TArray<AActor*>> TileGrid;

	UPROPERTY(EditDefaultsOnly, Category = "Grid")
		int width;

	UPROPERTY(EditDefaultsOnly, Category = "Grid")
		int height;

	UPROPERTY(EditDefaultsOnly, Category = "Grid")
		UClass * gridTile;
	
};
