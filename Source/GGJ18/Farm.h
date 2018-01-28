// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Building.h"
#include "GGJ18GameModeBase.h"
#include "Farm.generated.h"

/**
 * 
 */
UCLASS()
class GGJ18_API AFarm : public ABuilding
{
	GENERATED_BODY()
	
public:

	AFarm();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure, Category = "Resources")
		float GetProductionRate();

	UFUNCTION(BlueprintCallable, Category = "Resources")
		void SetProductionRate(float Amount);

private:
	
	// Indicates how much food is produced per second
	UPROPERTY(EditDefaultsOnly, Category = "Resources")
		float ProductionRate;
	
};
