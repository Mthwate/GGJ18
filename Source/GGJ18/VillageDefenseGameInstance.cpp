// Fill out your copyright notice in the Description page of Project Settings.

#include "VillageDefenseGameInstance.h"


///////////////////////////////////////////////////////////
// Object Initialization

void UVillageDefenseGameInstance::Init() {

	
	// cost { food, wood, stone }
	BuildingCosts.house = {
		{ 1, 1, 0 },
		{ 2, 2, 0 },
	};

	BuildingCosts.farm = {
		{ 0, 1, 1 },
		{ 0, 2, 2 },
	};

}


//////////////////////////////////////////////////////////
// Getters and Setters

int UVillageDefenseGameInstance::GetFood() {
	return Food;
}

void UVillageDefenseGameInstance::SetFood(int Amount) {
	Food = FMath::Clamp(Amount, 0, GetMaxFood());
}

void UVillageDefenseGameInstance::AddFood(int Amount) {
	SetFood(Food + Amount);
}

void UVillageDefenseGameInstance::LoseFood(int Amount) {
	SetFood(Food - Amount);
}

int UVillageDefenseGameInstance::GetMaxFood() {
	return 9999; // Stub!
}

int UVillageDefenseGameInstance::GetWood() {
	return Wood;
}

void UVillageDefenseGameInstance::SetWood(int Amount) {
	Wood = FMath::Clamp(Amount, 0, GetMaxWood());
}

void UVillageDefenseGameInstance::AddWood(int Amount) {
	SetWood(Wood + Amount);
}

void UVillageDefenseGameInstance::LoseWood(int Amount) {
	SetWood(Wood - Amount);
}

int UVillageDefenseGameInstance::GetMaxWood() {
	return 9999; // Stub!
}

int UVillageDefenseGameInstance::GetStone() {
	return Stone;
}

void UVillageDefenseGameInstance::SetStone(int Amount) {
	Stone = FMath::Clamp(Amount, 0, GetMaxStone());
}

void UVillageDefenseGameInstance::AddStone(int Amount) {
	SetStone(Stone + Amount);
}

void UVillageDefenseGameInstance::LoseStone(int Amount) {
	SetStone(Stone - Amount);
}

int UVillageDefenseGameInstance::GetMaxStone() {
	return 9999; // Stub!
}

int UVillageDefenseGameInstance::GetPeople() {
	return People;
}

void UVillageDefenseGameInstance::SetPeople(int Amount) {
	People = FMath::Clamp(Amount, 0, GetMaxPeople());
}

void UVillageDefenseGameInstance::AddPeople(int Amount) {
	SetPeople(People + Amount);
}

void UVillageDefenseGameInstance::LosePeople(int Amount) {
	SetPeople(People - Amount);
}

int UVillageDefenseGameInstance::GetMaxPeople() {
	return 999; // Stub!
}

FBuildingCosts UVillageDefenseGameInstance::GetBuildingCosts() {
	return BuildingCosts;
}