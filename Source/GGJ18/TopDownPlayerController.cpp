// Fill out your copyright notice in the Description page of Project Settings.

#include "TopDownPlayerController.h"
#include "AI/Navigation/NavigationSystem.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"

ATopDownPlayerController::ATopDownPlayerController() {
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void ATopDownPlayerController::SetupInputComponent() {
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &ATopDownPlayerController::OnSetDestinationPressed);

}