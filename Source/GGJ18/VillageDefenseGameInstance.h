// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Building.h"
#include "VillageDefenseGameInstance.generated.h"

USTRUCT(BlueprintType)
struct FBuildingPosition {

	// The Actual Building
	ABuilding* Building;

	// The X and Y Coordinates
	int X, Y;

};


/**
 * 
 */
UCLASS()
class GGJ18_API UVillageDefenseGameInstance : public UGameInstance {
	GENERATED_BODY()
	
public:

	virtual void Init() override;

	/** The Current Amount of Food the Player Has */
	UFUNCTION(BlueprintPure, Category = "Resources")
		int GetFood();

	/** Set The Amount of Food the Player Has */
	UFUNCTION(BlueprintCallable, Category = "Resources")
		void SetFood(int Amount);

	/** Give the Player More Food */
	UFUNCTION(BlueprintCallable, Category = "Resources")
		void AddFood(int Amount);

	/** Take Food from the Player */
	UFUNCTION(BlueprintCallable, Category = "Resources")
		void LoseFood(int Amount);

	/** The Current Amount of Wood the Player Has */
	UFUNCTION(BlueprintPure, Category = "Resources")
		int GetWood();

	/** Set The Amount of Wood the Player Has */
	UFUNCTION(BlueprintCallable, Category = "Resources")
		void SetWood(int Amount);

	/** Give the Player More Wood */
	UFUNCTION(BlueprintCallable, Category = "Resources")
		void AddWood(int Amount);

	/** Take Wood from the Player */
	UFUNCTION(BlueprintCallable, Category = "Resources")
		void LoseWood(int Amount);

	/** The Current Amount of Stone the Player Has */
	UFUNCTION(BlueprintPure, Category = "Resources")
		int GetStone();

	/** Set The Amount of Stone the Player Has */
	UFUNCTION(BlueprintCallable, Category = "Resources")
		void SetStone(int Amount);

	/** Give the Player More Stone */
	UFUNCTION(BlueprintCallable, Category = "Resources")
		void AddStone(int Amount);

	/** Take Stone from the Player */
	UFUNCTION(BlueprintCallable, Category = "Resources")
		void LoseStone(int Amount);

	/** Get the Building at the Current Position */
	UFUNCTION(BlueprintPure, Category = "Buildings")
		ABuilding* GetBuildingAtLocation(int X, int Y);

	/** Place a Building onto the Grid */
	UFUNCTION(BlueprintCallable, Category = "Buildings")
		void PlaceBuilding(ABuilding* Building, int X, int Y, int Width, int Height);

	/** 
	 * Check the Grid to See if a Building Can Be Placed 
	 * Returns true if it a building can be placed
	 */
	UFUNCTION(BlueprintPure, Category = "Buildings")
		bool CheckGrid(int X, int Y, int Width, int Height);

private:
	// The Current Amount of Food the Player Has
	int Food;

	// The Current Amount of Wood the Player Has
	int Wood;

	// The Current Amount of Stone the Player Has
	int Stone;

	// Default Size of the Grid
	static const int DEFAULTWIDTH;
	static const int DEFAULTHEIGHT;

	// The List of All Buildings in the Map
	TArray<FBuildingPosition> BuildingList;

	// The Current Layout of the Grid
	TArray<TArray<ABuilding*>> Grid;

};
