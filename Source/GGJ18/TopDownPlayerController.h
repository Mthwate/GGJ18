// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TopDownPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GGJ18_API ATopDownPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:
	ATopDownPlayerController();

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	// Sets Up the Input Component
	void SetupInputComponent();

	/** Input handlers for SetDestination action. */
	UFUNCTION(BlueprintImplementableEvent, Category = "Movement")
		void OnSetDestinationPressed();
	
	
};
