// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Building.h"
#include "House.generated.h"

/**
 * 
 */
UCLASS()
class GGJ18_API AHouse : public ABuilding {
	GENERATED_BODY()
	
public:

	AHouse();

	UFUNCTION(BlueprintPure, Category = "Resources")
		int GetResidenceCapacity();

private:

	UPROPERTY(EditDefaultsOnly, Category = "Resources")
		int ResidenceCapacity;
	
};