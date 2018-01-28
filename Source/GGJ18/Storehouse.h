// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Building.h"
#include "Storehouse.generated.h"

/**
 * 
 */
UCLASS()
class GGJ18_API AStorehouse : public ABuilding {
	GENERATED_BODY()
	
public:
	AStorehouse();

	int GetFoodCapacity();
	int GetWoodCapacity();
	int GetStoneCapacity();
	
private:

	UPROPERTY(EditDefaultsOnly, Category = "Resources")
		int FoodCapacity;
	UPROPERTY(EditDefaultsOnly, Category = "Resources")
		int WoodCapacity;
	UPROPERTY(EditDefaultsOnly, Category = "Resources")
		int StoneCapacity;
	
	
};
