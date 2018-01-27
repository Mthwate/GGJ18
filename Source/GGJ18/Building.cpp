// Fill out your copyright notice in the Description page of Project Settings.

#include "Building.h"


// Sets default values
ABuilding::ABuilding() {
	// Set Default Values of Members
	CurrentHealth = MaxHealth = 100;
	Width = 1;
	Height = 1;

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