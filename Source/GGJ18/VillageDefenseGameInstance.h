// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Building.h"
#include "VillageDefenseGameInstance.generated.h"


USTRUCT(BlueprintType)
struct FCost  {

	GENERATED_BODY()

	int food;
	int wood;
	int stone;
};

USTRUCT(BlueprintType)
struct FBuildingCosts {

	GENERATED_BODY()

	TArray<FCost> house;
	TArray<FCost> farm;
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

	/** Gets the max amount of food the village can have */
	UFUNCTION(BlueprintPure, Category = "Resources")
		int GetMaxFood();

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

	/** Gets the max amount of wood the village can have */
	UFUNCTION(BlueprintPure, Category = "Resources")
		int GetMaxWood();

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

	/** Gets the max amount of stone the village can have */
	UFUNCTION(BlueprintPure, Category = "Resources")
		int GetMaxStone();

	/** The Current Number of People in the Village */
	UFUNCTION(BlueprintPure, Category = "People")
		int GetPeople();

	/** Set The Amount of People in the Village */
	UFUNCTION(BlueprintCallable, Category = "People")
		void SetPeople(int Amount);

	/** Add People to the Village */
	UFUNCTION(BlueprintCallable, Category = "People")
		void AddPeople(int Amount);

	/** Remove People from the Village */
	UFUNCTION(BlueprintCallable, Category = "People")
		void LosePeople(int Amount);

	/** Gets the max number of people the village can face */
	UFUNCTION(BlueprintPure, Category = "People")
		int GetMaxPeople();

	UFUNCTION(BlueprintCallable, Category = "Buildings")
		FBuildingCosts GetBuildingCosts();

private:
	// The Current Amount of Food the Player Has
	int Food;

	// The Current Amount of Wood the Player Has
	int Wood;

	// The Current Amount of Stone the Player Has
	int Stone;

	// The number of people in the village
	int People;

	FBuildingCosts BuildingCosts;

};
