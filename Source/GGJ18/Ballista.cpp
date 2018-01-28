// Fill out your copyright notice in the Description page of Project Settings.

#include "Ballista.h"

ABallista::ABallista() {
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AttackTick = 0.0f;

	// Initialize the Components
	DetectionRadius = CreateDefaultSubobject<USphereComponent>(TEXT("AttackingRadius"));
	DetectionRadius->SetupAttachment(RootComponent);
}

// Called every frame
void ABallista::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	AttackTick += DeltaTime;
	TSet<AActor*> OverlappedActors;
	DetectionRadius->GetOverlappingActors(OverlappedActors);
	if (AttackTick > 0.5f) {
		AttackTick = 0.f;
		for (AActor* Actor : OverlappedActors) {
			if (Actor->IsA(AZombie::StaticClass())) {
				AZombie* Zombie = Cast<AZombie>(Actor);
				PlayExplosionEffect(Zombie);
				Zombie->LoseHealth(10);
				if (Zombie->GetHealth() == 0) {
					Zombie->Destroy();
				}
			}
		}
	}
}