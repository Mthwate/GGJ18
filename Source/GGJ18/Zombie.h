// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/AIModule/Classes/Perception/PawnSensingComponent.h"
#include "Zombie.generated.h"

UCLASS()
class GGJ18_API AZombie : public ACharacter {
	GENERATED_BODY()

	/** Initializes the Pawn Sensing Component for the Zombie */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn Sensing", meta = (AllowPrivateAccess = "true"))
		UPawnSensingComponent* PawnSensing;

public:
	// Sets default values for this character's properties
	AZombie();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
