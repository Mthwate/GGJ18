// Fill out your copyright notice in the Description page of Project Settings.

#include "Building.h"


// Sets default values
ABuilding::ABuilding() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set Default Values of Members
	CurrentHealth = MaxHealth = 100;
	Width = 1;
	Height = 1;
	FoodCost = 0;
	WoodCost = 0;
	StoneCost = 0;

}

// Called when the game starts or when spawned
void ABuilding::BeginPlay() {
	Super::BeginPlay();
	
	// Set Current Health of Max Health
	CurrentHealth = MaxHealth;
}

//////////////////////////////////////////////////////////
// Getters and Setters

int ABuilding::GetCurrentHealth() {
	return CurrentHealth;
}

int ABuilding::GetMaximumHealth() {
	return MaxHealth;
}

float ABuilding::GetHealthRate() {
	return (CurrentHealth * 1.f) / MaxHealth;
}

void ABuilding::SetHealth(int Amount) {
	CurrentHealth = FMath::Clamp(Amount, 0, MaxHealth);
}

void ABuilding::GainHealth(int Amount) {
	SetHealth(CurrentHealth + Amount);
}

void ABuilding::LoseHealth(int Amount) {
	SetHealth(CurrentHealth - Amount);
}

int ABuilding::GetWidth() {
	return Width;
}

int ABuilding::GetHeight() {
	return Height;
}

int ABuilding::GetFoodCost() {
	return FoodCost;
}

int ABuilding::GetWoodCost() {
	return WoodCost;
}

int ABuilding::GetStoneCost() {
	return StoneCost;
}