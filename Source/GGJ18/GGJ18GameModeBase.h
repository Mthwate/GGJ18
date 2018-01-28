// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ResourceStore.h"
#include "GGJ18GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class GGJ18_API AGGJ18GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category = "Resources")
		UResourceStore* GetResourceStore();

protected:

	// The Resource Store HUD that is used to add resources to the game
	UPROPERTY(BlueprintReadWrite, Category = "Resources")
		UResourceStore* ResourceStore;
	
	
};
