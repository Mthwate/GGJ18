// Fill out your copyright notice in the Description page of Project Settings.

#include "ResourceStore.h"


UResourceStore::UResourceStore(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
	Food = 0;
	Wood = 0;
	Stone = 0;
	People = 0;

	FoodProduction = 0.0f;
	WoodProduction = 0.0f;
	StoneProduction = 0.0f;
}

void UResourceStore::NativeTick(const FGeometry& MyGeometry, float InDeltaTime) {
	Super::Tick(MyGeometry, InDeltaTime);

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFarm::StaticClass(), FoundActors);
	for (AActor* Actor : FoundActors) {
		FoodProduction += Cast<AFarm>(Actor)->GetProductionRate() * InDeltaTime;
	}
	if (FoodProduction > 1.0f) {
		int Prod = FMath::FloorToInt(FoodProduction);
		FoodProduction -= Prod;
		GainFood(Prod);
	}
}

// FOOD

int UResourceStore::GetFood() {
	return FMath::Clamp(Food, 0, GetMaxFood());
}

void UResourceStore::SetFood(int Amount) {
	Food = FMath::Clamp(Amount, 0, GetMaxFood());
}

void UResourceStore::GainFood(int Amount) {
	SetFood(Food + Amount);
}

void UResourceStore::LoseFood(int Amount) {
	GainFood(-Amount);
}

int UResourceStore::GetMaxFood() {
	int Capacity = 0;
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AStorehouse::StaticClass(), FoundActors);
	for (AActor* Actor : FoundActors) {
		Capacity += Cast<AStorehouse>(Actor)->GetFoodCapacity();
	}
	return Capacity;
}

// WOOD

int UResourceStore::GetWood() {
	return FMath::Clamp(Wood, 0, GetMaxWood());
}

void UResourceStore::SetWood(int Amount) {
	Wood = FMath::Clamp(Amount, 0, GetMaxWood());
}

void UResourceStore::GainWood(int Amount) {
	SetWood(Wood + Amount);
}

void UResourceStore::LoseWood(int Amount) {
	GainWood(-Amount);
}

int UResourceStore::GetMaxWood() {
	int Capacity = 0;
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AStorehouse::StaticClass(), FoundActors);
	for (AActor* Actor : FoundActors) {
		Capacity += Cast<AStorehouse>(Actor)->GetWoodCapacity();
	}
	return Capacity;
}

// STONE

int UResourceStore::GetStone() {
	return FMath::Clamp(Stone, 0, GetMaxStone());
}

void UResourceStore::SetStone(int Amount) {
	Stone = FMath::Clamp(Amount, 0, GetMaxStone());
}

void UResourceStore::GainStone(int Amount) {
	SetStone(Stone + Amount);
}

void UResourceStore::LoseStone(int Amount) {
	GainStone(-Amount);
}

int UResourceStore::GetMaxStone() {
	int Capacity = 0;
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AStorehouse::StaticClass(), FoundActors);
	for (AActor* Actor : FoundActors) {
		Capacity += Cast<AStorehouse>(Actor)->GetStoneCapacity();
	}
	return Capacity;
}

// PEOPLE

int UResourceStore::GetPeople() {
	return FMath::Clamp(People, 0, GetMaxPeople());
}

void UResourceStore::SetPeople(int Amount) {
	People = FMath::Clamp(Amount, 0, GetMaxPeople());
}

void UResourceStore::GainPeople(int Amount) {
	SetPeople(People + Amount);
}

void UResourceStore::LosePeople(int Amount) {
	GainPeople(-Amount);
}


int UResourceStore::GetMaxPeople() {
	int Capacity = 0;
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AHouse::StaticClass(), FoundActors);
	for (AActor* Actor : FoundActors) {
		Capacity += Cast<AHouse>(Actor)->GetResidenceCapacity();
	}
	return Capacity;
}