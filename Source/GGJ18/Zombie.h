// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/AIModule/Classes/Perception/PawnSensingComponent.h"
#include "Building.h"
#include "House.h"
#include "GGJ18GameModeBase.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Zombie.generated.h"

UCLASS()
class GGJ18_API AZombie : public ACharacter {
	GENERATED_BODY()

	/** Initializes the Pawn Sensing Component for the Zombie */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Detection", meta = (AllowPrivateAccess = "true"))
		UPawnSensingComponent* PawnSensing;

	/** Component that gets the buildings in a radius */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Detection", meta = (AllowPrivateAccess = "true"))
		USphereComponent* DetectionRadius;

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

	UFUNCTION(BlueprintCallable, Category = Movement)
		void ApproachBuilding(ABuilding* Building);

	UFUNCTION(BlueprintCallable, Category = Movement)
		void FindBuildings(TArray<ABuilding*> Buildings);

	UFUNCTION(BlueprintImplementableEvent)
		void ReshuffleBuildings();

	void ParseBuildingDistance();

	UFUNCTION(BlueprintPure, Category = Movement)
		ABuilding* GetNearestBuilding();

	UFUNCTION(BlueprintPure, Category = "Health")
		int GetHealth();
	UFUNCTION(BlueprintCallable, Category = "Health")
		void SetHealth(int Amount);
	UFUNCTION(BlueprintCallable, Category = "Health")
		void GainHealth(int Amount);
	UFUNCTION(BlueprintCallable, Category = "Health")
		void LoseHealth(int Amount);

private:

	// An ordered list of all buildings in order of distance from the zombie
	TArray<ABuilding*> Buildings;

	UPROPERTY(EditDefaultsOnly, Category = "Health")
		int Health;

	float AttackTick;
	
	
};
