// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Building.h"
#include "Zombie.h"
#include "Runtime/Engine/Classes/Sound/SoundCue.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystem.h"
#include "Ballista.generated.h"

/**
 * 
 */
UCLASS()
class GGJ18_API ABallista : public ABuilding {
	GENERATED_BODY()
	
	/** Component that gets the zombies in a radius */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Detection", meta = (AllowPrivateAccess = "true"))
		USphereComponent* DetectionRadius;

public:
	ABallista();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Explosion")
		void PlayExplosionEffect(AZombie* Zombie);

private:

	float AttackTick;
	
	
};
