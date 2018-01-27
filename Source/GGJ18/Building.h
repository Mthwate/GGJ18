// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Building.generated.h"

UCLASS(abstract)
class GGJ18_API ABuilding : public AActor {
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilding();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	/** Get the current health of the building */
	UFUNCTION(BlueprintPure, Category = "Building Properties")
		int GetCurrentHealth();

	/** Get the maximum health of the building */
	UFUNCTION(BlueprintPure, Category = "Building Properties")
		int GetMaximumHealth();

	/** Get the ratio of health of the building */
	UFUNCTION(BlueprintPure, Category = "Building Properties")
		float GetHealthRate();

	/** Set the building's current health (Corrects out of bounds values) */
	UFUNCTION(BlueprintCallable, Category = "Building Properties")
		void SetHealth(int Amount);

	/** Increase the building's health (Corrects out of bounds values) */
	UFUNCTION(BlueprintCallable, Category = "Building Properties")
		void GainHealth(int Amount);

	/** Decrease the building's health (Corrects out of bounds values) */
	UFUNCTION(BlueprintCallable, Category = "Building Properties")
		void LoseHealth(int Amount);

	/** The width of the building in tiles */
	UFUNCTION(BlueprintPure, Category = "Building Properties")
		int GetWidth();

	/** The height of the building in tiles */
	UFUNCTION(BlueprintPure, Category = "Building Properties")
		int GetHeight();

	/** The amount of food need to buy a new building */
	UFUNCTION(BlueprintPure, Category = "Building Properties")
		int GetFoodCost();

	/** The amount of wood need to buy a new building */
	UFUNCTION(BlueprintPure, Category = "Building Properties")
		int GetWoodCost();

	/** The amount of stone need to buy a new building */
	UFUNCTION(BlueprintPure, Category = "Building Properties")
		int GetStoneCost();

private:
	// The Current Health of the Building
	int CurrentHealth;

	// The Maximum Health of the Building
	UPROPERTY(EditDefaultsOnly, Category = "Building Properties")
		int MaxHealth;

	// The Width of the Building in Tiles
	UPROPERTY(EditDefaultsOnly, Category = "Building Properties")
		int Width;

	// The Height of the Building in Tiles
	UPROPERTY(EditDefaultsOnly, Category = "Building Properties")
		int Height;

	// The Amount of Food Needed to Purchase this Building
	UPROPERTY(EditDefaultsOnly, Category = "Building Properties")
		int FoodCost;

	// The Amount of Wood Needed to Purchase this Building
	UPROPERTY(EditDefaultsOnly, Category = "Building Properties")
		int WoodCost;

	// The Amount of Stone Needed to Purchase this Building
	UPROPERTY(EditDefaultsOnly, Category = "Building Properties")
		int StoneCost;
	
};
