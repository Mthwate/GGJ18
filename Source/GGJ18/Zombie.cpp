// Fill out your copyright notice in the Description page of Project Settings.

#include "Zombie.h"


// Sets default values
AZombie::AZombie() {
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialize the Components
	PawnSensing = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Senses"));

	DetectionRadius = CreateDefaultSubobject<USphereComponent>(TEXT("AttackingRadius"));
	DetectionRadius->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AZombie::BeginPlay() {
	Super::BeginPlay();
	ReshuffleBuildings();
}

// Called every frame
void AZombie::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	AttackTick += DeltaTime;
	TSet<AActor*> OverlappedActors;
	DetectionRadius->GetOverlappingActors(OverlappedActors);
	if (OverlappedActors.Contains(GetNearestBuilding())) {
		if (AttackTick > 0.5f) {
			AttackTick = 0.f;
			GetNearestBuilding()->LoseHealth(10);
			if (GetNearestBuilding()->GetCurrentHealth() == 0) {
				GetNearestBuilding()->Destroy();
				ReshuffleBuildings();
				TArray<AActor*> FoundActors;
				UGameplayStatics::GetAllActorsOfClass(GetWorld(), AZombie::StaticClass(), FoundActors);
				for (AActor* Actor : FoundActors) {
					if (Actor == this) {
						continue;
					}
					Cast<AZombie>(Actor)->ReshuffleBuildings();
				}
			}
		}
	} else if (GetNearestBuilding() == NULL) {
		ReshuffleBuildings();
	}

}

// Called to bind functionality to input
void AZombie::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Approach a Building
void AZombie::ApproachBuilding(ABuilding* Building) {
	AAIController* Controller = Cast<AAIController>(GetController());
	Controller->MoveToActor(Building);
}

// Accept the Buildings Array and Pick one to Destroy
void AZombie::FindBuildings(TArray<ABuilding*> Buildings) {
	this->Buildings = Buildings;
	ParseBuildingDistance();
}

void AZombie::ParseBuildingDistance() {
	FVector CurrentLocation = GetActorLocation();
	this->Buildings.Sort([&](const ABuilding& LHS, const ABuilding& RHS) {
		float LHSDist = FVector::Dist(LHS.GetActorLocation(), CurrentLocation);
		float RHSDist = FVector::Dist(RHS.GetActorLocation(), CurrentLocation);
		return LHSDist < RHSDist;
	});
}

ABuilding* AZombie::GetNearestBuilding() {
	if (Buildings.Num() > 0) {
		return Buildings[0];
	} else {
		return NULL;
	}
}