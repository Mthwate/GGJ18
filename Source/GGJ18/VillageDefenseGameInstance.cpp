// Fill out your copyright notice in the Description page of Project Settings.

#include "VillageDefenseGameInstance.h"

///////////////////////////////////////////////////////////
// Constants


//////////////////////////////////////////////////////////
// Getters and Setters

int UVillageDefenseGameInstance::GetFood() {
	return Food;
}

void UVillageDefenseGameInstance::SetFood(int Amount) {
	Food = FMath::Clamp(Amount, 0, Amount); // Stub
											// Change Max Amount
}

void UVillageDefenseGameInstance::AddFood(int Amount) {
	SetFood(Food + Amount);
}

void UVillageDefenseGameInstance::LoseFood(int Amount) {
	SetFood(Food - Amount);
}

int UVillageDefenseGameInstance::GetWood() {
	return Wood;
}

void UVillageDefenseGameInstance::SetWood(int Amount) {
	Wood = FMath::Clamp(Amount, 0, Amount); // Stub
										   // Change Max Amount
}

void UVillageDefenseGameInstance::AddWood(int Amount) {
	SetFood(Wood + Amount);
}

void UVillageDefenseGameInstance::LoseWood(int Amount) {
	SetFood(Wood - Amount);
}

int UVillageDefenseGameInstance::GetStone() {
	return Stone;
}

void UVillageDefenseGameInstance::SetStone(int Amount) {
	Stone = FMath::Clamp(Amount, 0, Amount); // Stub
										    // Change Max Amount
}

void UVillageDefenseGameInstance::AddStone(int Amount) {
	SetFood(Stone + Amount);
}

void UVillageDefenseGameInstance::LoseStone(int Amount) {
	SetFood(Stone - Amount);
}