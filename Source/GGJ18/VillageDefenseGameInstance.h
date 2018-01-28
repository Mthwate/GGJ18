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

	UFUNCTION(BlueprintCallable, Category = "Buildings")
		FBuildingCosts GetBuildingCosts();

private:

	FBuildingCosts BuildingCosts;

};
