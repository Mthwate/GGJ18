// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "House.h"
#include "Storehouse.h"
#include "Farm.h"
#include "ResourceStore.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GGJ18_API UResourceStore : public UUserWidget
{
	GENERATED_BODY()

public:
	UResourceStore(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

public:
	UFUNCTION(BlueprintPure, Category = "Resources")
		int GetFood();
	UFUNCTION(BlueprintCallable, Category = "Resources")
		void SetFood(int Amount);
	UFUNCTION(BlueprintCallable, Category = "Resources")
		void GainFood(int Amount);
	UFUNCTION(BlueprintCallable, Category = "Resources")
		void LoseFood(int Amount);
	UFUNCTION(BlueprintPure, Category = "Resources")
		int GetMaxFood();

	UFUNCTION(BlueprintPure, Category = "Resources")
		int GetWood();
	UFUNCTION(BlueprintCallable, Category = "Resources")
		void SetWood(int Amount);
	UFUNCTION(BlueprintCallable, Category = "Resources")
		void GainWood(int Amount);
	UFUNCTION(BlueprintCallable, Category = "Resources")
		void LoseWood(int Amount);
	UFUNCTION(BlueprintPure, Category = "Resources")
		int GetMaxWood();

	UFUNCTION(BlueprintPure, Category = "Resources")
		int GetStone();
	UFUNCTION(BlueprintCallable, Category = "Resources")
		void SetStone(int Amount);
	UFUNCTION(BlueprintCallable, Category = "Resources")
		void GainStone(int Amount);
	UFUNCTION(BlueprintCallable, Category = "Resources")
		void LoseStone(int Amount);
	UFUNCTION(BlueprintPure, Category = "Resources")
		int GetMaxStone();

	UFUNCTION(BlueprintPure, Category = "Resources")
		int GetPeople();
	UFUNCTION(BlueprintCallable, Category = "Resources")
		void SetPeople(int Amount);
	UFUNCTION(BlueprintCallable, Category = "Resources")
		void GainPeople(int Amount);
	UFUNCTION(BlueprintCallable, Category = "Resources")
		void LosePeople(int Amount);
	UFUNCTION(BlueprintPure, Category = "Resources")
		int GetMaxPeople();

	UFUNCTION(BlueprintPure, Category = "Resources")
		int GetZombies();
	UFUNCTION(BlueprintCallable, Category = "Resources")
		void SetZombies(int Amount);
	UFUNCTION(BlueprintCallable, Category = "Resources")
		void GainZombies(int Amount);
	UFUNCTION(BlueprintCallable, Category = "Resources")
		void LoseZombies(int Amount);

private:

	// Resources
	int Food;
	int Wood;
	int Stone;
	int People;
	int Zombies;

	float FoodProduction;
	float WoodProduction;
	float StoneProduction;

};
