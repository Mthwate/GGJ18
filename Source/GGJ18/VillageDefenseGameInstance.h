// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "VillageDefenseGameInstance.generated.h"



struct cost  {
	int food;
	int wood;
	int stone;
};


struct buildingCosts {
	cost house[];
	cost farm[];
};


/**
 * 
 */
UCLASS()
class GGJ18_API UVillageDefenseGameInstance : public UGameInstance {
	GENERATED_BODY()
	
public:

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

private:
	// The Current Amount of Food the Player Has
	int Food;

	// The Current Amount of Wood the Player Has
	int Wood;

	// The Current Amount of Stone the Player Has
	int Stone;

	buildingCosts BuildingCosts;

};
